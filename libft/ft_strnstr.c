/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 04:34:49 by aviau             #+#    #+#             */
/*   Updated: 2015/12/13 13:32:51 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	if (s2[i] == '\0')
		return ((char *)&s1[i]);
	while (s1[i])
	{
		j = i;
		k = 0;
		while ((s1[j] == s2[k]) && (j < n))
		{
			j++;
			k++;
			if (s2[k] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
