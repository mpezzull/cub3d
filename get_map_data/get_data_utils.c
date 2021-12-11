/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 01:29:51 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_data.h"

void	ft_error_msg(char *msg)
{
	printf("Error\n\t%s\n", msg);
	exit(0);
}

int	ft_allocate_matrix(t_maps_data *scene)
{
	int	row;

	row = 0;
	scene-> world_map = (int **)malloc((scene->row_max +1) * sizeof(int *));
	if (!(scene->world_map))
		return (-1);
	while (row <=scene->row_max)
	{
		scene->world_map[row] = (int *)malloc((scene->col_max + 1)
				* sizeof(int *));
		if (!(scene->world_map[row++]))
			return (-1);
	}
	return (0);
}

void	ft_free_array_strings(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i++] = NULL;
	}
	free(tmp);
	tmp = NULL;
}

void	ft_free_scene_struct(t_data *data)
{
	int	row;

	row = 0;
	while (row <= data->scene.row_max)
		free(data->scene.world_map[row++]);
	free(data->scene.world_map);
	free(data->scene.no_tex);
	free(data->scene.so_tex);
	free(data->scene.we_tex);
	free(data->scene.ea_tex);
	free(data->scene.s_tex);
}
