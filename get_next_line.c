/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:43:06 by jetownle          #+#    #+#             */
/*   Updated: 2019/06/14 19:56:19 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	appendline(char **s, char **line, int fd)
{
	char *tmp;
	int i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strdup(&s[fd][i + 1]);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *s[4096];
	char buf[BUFF_SIZE + 1];
	char *tmp;
	int ret;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
			return (-1);
	while((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
				s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
				break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(s, line, fd));
}
