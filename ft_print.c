#include<unistd.h>

void    ft_putnbr(int n)
{
    char nb;

    if (n >= 10)
    {
        ft_putnbr(n / 10);
    }
    nb = (n % 10) + '0';
    write(1, &nb, 1);
}

void    ft_print_board(int board[4][4])
{
    int r;
    int c;

    r = 0;
    while(r < 4)
    {
        c = 0;
        while (c < 4)
        {
            ft_putnbr(board[r][c]);
            if(c < 3)
            {
                write(1, " ", 1);
            }
            c++;
        }
        write(1, "\n", 1);
        r++;
    }
}