#include "libft.h"

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
    char test_memcpy_1[20] = "asdkjasdjkadsah";
    char test_memcpy_2[20] = " Carambola";
    char test_memcpy_3[20] = "asdkjasdjkadsah";
    char test_memcpy_4[20] = " Carambola";
    printf("Função: memcpy\n");
    ft_memcpy(test_memcpy_1, test_memcpy_2, 9);
    printf("ft_bzero:%s\n", test_memcpy_1);
    memcpy(test_memcpy_3, test_memcpy_4, 9);
    printf("original:%s\n", test_memcpy_3);
    printf("--------------------\n");
    //memccpy
    char test_memccpy_1[20] = "asdkjasdjkadsah";
    char test_memccpy_2[20] = " Carambola";
    char test_memccpy_3[20] = "asdkjasdjkadsah";
    char test_memccpy_4[20] = " Carambola";
    printf("Função: memccpy\n");
    ft_memccpy(test_memccpy_1, test_memccpy_2, 'a', 20);
    printf("ft_memccpy:%s\n", test_memccpy_1);
    memccpy(test_memccpy_3, test_memccpy_4, 'a', 20);
    printf("original:%s\n", test_memccpy_3);
    printf("--------------------\n");
    //memmove
    char test_memmove_1[10] = "";
    char test_memmove_2[10] = " Carambola";
    char test_memmove_3[10] = "";
    char test_memmove_4[10] = " Carambola";
    printf("Função: memmove\n");
    ft_memmove(test_memmove_1, test_memmove_2, 8);
    printf("ft_memmove:%s\n", test_memmove_1);
    memmove(test_memmove_3, test_memmove_4, 8);
    printf("original:%s\n", test_memmove_3);
    printf("--------------------\n");
    //memchr
    char test_memchr[10] = "Carambola";
    char test_memchr_1[10] = "Carambola";
    printf("Função: memchr\n");
    printf("ft_memchr:%s\n", ((char *)ft_memchr(test_memchr, 'l', 1)));
    printf("original:%s\n", ((char *)memchr(test_memchr_1, 'l', 1)));
    printf("--------------------\n");
    //memcmp
    char test_memcmp[10] = "Carambola";
    char test_memcmp_2[10] = "Carfmbola";
    printf("Função: memcmp\n");
    printf("ft_memcmp:%i\n", ft_memcmp(test_memcmp, test_memcmp_2, 0));
    printf("original:%i\n", memcmp(test_memcmp, test_memcmp_2, 0));
    printf("--------------------\n");
    //strlen
    char test_strlen[10] = "Carambola";
    printf("Função: strlen\n");
    printf("ft_strlen:%li\n", ft_strlen(test_strlen));
    printf("original:%li\n", strlen(test_strlen));
    printf("--------------------\n");
    //strlcpy
    char test_strlcpy_1[20] = "asdkjasdjkadsah";
    char test_strlcpy_2[20] = " Carambola";
    char test_strlcpy_3[20] = "asdkjasdjkadsah";
    char test_strlcpy_4[20] = " Carambola";
    printf("Função: strlcpy\n");
    ft_strlcpy(test_strlcpy_1, test_strlcpy_2, 20);
    printf("ft_strlcpy:%s\n", test_strlcpy_1);
    strlcpy(test_strlcpy_3, test_strlcpy_4, 20);
    printf("original:%s\n", test_strlcpy_3);
    printf("--------------------\n");
    //isalnum
    char a_alnum = ' ';
    char b_alnum = 'z';
    printf("Função: isalnum\n");
    printf("Resultado: %i\n", ft_isalnum(a_alnum));
    printf("Resultado: %i\n", ft_isalnum(b_alnum));
    printf("Original - Resultado: %i\n", isalnum(a_alnum));
    printf("Original - Resultado: %i\n", isalnum(b_alnum));
    printf("--------------------\n");
    //isalpha
    char a_alpha = 'A';
    char b_alpha = '\0';
    printf("Função: isalpha\n");
    printf("Resultado: %i\n", ft_isalpha(a_alpha));
    printf("Resultado: %i\n", ft_isalpha(b_alpha));
    printf("Original - Resultado: %i\n", isalpha(a_alpha));
    printf("Original - Resultado: %i\n", isalpha(b_alpha));
    printf("--------------------\n");
    //isdigit
    char a_digit = '9';
    char b_digit = 'a';
    printf("Função: isdigit\n");
    printf("Resultado: %i\n", ft_isdigit(a_digit));
    printf("Resultado: %i\n", ft_isdigit(b_digit));
    printf("Original - Resultado: %i\n", isdigit(a_digit));
    printf("Original - Resultado: %i\n", isdigit(b_digit));
    printf("--------------------\n");
    //isascii
    char a_ascii = '\0';
    char b_ascii = '\0';
    printf("Função: isascii\n");
    printf("Resultado: %i\n", ft_isascii(a_ascii));
    printf("Resultado: %i\n", ft_isascii(b_ascii));
    printf("Original - Resultado: %i\n", isascii(a_ascii));
    printf("Original - Resultado: %i\n", isascii(b_ascii));
    printf("--------------------\n");
    //isprint
    char a_print = '\0';
    char b_print = '\0';
    printf("Função: isprint\n");
    printf("Resultado: %i\n", ft_isprint(a_print));
    printf("Resultado: %i\n", ft_isprint(b_print));
    printf("Original - Resultado: %i\n", isprint(a_print));
    printf("Original - Resultado: %i\n", isprint(b_print));
    printf("--------------------\n");
    //toupper
    char a = 'a';
    char b = 'b';
    printf("Função: toupper\n");
    printf("Antes: %c // Depois: %c\n", a, ft_toupper(a));
    printf("Antes: %c // Depois: %c\n", b, ft_toupper(b));
    printf("Orgiinal - Antes: %c // Depois: %c\n", a, toupper(a));
    printf("Original - Antes: %c // Depois: %c\n", b, toupper(b));
    printf("--------------------\n");
    //tolower
    char c = 'C';
    char d = 'D';
    printf("Função: tolower\n");
    printf("Antes: %c // Depois: %c\n", d, ft_tolower(d));
    printf("Antes: %c // Depois: %c\n", c, ft_tolower(c));
    printf("Orgiinal - Antes: %c // Depois: %c\n", d, tolower(d));
    printf("Original - Antes: %c // Depois: %c\n", c, tolower(c));
    printf("--------------------\n");
    return (0);
    
}
