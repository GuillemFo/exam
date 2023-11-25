#include <unistd.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	i = 0;
	int sign;
	sign = 1;
	int result;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'F' || str[i] >= 'a' && str[i] <= 'f')
	{
		result = result * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			result = result + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'f')
		   result = result + (str[i] - 'a' + 10);
		i++;
	}
	return (sign * result);	


}
/*
int	main()
{
	printf("%d\n", ft_atoi_base("Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.i", 16));
}
*/
