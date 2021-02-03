#include <ft_memset.h>

int main(void)
{
    char text[10];

    ft_memset(text, 'p', 9);
    printf(text);
    return 0;
}