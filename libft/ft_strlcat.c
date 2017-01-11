/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 03:24:32 by aviau             #+#    #+#             */
/*   Updated: 2016/01/28 03:24:48 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t j;
	size_t ret;

	len = ft_strlen(dst);
	ret = size;
	if (len > size)
		len = size;
	j = -1;
	while (src[++j] && size-- > len + 1)
		dst[j + len] = src[j];
	if (ret > j + len)
		dst[j + len] = '\0';
	return (ft_strlen(src) + len);
}
