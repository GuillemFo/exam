#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *s)
{
	int result;
	int	i;
	int	sign;
	
	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			result = result *10 +s[i] - '0';
		else
			return (result * sign);
		i++;
	}

	return (result * sign);
}

int	main()
{
	char test[20] = "-12f3";

	printf("%d\n", atoi(test));
	printf("%d\n", ft_atoi(test));
	
}