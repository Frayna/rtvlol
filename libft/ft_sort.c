/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 06:35:37 by aviau             #+#    #+#             */
/*   Updated: 2015/12/28 06:35:39 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_sort(void *input)
{
	unsigned char	sav;
	int				i;
	int				a;
	int				size;

	i = 0;
	a = 1;
	size = ft_strlen((char *)input);
	while (a)
	{
		if (((char *)input)[i] > ((char *)input)[i + 1] && i < size - 1)
		{
			sav = ((char *)input)[i + 1];
			((char *)input)[i + 1] = ((char *)input)[i];
			((char *)input)[i] = sav;
			a++;
		}
		i++;
		if (i == size)
		{
			a = (a == 1) ? 0 : 1;
			i = 0;
		}
	}
	return (input);
}
