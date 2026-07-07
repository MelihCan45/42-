void    ft_parser(char *str, int clues[4][4])
{
    int i ;
    int filled_str;

    i = 0;
    filled_str = 0;
    
    while(i < 4)
    {
        clues[0][i] = str[filled_str] - '0';
        clues[1][i] = str[filled_str + 8] - '0';
        clues[2][i] = str[filled_str + 16] - '0';
        clues[3][i] = str[filled_str + 24] - '0';
        
        i++;
        filled_str += 2;
    }
}