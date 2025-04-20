int check_col(int i, int *input, int **result, int direction)
{
    int j;
    int max = 0;
    int answer = 0;

    if (direction == 1)
        j = 3;
    else
        j = 0;
    while ((direction == 1 && j >= 0) || (direction == 0 && j < 4))
    {
        if (result[j][i % 4] > max)
        {
            max = result[j][i % 4];
            answer++;
        }
        if (direction == 1)
            j--;
        else
            j++;
    }
    if (answer == input[i])
        return 1;
    return 0;
}

int check_row(int i, int *input, int **result, int direction)
{
    int j;
    int max = 0;
    int answer = 0;

    if (direction == 0)
        j = 0;
    else
        j = 3;
    while ((direction == 1 && j >= 0) || (direction == 0 && j < 4))
    {
        if (result[i % 4][j] > max)
        {
            max = result[i % 4][j];
            answer++;
        }
        if (direction == 0)
            j++;
        else
            j--;
    }
    if (answer == input[i])
        return 1;
    return 0;
}

int checker(int *input, int **result)
{
    int i = 0;
    while (i < 4)
    {
        if (check_col(i, input, result, 0) == 0 || check_col(i + 4, input, result, 1) == 0)
            return 0;
        i++;
    }
    i = 8;
    while (i < 12)
    {
        if (check_row(i, input, result, 0) == 0 || check_row(i + 4, input, result, 1) == 0)
            return 0;
        i++;
    }
    return 1;
}
