#include "includes/ft_printf.h"

int main(void)
{
	printf("%d\n", ft_printf("%u\n", -1));
	printf("%d\n", printf("%u\n", -1));
}