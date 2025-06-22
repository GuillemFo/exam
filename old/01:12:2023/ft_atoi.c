#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int result;
	int	flag;
	int i;

	i = 0;
	flag = 1;
	result = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = - 1;
		i++;
	}
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'|| str[i] == '\r'|| str[i] == 'f')
		i++; 
	while (str[i] != '\0')
	{

		if	(str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += str[i] - '0';
			i++;
		}
		else
			return (result * flag);
	}
	return (result * flag);
}

int	main(int ac, char **av)
{
	int result_m;
	int	result_og;
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	result_m = ft_atoi(av[1]);
	result_og = atoi(av[1]);

	printf("My: %d\nOG: %d\n", result_m,result_og);

}
