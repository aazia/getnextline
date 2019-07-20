
#include "get_next_line.h"

int	ft_checkline(char **str, char **line)
{
	char 	**strbloc;
	int	i;

	i = 0;
	strbloc = ft_strsplit(*str, '\n');
	if (ft_strcmp(strbloc[0], *str) == 0)
	{
	// 	if there's no new line character return (0)
		return (0);	
	}
	// if there is a nl 1) replace stack w/ everything after nl
	if (strbloc[1])
		*str = ft_strdup(strbloc[1]);
	else
		ft_strclr(*str);
	// 2) assign everything before newline character to *line 
	*line = ft_strdup(strbloc[0]);
	/// free bloc
	free(strbloc);
	// return 1 to affirm there is a new line character & we dissected stack
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char	*str[1025];
	char		*buffer;
	int		nbread;
	char		*tmpstr;

	// check for errors
	if (!line || fd < 0 || fd >= 1025 || (read(fd, str[fd], 0) < 0) || \
		!((buffer = ft_strnew(BUFF_SIZE))))
		return (-1);
	// check if there's something in the stack
	if (str[fd])
	{
		ft_putstr("Current str[fd]: ");
		ft_putendl(str[fd]);
		ft_putendl("in if str[fd]");
	// 	if there is something in the stack check if there's a new line
		if (ft_checkline(&str[fd], line))
		{
	//		if there is that means we should return 1 BECAUSE
			ft_putendl("returning 1");
			return (1);
		}
	}	
	
	// read the file buffer by buffer (as to buffer_size) until the file ends (read returns 0)
	//	OR until a newline appears
	while ((nbread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[nbread] = '\0';
	// 	append each new buffer to stack, 
		if (str[fd])
		{
			tmpstr = ft_strjoin(str[fd], buffer);
			str[fd] = ft_strdup(tmpstr);
			tmpstr = NULL;
		}
	// 	if no stack then buffer == stack
		else
			str[fd] = ft_strdup(buffer);
	// 	if there is a new line, break from reading and 
		
		if (ft_checkline(&str[fd], line))
		{
	//		1) append stack up to newline into line
	//		2) add all the rest of stack back into etack
			break;
		}
		//ft_putstr("str[fd]: ");
		//ft_putendl(str[fd]);
	}
	
	//free buffer since we finished reading
	free(buffer);
	
	//	check to see if we are at the end of file or it was just a new line
	if (nbread == 0)
	{
		
		return (nbread);
	}
	//	return the ret value of 
	ft_putstr("returning nbread : ");
	ft_putnbr(nbread);
	ft_putendl("");
	*line = ft_strdup(str[fd]);
//	str[fd] = NULL;
	return (1);
}

// why does he have to force RET_VALUE in his read function
// how do we finish reading the file
// 
