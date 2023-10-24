#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	int	i = 42;

	test_printf("%#X\n", 255);
	test_printf("%X\n", i);
	test_printf("%2X\n", i);
	test_printf("%5X\n", i);
	test_printf("%05X\n", i);
	test_printf("%#5X\n", i);
	test_printf("%#010X\n", i);
	test_printf("%-10XH\n", i);
}