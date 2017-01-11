/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 04:31:54 by aviau             #+#    #+#             */
/*   Updated: 2015/12/28 02:22:10 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest0;
	unsigned char	*src0;

	i = 0;
	dest0 = (unsigned char *)dest;
	src0 = (unsigned char *)src;
	while (i < n)
	{
		dest0[i] = src0[i];
		if (src0[i] == (unsigned char)c)
			return ((void*)&dest0[i + 1]);
		i++;
	}
	return (NULL);
}
