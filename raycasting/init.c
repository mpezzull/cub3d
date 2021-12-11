/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:12:19 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init(t_data *data)
{
	int	i;

	i = 0;
	data->old_plane_x = 0;
	data->old_dir_x = 0;
	data->draw.camera_x = 0;
	data->draw.ray_dir_x = 0;
	data->draw.ray_dir_y = 0;
	data->draw.map_x = 0;
	data->draw.map_y = 0;
	data->draw.side_dist_x = 0;
	data->draw.side_dist_y = 0;
	data->draw.delta_dist_x = 0;
	data->draw.delta_dist_y = 0;
	data->draw.perp_wall_dist = 0;
	data->draw.line_height = 0;
	data->draw.draw_start = 0;
	data->draw.draw_end = 0;
	data->step.step_x = 0;
	data->step.step_y = 0;
	data->step.hit = 0;
	data->step.side = 0;
	return (0);
}

void	ft_init_key(t_data *data)
{
	data->key_pressed[0] = 0;
	data->key_pressed[1] = 0;
	data->key_pressed[2] = 0;
	data->key_pressed[3] = 0;
	data->key_pressed[4] = 0;
	data->key_pressed[5] = 0;
}

void	ft_init_start(t_data *data)
{
	data->w = data->scene.screen_width;
	data->h = data->scene.screen_height;
	data->img = mlx_new_image(data->mlx, data->scene.screen_width,
			data->scene.screen_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->step.move_speed = 0.055;
	data->step.rot_speed = 0.035;
	data->x = 0;
}

void	ft_init_draw(t_data *data)
{
	data->draw.camera_x = (2 * data->x / data->w) - 1;
	data->draw.ray_dir_x = data->dir_x + data->plane_x * data->draw.camera_x;
	data->draw.ray_dir_y = data->dir_y + data->plane_y * data->draw.camera_x;
	data->draw.map_x = (int)(data->pos_x);
	data->draw.map_y = (int)(data->pos_y);
	data->draw.delta_dist_x = fabs(1 / data->draw.ray_dir_x);
	data->draw.delta_dist_y = fabs(1 / data->draw.ray_dir_y);
}
