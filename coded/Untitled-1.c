#include <unistd.h>

void	putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


void	ft_rostring(char *s)
{
	int i;
	int j;
	int	word;
	int x;
	
	i = 0;
	j = 0;
	word = 0;
	x = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		i++;
		j++;
	}

	while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
	{
		word++;
		i++;
	}
	if (s[x] == ' ' || s[x] == '\t' || s[x] == '\n')
		{
			while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n')
				x--;
		}
	while (s[i] != '\0' && (x - j) > 0)
	{
		putchar(s[i]);
		i++;
		x--;
	}
	putchar(' ');
	while (word > 0)
	{
		putchar(s[j]);
		j++;
		word--;
	}
}




int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 1);
	else
		{
			ft_rostring(av[1]);
			write(1, "\n", 1);
		}
	return (0);
}
