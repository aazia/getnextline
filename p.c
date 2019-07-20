/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:56:32 by azkeever          #+#    #+#             */
/*   Updated: 2019/01/08 12:19:03 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			nbread;
	
	if (fd < 0 && *line == NULL)
	{
		return (-1);
	}
	if (*line)
		(void) ft_memset((void*)*line, 0, ft_strlen(*line));
	(void) ft_memset((void *)buff, 0, BUFF_SIZE);
	while ((nbread = read(fd, (void *)buff, BUFF_SIZE) > 0))
		{
			buff[BUFF_SIZE] = '\0';
			if (ft_strchr((char *)buff, '\n'))
			{
/*				ft_strclr(ft_strchr((char *)buff, '\n'));
*/				*line = ft_strcat(*line, buff);
				return (1);
			}
			if (!(*line))
				*line = malloc(sizeof(*line));
			*line = ft_strcat(*line, buff);
			ft_memset((void *)buff, 0, BUFF_SIZE);
		}
	if (nbread == -1 || nbread == 0)
		return (-1);
	return (0);
}
