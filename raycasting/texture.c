/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:59:04 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_texture(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx, data->scene.ea_tex,
			&data->texture[0].width, &data->texture[0].height);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx, data->scene.no_tex,
			&data->texture[1].width, &data->texture[1].height);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx, data->scene.so_tex,
			&data->texture[2].width, &data->texture[2].height);
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx, data->scene.we_tex,
			&data->texture[3].width, &data->texture[3].height);
	data->texture[4].img = mlx_xpm_file_to_image(data->mlx, data->scene.s_tex,
			&data->texture[4].width, &data->texture[4].height);
	if (ft_check_tex(data, 1) == -1)
		return (-1);
	data->texture[0].img_addr = mlx_get_data_addr(data->texture[0].img,
			&data->bits_per_pixel, &data->size_l, &data->endian);
	data->texture[1].img_addr = mlx_get_data_addr(data->texture[1].img,
			&data->bits_per_pixel, &data->size_l, &data->endian);
	data->texture[2].img_addr = mlx_get_data_addr(data->texture[2].img,
			&data->bits_per_pixel, &data->size_l, &data->endian);
	data->texture[3].img_addr = mlx_get_data_addr(data->texture[3].img,
			&data->bits_per_pixel, &data->size_l, &data->endian);
	data->texture[4].img_addr = mlx_get_data_addr(data->texture[4].img,
			&data->bits_per_pixel, &data->size_l, &data->endian);
	if (ft_check_tex(data, 2) == -1)
		return (-1);
	return (0);
}

int	ft_check_tex(t_data *data, int n_check)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (!data->texture[i].img && n_check == 1)
			return (-1);
		if (!data->texture[i++].img_addr && n_check == 2)
			return (-1);
	}
	return (0);
}

void	ft_draw(t_data *data)
{
	int	screen_width;

	screen_width = data->scene.screen_width;
	ft_tex_used(data);
	ft_draw_sf(data);
	data->y = data->draw.draw_start;
	while (data->y < data->draw.draw_end)
	{
		data->tex_y = (int)data->tex_pos
			& (data->texture[data->tex_used].height - 1);
		data->tex_pos += data->step.step;
		data->addr[data->x * 4 + (4 * screen_width * (data->y))]
			= (int)(data->texture[data->tex_used].img_addr[data->tex_x
				* 4 + 4 * data->texture[data->tex_used].width
				* data->tex_y]);
		data->addr[data->x * 4 + (4 * screen_width * (data->y)) + 1]
			= (int)(data->texture[data->tex_used].img_addr[data->tex_x
				* 4 + 4 * data->texture[data->tex_used].width
				* data->tex_y + 1]);
		data->addr[data->x * 4 + (4 * screen_width * (data->y)) + 2]
			= (int)(data->texture[data->tex_used].img_addr[data->tex_x
				* 4 + 4 * data->texture[data->tex_used].width
				* data->tex_y + 2]);
		data->y++;
	}
}

void	ft_tex(t_data *data)
{
	data->tex_x = (int)(data->wall_x
			* (double)data->texture[data->tex_used].width);
	if (data->step.side == 0 && data->draw.ray_dir_x > 0)
		data->tex_x = data->texture[data->tex_used].width - data->tex_x - 1;
	if (data->step.side == 1 && data->draw.ray_dir_y < 0)
		data->tex_x = data->texture[data->tex_used].width - data->tex_x - 1;
	data->step.step = 1.0 * data->texture[data->tex_used].height
		/ data->draw.line_height;
	data->tex_pos = (data->draw.draw_start - data->h
			/ 2 + data->draw.line_height / 2) * data->step.step;
	ft_draw(data);
}

void	ft_wall_dist(t_data *data)
{
	if (data->step.side == 0)
		data->draw.perp_wall_dist = (data->draw.map_x - data->pos_x
				+ (1 - data->step.step_x) / 2) / data->draw.ray_dir_x;
	else
		data->draw.perp_wall_dist = (data->draw.map_y - data->pos_y
				+ (1 - data->step.step_y) / 2) / data->draw.ray_dir_y;
	data->z_buffer[data->x] = data->draw.perp_wall_dist;
	data->draw.line_height = (int)(data->h / data->draw.perp_wall_dist);
	if (data->draw.line_height < 0)
		data->draw.line_height = data->h;
	data->draw.draw_start = -data->draw.line_height / 2 + data->h / 2;
	if (data->draw.draw_start < 0)
		data->draw.draw_start = 0;
	data->draw.draw_end = data->draw.line_height / 2 + data->h / 2;
	if (data->draw.draw_end >= data->h || data->draw.draw_end < 0)
		data->draw.draw_end = data->h;
	if (data->step.side == 0)
		data->wall_x = data->pos_y + data->draw.perp_wall_dist
			* data->draw.ray_dir_y;
	else
		data->wall_x = data->pos_x + data->draw.perp_wall_dist
			* data->draw.ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	ft_tex(data);
}
