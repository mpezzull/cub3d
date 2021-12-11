/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:08:34 by aperuzzo          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_fill_sprite(t_data *data)
{
	int	i;
	int	n_sprite;
	int	j;

	i = 0;
	n_sprite = 0;
	data->sprite = (t_sprite *)malloc(sizeof(t_sprite)
			* (data->scene.num_sprite));
	if (!(data->sprite))
		return (-1);
	while (i < data->scene.row_max + 1)
	{
		j = 0;
		while (j < data->scene.col_max + 1)
		{
			if (data->scene.world_map[i][j] == 2)
			{
				(data->sprite)[n_sprite].x = i + 0.5;
				(data->sprite)[n_sprite++].y = j + 0.5;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void 	ft_srt_sprites(int *order, double *dist, int len)
{
	int		i;
	double	temp;
	int		max;

	i = 0;
	temp = 0.0;
	max = 0;
	if (len == 1)
		return ;
	while (i < len - 1)
	{
		if (dist[i] < dist[i + 1])
		{
			temp = dist[i];
			dist[i] = dist[i + 1];
			dist[i + 1] = temp;
			temp = order[i];
			order[i] = order[i + 1];
			order[i + 1] = temp;
		}
		i++;
	}
	return (ft_srt_sprites(order, dist, len - 1));
}

void	ft_draw_sprites(t_data *data)
{
	t_spr_temp	tmp;

	tmp.i = -1;
	tmp.spr_order = (int *)malloc(sizeof(int) * data->scene.num_sprite);
	tmp.spr_dist = (double *)malloc(sizeof(double) * data->scene.num_sprite);
	if (!(tmp.spr_order) || (!(tmp.spr_dist)))
		ft_error_msg(strerror(errno));
	while (++(tmp.i) < data->scene.num_sprite)
	{
		tmp.spr_order[tmp.i] = tmp.i;
		tmp.spr_dist[tmp.i] = ((data->pos_x - data->sprite[tmp.i].x)
				* (data->pos_x - data->sprite[tmp.i].x)
				+ (data->pos_y - data->sprite[tmp.i].y)
				* (data->pos_y - data->sprite[tmp.i].y));
	}
	ft_srt_sprites(tmp.spr_order, tmp.spr_dist, data->scene.num_sprite);
	tmp.i = 0;
	while (tmp.i < data->scene.num_sprite)
	{
		ft_spr_tmp(&tmp, data);
		ft_spr_tmp2(&tmp, data);
		tmp.i++;
	}
	free(tmp.spr_order);
	free(tmp.spr_dist);
}

void	ft_spr_tmp(t_spr_temp *tmp, t_data *data)
{
	tmp->spr_x = data->sprite[tmp->spr_order[tmp->i]].x - data->pos_x;
	tmp->spr_y = data->sprite[tmp->spr_order[tmp->i]].y - data->pos_y;
	tmp->inv_det = 1.0 / (data->plane_x * data->dir_y - data->dir_x
			* data->plane_y);
	tmp->transf_x = tmp->inv_det * (data->dir_y * tmp->spr_x
			- data->dir_x * tmp->spr_y);
	tmp->transf_y = tmp->inv_det * (-data->plane_y * tmp->spr_x
			+ data->plane_x * tmp->spr_y);
	tmp->spr_scr_x = (int)((data->w / 2) * (1 + tmp->transf_x
				/ tmp->transf_y));
	tmp->spr_height = abs((int)(data->h / (tmp->transf_y)));
	tmp->draw_start_y = -tmp->spr_height / 2 + data->h / 2;
	if (tmp->draw_start_y < 0)
		tmp->draw_start_y = 0;
	tmp->draw_end_y = tmp->spr_height / 2 + data->h / 2;
	if (tmp->draw_end_y >= data->h)
		tmp->draw_end_y = data->h - 1;
	tmp->spr_width = abs((int)(data->h / (tmp->transf_y)));
	tmp->draw_start_x = -tmp->spr_width / 2 + tmp->spr_scr_x;
	if (tmp->draw_start_x < 0)
		tmp->draw_start_x = 0;
	tmp->draw_end_x = tmp->spr_width / 2 + tmp->spr_scr_x;
	if (tmp->draw_end_x >= data->w)
		tmp->draw_end_x = data->w - 1;
}

void	ft_spr_tmp2(t_spr_temp *tmp, t_data *data)
{
	int	t_i;

	tmp->x = tmp->draw_start_x;
	while (tmp->x < tmp->draw_end_x)
	{
		data->tex_x = (int)(256 *(tmp->x - (-tmp->spr_width / 2
						+ tmp->spr_scr_x)) * data->texture[4].width
				/ tmp->spr_width) / 256;
		if (tmp->transf_y > 0 && tmp->x > 0 && tmp->x < data->w
			&& tmp->transf_y < data->z_buffer[tmp->x])
		{
			tmp->y = tmp->draw_start_y;
			while (tmp->y < tmp->draw_end_y)
			{
				tmp->d = tmp->y * 256 - data->h * 128 + tmp->spr_height * 128;
				data->tex_y = ((tmp->d * data->texture[4].height)
						/ tmp->spr_height) / 256;
				t_i = 4 * (data->tex_x + data->texture[4].width * data->tex_y);
				ft_spr_tmp3(tmp, data, t_i);
				tmp->y++;
			}
		}
		tmp->x++;
	}
}
