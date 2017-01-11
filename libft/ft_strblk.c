/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strblk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 02:05:16 by aviau             #+#    #+#             */
/*   Updated: 2015/12/28 02:26:50 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *str)
{
	int i;
	int out;

	i = 0;
	out = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			out++;
		i++;
	}
	return (out);
}

char		*ft_strblk(char *input)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	output = (char *)malloc(sizeof(char) * count(input));
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\n' && input[i] != '\t')
		{
			output[j] = input[i];
			j++;
		}
		i++;
	}
	output[j] = '\0';
	return (output);
}
