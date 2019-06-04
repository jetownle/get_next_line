/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 23:26:40 by jetownle          #+#    #+#             */
/*   Updated: 2019/06/04 00:28:03 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_copyuntil(char **dst, char *src, char c)
{
	int	i;

	i = -1;
	while (src[++i])
		if (src[i] == c)
			break ;
	*dst = ft_strndup(src, i);
	return (i);
}
