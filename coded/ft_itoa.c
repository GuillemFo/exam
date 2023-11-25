#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int	ft_size(int n)
{
	int i;
	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int	i;

	i = ft_size(nbr);
	result = malloc ((ft_size(nbr) +1) * sizeof(char));
	result[i] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		result[i -1] = (nbr % 10) + '0';
		nbr = nbr /10;
		i--;
	}
	return (result);
}	


int	main()
{
	int n;
	n = 123;
	printf("%s\n", ft_itoa(n));
	printf("size = %d\n", ft_size(n));
}