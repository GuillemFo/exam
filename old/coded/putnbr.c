#include <unistd.h>

void	putnbr(nb)
{
	//char base[20] = "0123456789abcdef";
	if (nb >= 10)
		putnbr(nb / 10);
	char nbr = (nb %10) +'0';
	write (1, &nbr, 1);
}	

int	main()
{
	int nb;
	nb = 5435;

	putnbr(nb);
	return (0);
}