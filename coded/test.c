#include <unistd.h>

int	ft_atoi(char *str)
{
	int n = 0;

	while (*str != '\0')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	print_hex(int nb)
{
	char 	base[20] = "0123456789abcdef";
	if (nb >= 16)
	{
		print_hex(nb /16);
	}
		write(1, &base[nb%16], 1);

}


int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}