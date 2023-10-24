#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	int	i = 42;

	test_printf("%#x\n", 1);
	test_printf("%#x\n", 255);
	test_printf("%x\n", i);
	test_printf("%2x\n", i);
	test_printf("%5x\n", i);
	test_printf("%05x\n", i);
	test_printf("%#5x\n", i);
	test_printf("%#010x\n", i);
	test_printf("%-10xH\n", i);
}