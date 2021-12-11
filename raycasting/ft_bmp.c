/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:02:54 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

void	imgbmp(t_data *data, t_bmp *bmp)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = -1;
	data->get_data = (int *)data->addr;
	while (++j < data->scene.screen_height)
	{
		i = -1;
		while (++i < data->scene.screen_width)
		{
			x = i;
			y = data->scene.screen_height - 1 - j;
			bmp->color = data->get_data[x + y * data->scene.screen_width];
			write(bmp->fd, &bmp->color, 3);
		}
		i = -1;
		while (++i < (4 - (data->scene.screen_width * 3) % 4) % 4)
			write(bmp->fd, &bmp->pad, 1);
	}
}

void	ft_header(t_data *data, t_bmp *bmp)
{
	int	i;

	i = 0;
	while (i < 14)
		bmp->header[i++] = 0;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	bmp->header[10] = 54;
	i = 0;
	while (i < 40)
		bmp->info[i++] = 0;
	bmp->info[0] = 40;
	bmp->info[12] = 1;
	bmp->info[14] = 24;
	i = 0;
	while (i < 3)
		bmp->pad[i++] = 0;
	set_header(&bmp->header[2], bmp->size);
	set_header(&bmp->info[4], data->scene.screen_width);
	set_header(&bmp->info[8], data->scene.screen_height);
	write(bmp->fd, bmp->header, 14);
	write(bmp->fd, bmp->info, 40);
}

void	ft_bmp(t_data *data)
{
	t_bmp	bmp;
	int		imgsize;

	imgsize = 3 * data->scene.screen_width * data->scene.screen_height;
	bmp.size = 54 + imgsize;
	bmp.img = malloc((sizeof(char) * imgsize));
	if (!bmp.img)
		ft_error_msg(strerror(errno));
	ft_bzero(bmp.img, imgsize);
	bmp.fd = open("img.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	ft_header(data, &bmp);
	imgbmp(data, &bmp);
	free(bmp.img);
	close(bmp.fd);
}

void	ft_bmpinit(t_data *data)
{
	init(data);
	data->mlx = mlx_init();
	ft_texture(data);
	ft_fill_sprite(data);
	start_position1(data);
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
	ft_bmp(data);
	mlx_destroy_image(data->mlx, data->img);
	exit(0);
}
