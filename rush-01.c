#include <unistd.h>
#include <stdlib.h>

int valid(char *str);
int solve(int *input, int ***result);

void print(int **str)
{
	int i;
	int j;
	int c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = str[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void fill(int *input, char *str)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			input[counter] = str[i] - '0';
			counter++;
		}
		i++;
	}
}

int error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void free_all(int **result, int *input)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(result[i]);
		i++;
	}
	free(result);
	free(input);
}

int main(int argc, char **argv)
{
	int *input;
	int **result;
	int i;

	if (argc == 2)
	{
		if (valid(argv[1]) == 1)
		{
			input = malloc(16 * sizeof(int));
			result = malloc(4 * sizeof(int *));
			i = 0;
			while (i < 4)
				result[i++] = malloc(4 * sizeof(int));
			fill(input, argv[1]);
			if (solve(input, &result) == 1)
				print(result);
			else
			{
				free_all(result, input);
				return (error());
			}
			free_all(result, input);
			return (0);
		}
	}
	return (error());
}
