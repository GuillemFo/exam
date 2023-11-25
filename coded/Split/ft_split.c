#include <stdio.h>
#include <stdlib.h>


int	ft_count_words(char *str)
{
	int	i;
	int	counter;
	i = 0;
	counter = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
		if (!(str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
		{
			while (str[i + 1] != '\n' && str[i + 1] != '\t' && str[i + 1] != ' ' && str[i + 1] != '\0')
			{
				i++;
			}
			i++;
			counter++;
		}
	}
	return(counter);
}

char *ft_strcpy(char *str, int i, int w)
{
	char *s2;
	int	x;
	x = 0;

	s2 = malloc((w + 1) * sizeof(char));
	while (w > 0)
	{
		s2[x] = str[i - w];
		x++;
		w--;
	}
	s2[x] = '\0';
	return (s2);
}


char	**ft_split(char *str)
{
	char	**out;
	int	word_count;
	int	i;
	int	w;
	int	k;

	i = 0;
	k = 0;

	word_count = ft_count_words(str);
	out = malloc((word_count + 1) * sizeof(char *));
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
		else if (str[i] != '\n' || str[i] != '\t' || str[i] != ' ')
		{
			w = 0;
			while (str[i] != '\n' && str[i] != '\t' && str[i] != ' '&& str[i] != '\0')
			{
				i++;
				w++;
			}
			out[k] = ft_strcpy(str, i, w);
			k++;
		}
	}
	out[k] = malloc(w+1 * sizeof(char));
	out[k] = NULL;
	return (out);
}

int main(int argc, char **argv)
{
	char	**split;
	int		i;

	if (argc == 1)
	{
		split = ft_split(" hola buenas tardes a");
			printf("%s ", split[0]);
		i = 1;
		while (split[i] != 0)
		{
			printf("%s ", split[i]);
			i++;
		}
		printf("%s", split[i]);
	}
	printf("\n");

    return (0);
}
