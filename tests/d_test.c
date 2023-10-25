#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	int	i = 42;

	test_printf("%d", i);
	test_printf("%2d", -i);
	test_printf("%5d", i);
	test_printf("%05d", i);
	test_printf("%05d", -i);
	test_printf("%-05dH", i);
	test_printf("%-10dH", i);
	test_printf("%+ 5d", i);
	test_printf("% d", i);
	test_printf("%+ d", i);
	test_printf("% 05d", i);
	test_printf("%5d", -i);
	test_printf("%.5d", i);
	test_printf("% .5d", i);
	test_printf("%10.5d", -i);
	test_printf("%010.5d", -i);
	test_printf("%10.*d", 10, -i);
}	