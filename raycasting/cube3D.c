/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:07:39 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_step_hit(t_data *data)
{
	if (data->draw.side_dist_x < data->draw.side_dist_y)
	{
		data->draw.side_dist_x += data->draw.delta_dist_x;
		data->draw.map_x += data->step.step_x;
		data->step.side = 0;
	}
	else
	{
		data->draw.side_dist_y += data->draw.delta_dist_y;
		data->draw.map_y += data->step.step_y;
		data->step.side = 1;
	}
	if (data->scene.world_map[(int)data->draw.map_x][(int)data->draw.map_y]
			== 1)
		data->step.hit = 1;
}

int	ft_render_frame(t_data *data)
{
	ft_init(data);
	ft_init_start(data);
	ft_move(data);
	while (data->x < data->scene.screen_width)
	{
		ft_init(data);
		ft_init_draw(data);
		ft_ray(data);
		while (data->step.hit == 0)
			ft_step_hit(data);
		ft_wall_dist(data);
		data->x++;
	}
	ft_draw_sprites(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

int	init(t_data *data)
{
	int		i;

	i = 0;
	data->pos_x = data->scene.start_row +0.5;
	data->pos_y = data->scene.start_col +0.5;
	check_pos_screen(data);
	start_position1(data);
	data->z_buffer = (double *)malloc(sizeof(double)
			* data->scene.screen_width);
	if (!(data ->z_buffer))
		return (-1);
	while (i < data->scene.screen_width)
	{
		data->z_buffer[i] = 0;
		i++;
	}	
	return (0);
}

void	start_position1(t_data *data)
{
	if (data->scene.start_dir == 'E')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (data->scene.start_dir == 'W')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	start_position2(data);
}

void	start_position2(t_data *data)
{
	if (data->scene.start_dir == 'N')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	else if (data->scene.start_dir == 'S')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
}
