int nums_valid(int row, int col, int num, int **result)
{
    int i;

    i = 0;
    while (i < col)
    {
        if (result[row][i] == num)
            return 0;
        i++;
    }
    i = 0;
    while (i < row)
    {
        if (result[i][col] == num)
            return 0;
        i++;
    }
    return 1;
}

int valid_helper(int *space, int *numbers, int *i, char *str)
{
    while (str[*i] != '\0')
    {
        if (str[*i] == ' ')
        {
            if (*space == 1)
                return (0);
            *space = 1;
        }
        else if (str[*i] >= '1' && str[*i] <= '4')
        {
            if (*space == 0)
                return (0);
            *numbers = *numbers + 1;
            *space = 0;
        }
        else
            return (0);
        *i += 1;
    }
    return (1);
}

int valid(char *str)
{
    int space;
    int numbers;
    int i;
    int valid;

    i = 0;
    space = 1;
    numbers = 0;
    valid = valid_helper(&space, &numbers, &i, str);
    if (valid == 0)
        return (0);
    if (numbers == 16 && space == 0)
        return (1);
    return (0);
}
