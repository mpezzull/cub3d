/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:29:56 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_spr_tmp3(t_spr_temp *tmp, t_data *data, int t_i)
{
	if ((data->texture[4].img_addr[t_i] != (char)0x00)
		|| data->texture[4].img_addr[t_i + 1] != (char)0x00
		|| data->texture[4].img_addr[t_i + 2] != (char)0x00)
	{
		data->addr[4 * (tmp->x + data->scene.screen_width * tmp->y)]
			= data->texture[4].img_addr[t_i];
		data->addr[4 * (tmp->x + data->scene.screen_width * tmp->y)
			+ 1] = data->texture[4].img_addr[t_i + 1];
		data->addr[4 * (tmp->x + data->scene.screen_width * tmp->y)
			+ 2] = data->texture[4].img_addr[t_i + 2];
	}
}

void	ft_tex_used(t_data *data)
{
	data->tex_used = 0;
	if (data->draw.map_y <= data->pos_y && data->tex_used < 4)
	{
		if (data->step.side == 0 && data->draw.map_x < data->pos_x)
			data->tex_used = 1;
		else if (data->step.side == 0 && data->draw.map_x >= data->pos_x)
			data->tex_used = 2;
		else if (data->step.side == 1)
			data->tex_used = 3;
	}
	if (data->draw.map_y >= data->pos_y && data->tex_used < 4)
	{
		if (data->step.side == 0 && data->draw.map_x < data->pos_x)
			data->tex_used = 1;
		else if (data->step.side == 0 && data->draw.map_x >= data->pos_x)
			data->tex_used = 2;
		else if (data->step.side == 1)
			data->tex_used = 0;
	}
}
