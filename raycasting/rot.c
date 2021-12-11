/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:56:33 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rot_right(t_data *data)
{
	data->old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->step.rot_speed)
		- data->dir_y * sin(-data->step.rot_speed);
	data->dir_y = data->old_dir_x * sin(-data->step.rot_speed)
		+ data->dir_y * cos(-data->step.rot_speed);
	data->old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-data->step.rot_speed)
		- data->plane_y * sin(-data->step.rot_speed);
	data->plane_y = data->old_plane_x * sin(-data->step.rot_speed)
		+ data->plane_y * cos(-data->step.rot_speed);
}

void	ft_rot_left(t_data *data)
{
	data->old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(data->step.rot_speed)
		- data->dir_y * sin(data->step.rot_speed);
	data->dir_y = data->old_dir_x * sin(data->step.rot_speed)
		+ data->dir_y * cos(data->step.rot_speed);
	data->old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(data->step.rot_speed)
		- data->plane_y * sin(data->step.rot_speed);
	data->plane_y = data->old_plane_x * sin(data->step.rot_speed)
		+ data->plane_y * cos(data->step.rot_speed);
}
