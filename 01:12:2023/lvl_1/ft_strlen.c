#include <unistd.h>

void	ft_write_num(int i)
{
	char	base[10] = "0123456789";
	if (i > 9)
		ft_write_num(i / 10);
	write(1, &base[i % 10], 1);
}


int	ft_strlen(char *str)
{
	int len;
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
int	main(int ac, char **av)
{
	int result;

	result = ft_strlen(av[1]);

	ft_write_num(result);
	write(1, "\n", 1);
}