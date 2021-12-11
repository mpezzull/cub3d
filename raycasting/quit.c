/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:12:07 by aperuzzo          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_quit(int button, t_data *data)
{
	button = data->scene.screen_height;
	exit(0);
	return (0);
}

void	ft_esc(t_data *data)
{
	int	k;

	k = 0;
	ft_free_scene_struct(data);
	while (k < 5)
		mlx_destroy_image(data->mlx, data->texture[k++].img);
	free(data->sprite);
	free(data->z_buffer);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}
