#include <stdio.h>
#include "libft.h"
#include <string.h>

int main(void)
{
    //Teste memset
    char text1[10];
    char text2[10];
    char char_test;
    size_t size_string;

    char_test = '9';
    size_string = 10;
    ft_memset(text1, char_test, size_string);
    printf("FT_memset:%s\n", text1);
    memset(text2, char_test, size_string);
    printf("memset:%s\n", text2);
    return 0;
}
