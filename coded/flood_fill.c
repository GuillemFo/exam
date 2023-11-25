#include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

void	fill(char **area, t_point size, t_point begin, char to_fill)
{
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y || area[begin.y][begin.x] != to_fill)
		return;
	
	area[begin.y][begin.x] = 'F';
	fill(area, size, (t_point){begin.x + 1, begin.y}, to_fill);
	fill(area, size, (t_point){begin.x - 1, begin.y}, to_fill);
	fill(area, size, (t_point){begin.x, begin.y + 1}, to_fill);
	fill(area, size, (t_point){begin.x, begin.y - 1}, to_fill);
}

void	flood_fill(char **area, t_point size, t_point begin)
{
	fill(area, size, begin, area[begin.y][begin.x]);
}


int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}