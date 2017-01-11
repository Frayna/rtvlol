/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 04:32:31 by aviau             #+#    #+#             */
/*   Updated: 2015/12/15 00:23:14 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_cast;
	size_t			i;

	i = 0;
	s_cast = (unsigned char *)s;
	while (i < n)
	{
		s_cast[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
