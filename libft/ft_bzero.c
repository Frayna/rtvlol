/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 04:31:18 by aviau             #+#    #+#             */
/*   Updated: 2015/12/06 17:03:50 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*s_cast;
	unsigned int	i;

	i = 0;
	s_cast = (unsigned char *)s;
	while (s_cast[i] != '\0' && i < n)
	{
		s_cast[i] = '\0';
		i++;
	}
}
