/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:25:18 by mpezzull          #+#    #+#             */
/*   Updated: 2021/01/18 13:00:20 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	y;

	i = 0;
	j = 0;
	y = 0;
	while (dest[i])
		i++;
	while (src[y])
		y++;
	if (len <= i)
		y += len;
	else
		y += i;
	while (src[j] && (i + 1) < len)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (y);
}
