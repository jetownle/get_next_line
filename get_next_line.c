/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:43:06 by jetownle          #+#    #+#             */
/*   Updated: 2019/06/06 06:03:07 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char *s[4096];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;
	int			i;

	i = -1;
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = s[fd];
		if (!(s[fd] = ft_strjoin(tmp, buf)))
			s[fd] = ft_strdup(buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(s[fd]))
		return (0);
	while (s[fd][++i])
		if (s[fd][i] == '\n')
			break ;
	*line = ft_strndup(s[fd], i);
	(i < (int)ft_strlen(s[fd])) ? s[fd] += (i + 1) : ft_strclr(s[fd]);
	return (1);
}
