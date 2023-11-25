#include <stdlib.h>
#include <stdio.h>
int	ft_size(nbr)
{
	int i;
	i = 0;
	if (nbr < 0 )
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr /10;
		i++;
	}
	i++;
	return (i);
}
char	*ft_itoa(int nbr)
{
	int size;
	char *result;
	
	size = ft_size(nbr);
	result = malloc ((size +1) * sizeof(char));
	result[size] = '\0';
	size--;
	if (nbr == 0)
		result[size] = '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr *-1;
	}
	while (nbr >= 10)
	{
		result[size -1] = nbr %10 + '0';
		nbr = nbr /10;
		size--;
	}
	result[size -1] = nbr + '0';
	return (result);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(0));
}
*/

