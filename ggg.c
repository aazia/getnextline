/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:56:32 by azkeever          #+#    #+#             */
/*   Updated: 2019/01/08 14:51:09 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Function to retrieve next line */
int		get_next_line(const int fd, char **line)
{
	static char	*str;;
	char		*buff;
	int		nbread;
	
	/* check for errors */
	if (fd < 0 || fd >= 1025 || (read(fd, stack[fd], 0) < 0) \
		|| !(heap = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	
	/* check to see if there's anything in the static character */
	if (*str)
	{
		if (ft_strchr(stack[fd], '\n'))
			return (1);
	}


	/* allocate buff for BUFF_SIZE */
	ft_memalloc(buff, 0, BUFF_SIZE);
	
	/* while read is able to put new things in buffer */
	while ((nbread = read(fd, (void *)buff, BUFF_SIZE) > 0))
		{
			ft_putendl("in while loop");
			/* null terminate buffer */
			buff[nbread] = '\0';
			/* if there is a null termination in the buffer */
			if (ft_strchr((char *)buff, '\n'))
			{
				ft_strclr(ft_strchr((char *)buff, '\n'));
				*line = ft_strcat(*line, buff);
				return (1);
			}
			/* if there's no line, malloc for line? */
			if (!(*line))
			{
				ft_putendl("in if 2");
				*line = malloc(sizeof(*line));
			}
			*line = ft_strcat(*line, buff);
			ft_memset((void *)buff, 0, BUFF_SIZE);
			if (nbread == 0)
				return (1);
		}
	if (nbread == -1)
	{
		ft_putendl("returned -1 ");
		return (-1);
	}
	ft_putendl("returning 0");
	ft_putnbr(nbread);
	ft_putendl("");
	return (0);
}
