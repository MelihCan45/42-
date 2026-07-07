void    ft_parser(char *str, int clues[4][4]);
void    ft_print_board(int board[4][4]);
void    check_fillable_column(int board[4][4], int clues[4][4]);
void    check_fillable_row(int board[4][4], int clues[4][4]);
void    ft_print_board(int board[4][4]);
int    solve_puzzle(int board[4][4], int clues[4][4]);

void    init_board(int board[4][4])
{
    int r;
    int c;

    r = 0;
    while(r < 4)
    {
        c = 0;
        while (c < 4)
        {
            board[r][c] = 0;
            c++;
        }
        r++;
    }
}

#include <unistd.h>

int     main(int ac, char **av)
{
    int clues[4][4];
    int board[4][4];
    
    if (ac != 2)
    {
        write(1, "error", 5);
    }
    init_board(board);
    ft_parser(av[1], clues);
    check_fillable_column(board, clues);
    check_fillable_row(board, clues);
    solve_puzzle(board,clues);
    ft_print_board(board);

    return(0);
}