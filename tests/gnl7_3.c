#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line.h"

/*
** 4 lines with 8 chars without Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "tests/gnl7_3.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				{
					errors+= 1;
				}
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
				errors += 2;
			if (count_lines == 2 && strcmp(line, "4567890") != 0)
				errors += 3;
			if (count_lines == 3 && strcmp(line, "defghijk") != 0)
			{
				errors += 4;
			}
			count_lines++;
			printf("in test: line : %s\n", line);
			if (count_lines > 5)
				break ;
		}
		close(fd);
		printf("ending line : %s\n", line);
		if (count_lines != 4)
		{
			printf("-> should have returned '1' four times instead of %d time(s)\n", count_lines);
			printf("error: %s, %d\n", line, ret);
		}
		if (errors > 0)
		{
			printf("-> errors: %d, should have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghijk\"\n", errors);
		}
		if (count_lines == 4 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
