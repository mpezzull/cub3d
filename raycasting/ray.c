/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:12:09 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_ray(t_data *data)
{
	if (data->draw.ray_dir_x < 0)
	{
		data->step.step_x = -1;
		data->draw.side_dist_x = (data->pos_x - data->draw.map_x)
			* data->draw.delta_dist_x;
	}
	else
	{
		data->step.step_x = 1;
		data->draw.side_dist_x = (data->draw.map_x + 1.0 - data->pos_x)
			* data->draw.delta_dist_x;
	}
	if (data->draw.ray_dir_y < 0)
	{
		data->step.step_y = -1;
		data->draw.side_dist_y = (data->pos_y - data->draw.map_y)
			* data->draw.delta_dist_y;
	}
	else
	{
		data->step.step_y = 1;
		data->draw.side_dist_y = (data->draw.map_y + 1.0 - data->pos_y)
			* data->draw.delta_dist_y;
	}
}
