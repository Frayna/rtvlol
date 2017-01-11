/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 04:34:54 by aviau             #+#    #+#             */
/*   Updated: 2015/12/28 02:28:17 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_splitcountword(char const *s, char c)
{
	int	i;
	int out;

	i = 0;
	out = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			out++;
		while (s[i] != c && s[i])
			i++;
	}
	out = out + 1;
	return (out);
}

static int		ft_splitlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!i)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		index;
	int		i;
	int		len;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char *) * ft_splitcountword(s, c))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = ft_splitlen(&s[i], c);
			if (!(ret[index++] = ft_strsub(&s[i], 0, len)))
				return (NULL);
			i = i + len;
		}
	}
	ret[index] = NULL;
	return (ret);
}
