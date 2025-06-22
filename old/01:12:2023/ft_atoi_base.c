#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int 	check_base(char s, int str_base)
{
	char	base[16] = "0123456789abcdef";
	char	BASE[16] = "0123456789ABCDEF";
	int	i;

	i = 0;
	while (i < str_base)
	{
		if (s == base[i] || s == BASE[i])
			return (1);
		i++;
	}
	return (0);
}


int	ft_atoi_base(const char *str, int str_base)
{
	int	flag;
	int	result;
	int	i;

	flag = 1;
	result = 0;
	i = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (check_base(str[i], str_base) == 1)
		{	
			result *= str_base;
			if (str[i] >= '0' && str[i] <= '9')
				result += str[i] - '0';
			else if (str[i] >= 'A' && str[i] <= 'F')
				result += str[i] - 'A' + 10;
			else if (str[i] >= 'a' && str[i] <= 'f')
				result += str[i] - 'a' + 10;
			i++;
		}
		else
			return (result * flag);
	}
	return (result * flag);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1), 1);
	printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
}