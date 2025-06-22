#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int size;
	size = tab[len -1];
	while (len > 0)
	{
		if (tab[len -1] > size)
			size = tab[len -1];
		len--;
	}
	return (size);
}
int main() {
    int array[] = {3, 7, 2, 8, 5};
    unsigned int length = sizeof(array) / sizeof(array[0]);

    int result = max(array, length);

    printf("The maximum value in the array is: %d\n", result);

    return 0;
}
