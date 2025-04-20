int nums_valid(int row, int col, int num, int **result);
int checker(int *input, int **result);

int solver(int row, int col, int *input, int **result)
{
    int i;
    int k;

    if (row == 4)
    {
        if (checker(input, result) == 0)
            return 0;
        return 1;
    }
    i = 1;
    while (i <= 4)
    {
        if (nums_valid(row, col, i, result) == 1)
        {
            result[row][col] = i;
            if (col + 1 > 3)
                k = solver(row + 1, 0, input, result);
            else
                k = solver(row, col + 1, input, result);
            if (k == 1)
                return 1;
        }
        i++;
    }
    return 0;
}

int solve(int *input, int ***result)
{
    return solver(0, 0, input, *result);
}