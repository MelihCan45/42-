int	check_row_right(int board[4][4], int clues[4][4], int row, int col);
int check_column_down(int board[4][4], int clues[4][4], int row, int col);


int find_empty_cell(int board[4][4], int *row, int *col)
{
    *row = 0;
    while(*row < 4)
    {
        *col = 0;
        while(*col < 4)
        {
            if(board[*row][*col] == 0)
                return (1);
            (*col)++;
        }
        (*row)++;
    }
    return(0);
}

int ft_count_visible(int *line)
{
    int count;
    int max_height;
    int i;

    count = 0;
    max_height = 0;
    i = 0;
    while(i < 4)
    {
        if(line[i] > max_height)
        {
            max_height = line[i];
            count++;
        }
        i++;
    }
    return(count);    
}

int is_safe(int board[4][4], int clues[4][4], int row, int col, int number)
{
    int i;

    i = 0;
    while(i < 4)
    {
        if (board[row][i] == number || board[i][col] == number)
            return (0);
        i++;
    }
    
    board[row][col] = number;
	if (col == 3 && check_row_right(board, clues, row, col) != 1)
	{
		board[row][col] = 0;
		return (0);
	}
	if (row == 3 && !check_column_down(board, clues, col, row))
	{
		board[row][col] = 0;
		return (0);
	}
    board[row][col] = 0;
	return (1);
}

int    solve_puzzle(int board[4][4], int clues[4][4])
{
    int row;
    int col;
    int number;

    if (find_empty_cell(board, &row, &col) == 0)
        return (1);

    number = 0;
    while (++number <= 4)
    {
        if (is_safe(board, clues, row, col, number) == 1)
        {
            board[row][col] = number;
            if(solve_puzzle(board,clues)==1)
                return (1);
            board[row][col] = 0;
        }
    }
    return (0);
}

