/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:33:13 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_data.h"

void	ft_identifier(char *str, t_maps_data *scene)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	if ((ft_strncmp(tmp[0], "R", 1) == 0))
		ft_id_r(tmp, str, scene);
	else if ((ft_strncmp(tmp[0], "NO", 2) == 0))
		ft_id_no(tmp, str, scene);
	else if ((ft_strncmp(tmp[0], "SO", 2) == 0))
		ft_id_so(tmp, str, scene);
	else if ((ft_strncmp(tmp[0], "WE", 2) == 0))
		ft_id_we(tmp, str, scene);
	else if ((ft_strncmp(tmp[0], "EA", 2) == 0))
		ft_id_ea(tmp, str, scene);
	else if ((ft_strncmp(tmp[0], "S", 1) == 0))
		ft_id_s(tmp, str, scene);
	else if ((ft_strncmp(tmp[0], "F", 1) == 0))
		ft_id_f(tmp, str, scene);
	else if ((ft_strncmp(tmp[0], "C", 1) == 0))
		ft_id_c(tmp, str, scene);
	else
		ft_error_msg("Unknown Identifier");
	ft_free_array_strings(tmp);
}

void	ft_id_r(char **tmp, char *str, t_maps_data *scene)
{
	if (str[1] == ' ' && tmp[1] != NULL && tmp[2] != NULL && tmp[3] == NULL
		&& scene->screen_width == -1 && scene->screen_height == -1)
	{
		scene->screen_width = ft_atoi(tmp[1]);
		scene->screen_height = ft_atoi(tmp[2]);
		if (scene->screen_width < 0 ||scene->screen_height < 0)
			ft_error_msg("Resolution too small");
	}
	else
		ft_error_msg("Resolution format wrong");
}

void	ft_id_no(char **tmp, char *str, t_maps_data *scene)
{
	if (str[2] == ' ' && tmp[1] != NULL && tmp[2] == NULL
		&& scene->no_tex == NULL)
		scene->no_tex = ft_strdup(tmp[1]);
	else
		ft_error_msg("North Texture format wrong");
}

void	ft_id_so(char **tmp, char *str, t_maps_data *scene)
{
	if (str[2] == ' ' && tmp[1] != NULL && tmp[2] == NULL
		&& scene->so_tex == NULL)
		scene->so_tex = ft_strdup(tmp[1]);
	else
		ft_error_msg("South Texture format wrong");
}

void	player_pos(char *str, int *row, int col, t_maps_data *scene)
{
	scene->world_map[*row][col] = 0;
	scene->start_row = *row;
	scene->start_col = col;
	scene->start_dir = str[col];
}
