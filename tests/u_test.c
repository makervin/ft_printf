#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	unsigned int	i = 42;

	test_printf("%u", i);
	test_printf("%2u", i);
	test_printf("%5u", i);
	test_printf("%05u", i);
	test_printf("%-05uH", i);
	test_printf("%-10uH", i);
	test_printf("%+ 5u", i);
	test_printf("% u", i);
	test_printf("%+ u", i);
	test_printf("% 5u", i);
	test_printf("% 05u", i);
	test_printf("%5u", i);
	test_printf("%.5u", i);
	test_printf("% .5u", i);
	test_printf("%10.5u", i);
	test_printf("%010.5u", i);
	test_printf("%10.*u", 10, i);
}