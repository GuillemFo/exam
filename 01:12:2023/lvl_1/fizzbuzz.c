#include <unistd.h>


void	ft_write_num(int i)
{
	char	str[10] = "0123456789";
	if (i > 9)
		ft_write_num(i / 10);
	write(1, &str[i % 10], 1);
}


int	main()
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
		{
			write(1, "fizz", 4);
			i++;
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz", 4);
			i++;
		}
		else if (i % 15 == 0)
		{
			write(1, "fizzbuzz", 8);
			i++;
		}
		else 
		{
			ft_write_num(i);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}