#include <unistd.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int	i;
	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	main(int ac, char **av)
{
	char *result;
	int	i;
	i = 0;

	if (ac != 3)
		write(1, "\n", 1);
	result = ft_strcpy(av[2], av[1]);
	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
}