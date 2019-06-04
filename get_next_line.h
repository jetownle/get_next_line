/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:03:41 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/28 21:30:47 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Macro that allows u to choose the size of the reading buffer for the read
** function. This value will be modified during the defence to evaluate
** the strength of your function. The marco must be named BUFF_SIZE.
** For example :
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 42

int	get_next_line(const int fd, char **line);
#endif
