/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:32:43 by mpezzull          #+#    #+#             */
/*   Updated: 2021/04/26 15:32:43 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_data.h"

t_maps_data	initmapdata(void)
{
	t_maps_data		scene;

	scene.screen_width = -1;
	scene.screen_height = -1;
	scene.no_tex = NULL;
	scene.so_tex = NULL;
	scene.we_tex = NULL;
	scene.ea_tex = NULL;
	scene.s_tex = NULL;
	scene.floor_red = -1;
	scene.floor_green = -1;
	scene.floor_blue = -1;
	scene.ceiling_red = -1;
	scene.ceiling_green = -1;
	scene.ceiling_blue = -1;
	scene.row_max = -1;
	scene.col_max = -1;
	scene.start_row = -1;
	scene.start_col = -1;
	scene.start_dir = ' ';
	scene.num_sprite = 0;
	return (scene);
}

void	get_data(char *file, t_maps_data *scene)
{
	char	*str;
	int		fd;
	int		row;

	row = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error_msg(strerror(errno));
	while (get_next_line(fd, &str) != 0)
		read_file(str, &row, scene);
	read_file(str, &row, scene);
	close(fd);
	ft_allocate_matrix(scene);
	fd = open(file, O_RDONLY);
	fill_seven_world_map(scene);
	row = 0;
	while (row <=scene->row_max)
	{
		get_next_line(fd, &str);
		create_world_map(str, &row, scene);
		free(str);
	}
	ft_check(scene);
	close(fd);
}

void	ft_check(t_maps_data *scene)
{
	check_row(scene);
	check_col(scene);
	if (scene->start_row == -1 || scene->start_col == -1)
		ft_error_msg("The player's starting position is missing");
}
