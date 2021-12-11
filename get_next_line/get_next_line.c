/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:14:41 by mpezzull          #+#    #+#             */
/*   Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	t_line	gnl;

	gnl.len = 0;
	if (!(line))
		return (-1);
	gnl.temp[0] = '\0';
	gnl.ret = read(fd, &gnl.buffer, 1);
	while (gnl.ret > 0)
	{
		if (gnl.buffer == '\n' || gnl.buffer == '\0')
			break ;
		gnl.temp[gnl.len++] = gnl.buffer;
		gnl.ret = read(fd, &gnl.buffer, 1);
	}
	gnl.temp[gnl.len + 1] = '\0';
	gnl.str = ((char *)malloc(sizeof(char) * (gnl.len + 1)));
	if (!(gnl.str))
		return (-1);
	gnl.str[gnl.len] = '\0';
	while (gnl.len-- >= 0)
		gnl.str[gnl.len] = gnl.temp[gnl.len];
	*line = gnl.str;
	return (gnl.ret);
}
