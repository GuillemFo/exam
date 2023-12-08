#include <stdio.h>
#include <unistd.h>
int	ft_strlen(char *s)
{
	int	i;
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char    *ft_strrev(char *str)
{
	int	i;
	int len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	printf("%d\n", len);
	while (i < (len / 2))
	{
		tmp = str[i];
		str[i] = str[len -1 - i]; // len -1 (por el null) - i(los caracteres que he cambiado ya)
		str[len -1 - i] = tmp;
		i++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	printf("%s\n", ft_strrev(av[1]));
}