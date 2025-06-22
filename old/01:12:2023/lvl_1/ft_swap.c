#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	*tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

int	main()
{
	int	a_v;
	int b_v;
	int	*a;
	int *b;
	
	a_v = 10;
	b_v = 15;

	a = &a_v;
	b = &b_v;
	printf("%d\n", *a);
	printf("%d\n", *b);
	ft_swap(a, b);
	printf("%d\n", *a);
	printf("%d\n", *b);
	
}