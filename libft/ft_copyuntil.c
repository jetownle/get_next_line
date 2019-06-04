/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 23:26:40 by jetownle          #+#    #+#             */
/*   Updated: 2019/06/03 22:52:13 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_copyuntil(char **dst, char *src, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	*dst = ft_strndup(src, i);
/*	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoinch(*dst, src[count])))
			return (0);
		count++;
	}
*/
	return (i);
}
