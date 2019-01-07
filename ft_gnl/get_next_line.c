/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:56:32 by azkeever          #+#    #+#             */
/*   Updated: 2019/01/07 14:35:19 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			nbread;
	ft_putendl("inside");
	if (fd < 0 || line == NULL)
		return (-1);
	ft_putendl("did not return null");
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
	int		ret;
	char	*line;

	i = 0;
	line = NULL;
	fd = open("gnl1_1.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		ft_putendl(line);
	}
	close(fd);
	return (0);
}
