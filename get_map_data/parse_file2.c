/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:33:24 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_data.h"

void	ft_id_we(char **tmp, char *str, t_maps_data *scene)
{
	if (str[2] == ' ' && tmp[1] != NULL && tmp[2] == NULL
		&& scene->we_tex == NULL)
		scene->we_tex = ft_strdup(tmp[1]);
	else
		ft_error_msg("West Texture format wrong");
}

void	ft_id_ea(char **tmp, char *str, t_maps_data *scene)
{
	if (str[2] == ' ' && tmp[1] != NULL && tmp[2] == NULL
		&& scene->ea_tex == NULL)
		scene->ea_tex = ft_strdup(tmp[1]);
	else
		ft_error_msg("East Texture format wrong");
}

void	ft_id_s(char **tmp, char *str, t_maps_data *scene)
{
	if (str[1] == ' ' && tmp[1] != NULL && tmp[2] == NULL
		&& scene->s_tex == NULL)
		scene->s_tex = ft_strdup(tmp[1]);
	else
		ft_error_msg("Sprite Texture format wrong");
}

void	ft_id_f(char **tmp, char *str, t_maps_data *scene)
{
	char	**tmp2;

	tmp2 = ft_split(tmp[1], ',');
	if (str[1] == ' ' && tmp2[0] != NULL && tmp2[1] != NULL
		&& tmp2[2] != NULL && tmp2[3] == NULL && scene->floor_red == -1
		&& scene->floor_green == -1 && scene->floor_blue == -1)
	{
		scene->floor_red = ft_atoi(tmp2[0]);
		scene->floor_green = ft_atoi(tmp2[1]);
		scene->floor_blue = ft_atoi(tmp2[2]);
		if (scene->floor_red < 0 ||scene->floor_green < 0
			||scene->floor_blue < 0 ||scene->floor_red > 255
			||scene->floor_green > 255 ||scene->floor_blue > 255)
			ft_error_msg("Floor R,G,B colors not in range [0,255]");
	}
	else
		ft_error_msg("Floor format wrong");
	ft_free_array_strings(tmp2);
}

void	ft_id_c(char **tmp, char *str, t_maps_data *scene)
{
	char	**tmp2;

	tmp2 = ft_split(tmp[1], ',');
	if (str[1] == ' ' && tmp2[0] != NULL && tmp2[1] != NULL
		&& tmp2[2] != NULL && tmp2[3] == NULL && scene->ceiling_red == -1
		&& scene->ceiling_green == -1 && scene->ceiling_blue == -1)
	{
		scene->ceiling_red = ft_atoi(tmp2[0]);
		scene->ceiling_green = ft_atoi(tmp2[1]);
		scene->ceiling_blue = ft_atoi(tmp2[2]);
		if (scene->ceiling_red < 0 ||scene->ceiling_green < 0
			||scene->ceiling_blue < 0 ||scene->ceiling_red > 255
			||scene->ceiling_green > 255 ||scene->ceiling_blue > 255)
			ft_error_msg("Ceiling color too small [0,255]");
	}
	else
	{
		ft_error_msg("Ceiling format wrong");
		exit(0);
	}
	ft_free_array_strings(tmp2);
}
