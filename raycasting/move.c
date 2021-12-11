/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:02:21 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_up(t_data *data)
{
	if (data->scene.world_map[(int)(data->pos_x
			+ data->dir_x * data->step.move_speed)]
	[(int)(data->pos_y)] == 0)
	{
		data->pos_x += data->dir_x * data->step.move_speed;
	}
	if (data->scene.world_map[(int)(data->pos_x)]
	[(int)(data->pos_y + data->dir_y * data->step.move_speed)] == 0)
	{
		data->pos_y += data->dir_y * data->step.move_speed;
	}
}

void	ft_move_down(t_data *data)
{
	if (data->scene.world_map[(int)(data->pos_x - data->dir_x
			* data->step.move_speed)]
	[(int)(data->pos_y)] == 0)
	{
		data->pos_x -= data->dir_x * data->step.move_speed;
	}
	if (data->scene.world_map[(int)(data->pos_x)]
	[(int)(data->pos_y - data->dir_y * data->step.move_speed)] == 0)
	{
		data->pos_y -= data->dir_y * data->step.move_speed;
	}
}

void	ft_move_left(t_data *data)
{
	if (data->scene.world_map[(int)(data->pos_x + data->dir_y
			* data->step.move_speed)]
	[(int)(data->pos_y)] == 0)
	{
		data->pos_x += data->dir_y * data->step.move_speed;
	}
	if (data->scene.world_map[(int)(data->pos_x)]
	[(int)(data->pos_y - data->dir_x * data->step.move_speed)] == 0)
	{
		data->pos_y -= data->dir_x * data->step.move_speed;
	}
}

void	ft_move_right(t_data *data)
{
	if (data->scene.world_map[(int)(data->pos_x - data->dir_y
			* data->step.move_speed)]
	[(int)(data->pos_y)] == 0)
	{
		data->pos_x -= data->dir_y * data->step.move_speed;
	}
	if (data->scene.world_map[(int)(data->pos_x)]
	[(int)(data->pos_y + data->dir_x * data->step.move_speed)] == 0)
	{
		data->pos_y += data->dir_x * data->step.move_speed;
	}
}

void	ft_move(t_data *data)
{
	if (data->key_pressed[4])
		ft_move_right(data);
	if (data->key_pressed[5])
		ft_move_left(data);
	if (data->key_pressed[3])
		  ft_move_up(data);
	if (data->key_pressed[2])
		ft_move_down(data);
	if (data->key_pressed[1])
		ft_rot_right(data);
	if (data->key_pressed[0])
		ft_rot_left(data);
}
