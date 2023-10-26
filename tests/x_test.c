#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	int	i = 42;

	test_printf("%#x", 0);
	test_printf("%#x", 1);
	test_printf("%#x", 255);
	test_printf("%x", i);
	test_printf("%2x", i);
	test_printf("%5x", i);
	test_printf("%05x", i);
	test_printf("%#5x", i);
	test_printf("%#010x", i);
	test_printf("%-10xH", i);
	test_printf("%10.xH", 0);
}