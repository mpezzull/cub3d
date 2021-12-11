/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 01:37:17 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_data.h"

void	read_file(char *str, int *row, t_maps_data *scene)
{
	int	col;

	if (ft_strlen(str) > 0)
	{
		if (str[0] == '1' || str[0] == ' ')
		{
			ft_maps_is_last(scene);
			col = (int)ft_strlen(str) - 1;
			if (col >scene->col_max)
				scene->col_max = col;
			if (*row >scene->row_max)
				scene->row_max = *row;
			(*row)++;
		}
		else
			ft_identifier(str, scene);
	}
	if (ft_strlen(str) == 0 && *row != 0)
		ft_error_msg("There is an empty row inside the map");
	free(str);
	str = NULL;
}

int	ft_maps_is_last(t_maps_data *scene)
{
	if (scene->screen_height < 0 || scene->screen_width < 0
		|| scene->no_tex == NULL
		|| scene->so_tex == NULL
		|| scene-> we_tex == NULL
		|| scene->ea_tex == NULL
		|| scene->s_tex == NULL
		|| scene-> floor_red < 0 || scene->floor_blue < 0
		|| scene-> floor_green < 0 ||scene->ceiling_red < 0
		|| scene-> ceiling_green < 0 || scene->ceiling_blue < 0)
		ft_error_msg("Missing parameter before the map");
	return (0);
}

void	fill_seven_world_map(t_maps_data *scene)
{
	int	row;
	int	col;

	row = 0;
	while (row <=scene->row_max)
	{
		col = 0;
		while (col <=scene->col_max)
		{
			scene->world_map[row][col] = 7;
			col++;
		}
		row++;
	}
}

void	create_world_map(char *str, int *row, t_maps_data *scene)
{
	int	col;

	if (ft_strlen(str) > 0 && (str[0] == '1' || str[0] == ' '))
	{
		col = 0;
		while (str[col])
		{
			if (str[col] == ' ')
				scene->world_map[*row][col] = 7;
			else if (str[col] == '1' || str[col] == '2' || str[col] == '0')
			{
				scene->world_map[*row][col] = str[col] - 48;
				if (str[col] == '2')
					scene->num_sprite++;
			}
			else if ((str[col] == 'N' || str[col] == 'S' || str[col] == 'W'
					|| str[col] == 'E') && scene->start_row == -1
				&& scene->start_col == -1)
				player_pos(str, row, col, scene);
			else
				ft_error_msg("There is an error in the map");
			col++;
		}
		(*row)++;
	}
}
