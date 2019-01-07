/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:56:32 by azkeever          #+#    #+#             */
/*   Updated: 2019/01/07 14:25:06 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			nbread;
	//static char	*temp;

/*	if (!(temp = malloc(sizeof(*temp))))
	{
		ft_putendl("failed malloc for static char");
		return (-1);
	}*/
	ft_putendl("passed malloc");
	(void) ft_memset(*line, 0, ft_strlen(*line));
	ft_putendl("\n rob");
	(void) ft_memset((void *)buff, 0, BUFF_SIZE);
	ft_putstr("\nseg f??\n");
	while ((nbread = read(fd, (void *)buff, BUFF_SIZE) > 0))
		{
			ft_putendl("in while loop");
			if (ft_strchr((char *)buff, '\n'))
			{
				ft_putendl("in if statement");
				ft_strclr(ft_strchr((char *)buff, '\n'));
				*line = ft_strcat(*line, buff);
				//ft_strcpy(*line, temp);
				return (1);
			}
			*line = ft_strcat(*line, buff);
			ft_memset((void *)buff, 0, BUFF_SIZE);
		}
	if (nbread == -1 || nbread == 0)
		return (-1);
	return (0);
}

int		main(void)
{
	int		fd;
	int		i;
	int		new;
	char	*line;

	i = 0;
	if (!(line = malloc(sizeof(*line))))
		return (-1);
	fd = open("gnl1_1.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((new = get_next_line(fd, &line) > 0))
	{
//		new = get_next_line(fd, &line);
		//ft_putstr("return of gnl: ");
		//ft_putnbr(new);
		//ft_putchar('\n');
		ft_putendl(line);
	}
	close(fd);
	return (0);
}
