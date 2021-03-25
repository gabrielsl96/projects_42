#include <stdio.h>

#include <limits.h>

#include "ft_printf.h"



int main(void)

{
char *teste1 = "%09s";

	printf("Original: %i \n", printf(teste1, "hi low"));

		printf("\nMinha: %i\n", ft_printf(teste1, "hi_low"));

			return (0);
}
