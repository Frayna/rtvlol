/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 04:34:12 by aviau             #+#    #+#             */
/*   Updated: 2016/11/20 06:15:25 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char const *s1, char const *s2, int ifre)
{
	char	*result;

	if (s1 && s2)
	{
		result = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (result)
		{
			ft_strcpy(result, s1);
			ft_strcat(result, s2);
		}
		else
			result = NULL;
	}
	else
		result = NULL;
	if (ifre == 1 || ifre == 3)
		ft_strdel((char **)&s1);
	if (ifre == 2 || ifre == 3)
		ft_strdel((char **)&s2);
	return (result);
}

char	*ft_strjoin(char const *a, char const *b)
{
	int		i;
	int		j;
	char	*r;

	if (!a || !b)
		return (NULL);
	i = 0;
	j = 0;
	if (!(r = (char*)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1))))
		return (NULL);
	while (a[i] != '\0')
	{
		r[j] = a[i];
		i++;
		j++;
	}
	i = 0;
	while (b[i] != '\0')
	{
		r[j] = b[i];
		i++;
		j++;
	}
	r[j] = '\0';
	return (r);
}
