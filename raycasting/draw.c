/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:20:38 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_sf(t_data *data)
{
	int	floor;
	int	ceiling;

	floor = create_rgb(data->scene.floor_red, data->scene.floor_green,
			data->scene.floor_blue);
	ceiling = create_rgb(data->scene.ceiling_red, data->scene.ceiling_green,
			data->scene.ceiling_blue);
	data->y = 0;
	while (data->y <= data->h / 2)
	{
		ft_mlx_pixel_put(data, data->x, data->y, ceiling);
		data->y++;
	}
	while (data->y < data->h)
	{
		ft_mlx_pixel_put(data, data->x, data->y, floor);
		data->y++;
	}
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
