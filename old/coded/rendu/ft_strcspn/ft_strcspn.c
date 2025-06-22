#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i;
	int j;
	j = 0;
	while (s[j] != '\0')
	{
		i = 0;
		while (s[j] != reject[i] && reject[i] != '\0')
			i++;
		if (s[j] == reject[i])
			return (j);
		j++;
	}
	return (j);
}
/*
int	main()
{	
	printf("%lu\n", strcspn("", "zbq"));
	printf("%lu\n", ft_strcspn("", "zbq"));
}
*/
