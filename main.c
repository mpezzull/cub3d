/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:07:30 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting/cub3D.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc < 2 || argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save", 6)))
		ft_error_msg("try ./cub3D maps/map.cub [--save]");
	if (argv[1] && ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
		ft_error_msg("the configuration file must be file.cub");
	data.scene = initmapdata();
	get_data(argv[1], &data.scene);
	if (argv[2] && !ft_strncmp(argv[2], "--save", 6))
		ft_bmpinit(&data);
	init(&data);
	ft_init_key(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.scene.screen_width,
			data.scene.screen_height, "cub3D");
	if (ft_texture(&data) == -1)
		ft_error_msg(strerror(errno));
	ft_fill_sprite(&data);
	mlx_loop_hook(data.mlx, ft_render_frame, &data);
	mlx_hook(data.win, 02, 1L << 0, ft_keypress, &data);
	mlx_hook(data.win, 03, 1L << 1, ft_keyrelease, &data);
	mlx_hook(data.win, 17, 0, ft_quit, &data);
	mlx_loop(data.mlx);
}

int	ft_keyrelease(int keycode, t_data *data)
{
	if (keycode == LEFT_ROT)
		data->key_pressed[0] = 0;
	else if (keycode == RIGHT_ROT)
		data->key_pressed[1] = 0;
	else if (keycode == UP)
		data->key_pressed[2] = 0;
	else if (keycode == DOWN)
		data->key_pressed[3] = 0;
	else if (keycode == LEFT)
		data->key_pressed[4] = 0;
	else if (keycode == RIGHT)
		data->key_pressed[5] = 0;
	return (0);
}

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_esc(data);
	if (keycode == LEFT_ROT)
		data->key_pressed[0] = 1;
	else if (keycode == RIGHT_ROT)
		data->key_pressed[1] = 1;
	else if (keycode == UP)
		data->key_pressed[2] = 1;
	else if (keycode == DOWN)
		data->key_pressed[3] = 1;
	else if (keycode == LEFT)
		data->key_pressed[4] = 1;
	else if (keycode == RIGHT)
		data->key_pressed[5] = 1;
	return (0);
}

void	check_pos_screen(t_data *data)
{
	if (data->scene.screen_width > 2560)
		data->scene.screen_width = 2560;
	if (data->scene.screen_height > 1440)
		data->scene.screen_height = 1440;
}
