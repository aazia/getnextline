#ifndef HEADER_H
# define HEADER_H
# include "g_libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# define BUFF_SIZE 10

int	main(int argc, char **argv);
int	get_next_line(const int fd, char **line);

#endif
