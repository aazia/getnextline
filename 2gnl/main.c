#include "header.h"

int		line_copy(char **line, char *content, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

t_list	*get_live(int fd, t_list **hist)
{
	t_list	*tmp;

	if (!hist)
		return (NULL);
	tmp = *hist;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(hist, tmp);
	return (tmp);
}

int		my_read(const int fd, char **content)
{
	int		read_result;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((read_result = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_result] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\0'))
			break ;
	}
	return (read_result);
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	size_t		read_result;
	static t_list	*hist;
	t_list		*live;
	char		*tmp;
	
	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 || (!(live = get_live(fd, &hist))))
		return (-1);
	tmp = live->content;
	read_result = my_read(fd, &tmp);
	live->content = tmp;
	if (!read_result && !*tmp)
		return (0);
	read_result = line_copy(line, live->content, '\0');
	tmp = live->content;
	if (tmp[read_result] != '\0')
	{
		live->content = ft_strdup(&((live->content)[read_result + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	char	*line;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		close(fd);
	}
	return (0);
}
