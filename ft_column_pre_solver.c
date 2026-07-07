void    fill_full_column(int board[4][4], int up, int down, int i)
{
    if (up == 1 && down == 4)
    {
        board[0][i] = 4;
        board[1][i] = 3;
        board[2][i] = 2;
        board[3][i] = 1;
    } 
    else if (up == 4 && down == 1)
    {
        board[0][i] = 1;
        board[1][i] = 2;
        board[2][i] = 3;
        board[3][i] = 4;
    }
}

void    fill_partial_column(int board[4][4], int up, int down, int i)
{
    if (up == 1 && down == 2)
        {
            board[0][i] = 4;
            board[3][i] = 3;
        }
    else if (up == 2 && down == 1)
        {
            board[0][i] = 3;
            board[3][i] = 4;
        }
}

void    check_fillable_column(int board[4][4], int clues[4][4])
{
    int i;
    int u;
    int d;

    i = -1;
    while(++i < 4)
    {
        u = clues[0][i];
        d = clues[1][i];
        if ((u == 1 && d == 4) || (u == 4 && d==1))
            fill_full_column(board, u, d, i);
        else if ((u == 2 && d == 1) || (u == 1 && d == 2))
            fill_partial_column(board, u, d, i);
        else if (u == 3 && d == 2)
            board[2][i] = 4;
        else if (u == 2 && d == 3)
            board[1][i] = 4;
        else if (u == 1)
            board[0][i] = 4;
        else if (d == 1)
            board[3][i] = 4;
    }
}