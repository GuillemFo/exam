#include <stdio.h>
#include <stdlib.h>

int	ft_size(int nbr)
{
	int i;
	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 10)
	{
		nbr = nbr /10;
		i++;
	}
	i++;
	return (i);
}


char	*ft_itoa(int nbr)
{
	char	*opt;
	int	len;
	len = ft_size(nbr);
	opt = malloc((len +1) * sizeof(char));
	opt[len] = '\0';
	if (nbr < 0)
	{
		opt[0] = '-';
		nbr *= -1;
	}
	while (nbr >= 10)
	{
		opt[len -1] = (nbr %10) + '0';
		nbr = nbr /10;
		len--;
	}
	opt[len - 1] = (nbr %10) + '0';
	return (opt);
}
/*
char	*ft_itoa(int nbr);

int main(int argc, char **argv)
{
    //printf("%s\n", ft_itoa(atoi(argv[1])));
	printf("%s\n", ft_itoa(-2498));
    return (0);
}
*/