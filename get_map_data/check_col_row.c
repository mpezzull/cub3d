/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:07:11 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:56 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_data.h"

void	check_col(t_maps_data *scene)
{
	int	col;
	int	row;

	col = 0;
	while (col <= scene->col_max)
	{
		row = 0;
		while (scene->world_map[row][col] != 1)
		{
			if (scene->world_map[row][col] != 7)
				ft_error_msg("There is an error in the map");
			row++;
			if (row == scene->row_max + 1)
				ft_error_msg("There is an error in the map");
		}
		while (row <= scene->row_max)
		{
			if ((scene->world_map[row][col] == 2
				|| scene->world_map[row][col] == 0)
				&& scene->world_map[row - 1][col] == 7)
				ft_error_msg("There is an error in the map");
			row++;
		}
		check_col_rev(scene, col++);
	}
}

void	check_col_rev(t_maps_data *scene, int col)
{
	int	row;

	row = scene->row_max;
	while (scene->world_map[row][col] != 1)
	{
		if (scene->world_map[row][col] != 7)
			ft_error_msg("There is an error in the map");
		row--;
		if (row == 0)
			ft_error_msg("There is an error in the map");
	}
	while (row >= 0)
	{
		if ((scene->world_map[row][col] == 2 || scene->world_map[row][col] == 0)
		&& scene->world_map[row + 1][col] == 7)
			ft_error_msg("There is an error in the map");
		row--;
	}
}

void	check_row(t_maps_data *scene)
{
	int	col;
	int	row;

	row = 0;
	while (row <= scene->row_max)
	{
		col = 0;
		while (scene->world_map[row][col] != 1)
		{
			if (scene->world_map[row][col] != 7)
				ft_error_msg("There is an error in the map");
			col++;
			if (col == scene->col_max)
				ft_error_msg("There is an error in the map");
		}
		while (col <= scene->col_max)
		{
			if ((scene->world_map[row][col] == 2
				|| scene->world_map[row][col] == 0)
				&& scene->world_map[row][col - 1] == 7)
				ft_error_msg("There is an error in the map");
			col++;
		}
		check_row_rev(scene, row++);
	}
}

void	check_row_rev(t_maps_data *scene, int row)
{
	int	col;

	col = scene->col_max;
	while (scene->world_map[row][col] != 1)
	{
		if (scene->world_map[row][col] != 7)
			ft_error_msg("There is an error in the map");
		col--;
		if (col == 0)
			ft_error_msg("There is an error in the map");
	}
	while (col >= 0)
	{
		if ((scene->world_map[row][col] == 2 || scene->world_map[row][col] == 0)
		&& scene->world_map[row][col + 1] == 7)
			ft_error_msg("There is an error in the map");
		col--;
	}
}
