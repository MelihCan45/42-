int	check_row_right(int board[4][4], int clues[4][4], int row, int col)
{
	int	max;
	int	count;
	int	i;

	if (col == 3)
	{
		max = 0;
		count = 0;
		i = -1;
		while (++i < 4)
		{
			if (board[row][i] > max)
			{
				max = board[row][i];
				count++;
			}
		}
		if (count != clues[2][row])
			return (0);

        max = 0;
		count = 0;
		i = -1;
		while (++i < 4)
		{
			if (board[row][3-i] > max)
			{
				max = board[row][3-i];
				count++;
			}
		}
		if (count != clues[3][row])
			return (0);
    }
	return (1);
}

int check_column_down(int board[4][4], int clues[4][4], int row, int col)
{
    int max;
    int count;
    int i;

    if(row == 3)
    {
        max = 0;
        count = 0;
        i = -1;
        while(++i < 4)
        {
            if(board[i][col] > max)
            {
                max = board[i][col];
                count++;
            }
        }
        if (count != clues[0][col])
        {
        return 0;
        }

        max = 0;
        count = 0;
        i = -1;
        while(++i < 4)
        {
            if(board[3-i][col] > max)
            {
                max = board[3-i][col];
                count++;
            }
        }
        if (count != clues[1][col])
        {
        return 0;
        }
    }
    return (1);
}
