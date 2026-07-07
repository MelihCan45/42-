
void    fill_full_row(int board[4][4], int left, int right, int i)
{
    if (left == 1 && right == 4)
    {
        board[i][0] = 4;
        board[i][1] = 3;
        board[i][2] = 2;
        board[i][3] = 1;
    } 
    else if (left == 4 && right == 1)
    {
        board[i][0] = 1;
        board[i][1] = 2;
        board[i][2] = 3;
        board[i][3] = 4;
    }
}

void    fill_partial_row(int board[4][4], int left, int right, int i)
{
    if (left == 1 && right == 2)
        {
            board[i][0] = 4;
            board[i][3] = 3;
        }
    else if (left == 2 && right == 1)
        {
            board[i][0] = 3;
            board[i][3] = 4;
        }
}

void    check_fillable_row(int board[4][4], int clues[4][4])
{
    int i;
    int l;
    int r;

    i = -1;
    while(++i < 4)
    {
        //here clues[2][i] gives us clues that we need to
        //check from left view and [3] from right view
        l = clues[2][i];
        r = clues[3][i];
        if ((l == 1 && r ==4) || (l == 4 && r==1))
            fill_full_row(board, l, r, i);
        else if ((l == 2 && r == 1) || (l == 1 && r == 2))
            fill_partial_row(board, l, r, i);
        else if (l == 3 && r == 2)
            board[i][2] = 4;
        else if (l == 2 && r == 3)
            board[i][1] = 4;
        else if (l == 1)
            board[i][0] = 4;
        else if (r == 1)
            board[i][3] = 4;
    }
}