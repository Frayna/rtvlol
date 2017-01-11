/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 04:35:06 by aviau             #+#    #+#             */
/*   Updated: 2016/01/28 10:30:02 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		len;
	char	*ret;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s) - 1;
	while (s[start] == ' ' | s[start] == '\n' | s[start] == '\t')
		start++;
	while (s[len] == ' ' | s[len] == '\n' | s[len] == '\t' && len > start)
		len--;
	len = len - start + 1;
	if (!(ret = ft_strsub((char *)s, start, len)))
		return (NULL);
	ret[len] = '\0';
	return (ret);
	return (NULL);
}
