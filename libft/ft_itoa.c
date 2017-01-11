/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 04:31:45 by aviau             #+#    #+#             */
/*   Updated: 2015/12/28 02:27:51 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	long	nbr;
	char	*ret;

	nbr = n;
	i = ft_nbrlen(nbr);
	if (!(ret = ft_strnew(i)))
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	while (i)
	{
		i--;
		ret[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (ret[i] == '0' && ret[1] != '\0')
		ret[i] = '-';
	return (ret);
}
