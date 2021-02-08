#include <stdio.h>
#include "libft.h"
#include <strings.h>
#include <string.h>

int main(void)
{
    //Teste memset
    char text1[20];
    char text2[20];

    //memset
    printf("Função: memset\n");
    ft_memset(text1, '9', 20);
    printf("ft_memset:%s\n", text1);
    memset(text2, '9', 20);
    printf("original:%s\n", text2);
    printf("--------------------\n");
    //bzero
    printf("Função: bzero\n");
    ft_bzero(text1+4, 4);
    printf("ft_bzero:%s\n", text1);
    bzero(text2+4, 4);
    printf("original:%s\n", text2);
    printf("--------------------\n");
    //memcpy
    char test_memcpy_1[20] = "Eita";
    char test_memcpy_2[20] = " Carambola";
    char test_memcpy_3[20] = "Eita";
    char test_memcpy_4[20] = " Carambola";
    printf("Função: memcpy\n");
    ft_memcpy(test_memcpy_1, test_memcpy_2, 9);
    printf("ft_bzero:%s\n", test_memcpy_1);
    memcpy(test_memcpy_3, test_memcpy_4, 9);
    printf("original:%s\n", test_memcpy_3);
    printf("--------------------\n");
    //memccpy
    char test_memccpy_1[10] = "";
    char test_memccpy_2[10] = " Carambola";
    char test_memccpy_3[10] = "";
    char test_memccpy_4[10] = " Carambola";
    printf("Função: memccpy\n");
    ft_memccpy(test_memccpy_1, test_memccpy_2, 'l', 20);
    printf("ft_memccpy:%s\n", test_memccpy_1);
    memccpy(test_memccpy_3, test_memccpy_4, 'l', 20);
    printf("original:%s\n", test_memccpy_3);
    printf("--------------------\n");
    return 0;
}
