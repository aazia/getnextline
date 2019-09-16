#include <stdio.h>
#include "libft/libft.h"

int	main(void)
{
	char *str;
	char **str2;
	int i;

	i = 0;
	str = "helloworld";
	str2 = ft_strsplit(str, '\n');

	if (ft_strcmp(str, &str[2]))
		ft_putendl("worked");
	else
	{
		ft_putendl(str);
		ft_putendl(str2[0]);
	}
	while (str2[i])
		free(str2[i++]);
	free(str2);
	return (0);
}
