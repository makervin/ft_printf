#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	int	i = 42;

	test_printf(" 'd'\t:%d", i);
	test_printf(" '2d'\t:%2d", -i);
	test_printf(" '5d'\t:%5d", i);
	test_printf(" '05d'\t:%05d", i);
	test_printf(" '05d'\t:%05d", -i);
	test_printf(" '-05dH'\t:%-05dH", i);
	test_printf(" '-10dH'\t:%-10dH", i);
	test_printf(" '+ 5d'\t:%+ 5d", i);
	test_printf(" ' d'\t:% d", i);
	test_printf(" '+ d'\t:%+ d", i);
	test_printf(" ' 05d'\t:% 05d", i);
	test_printf(" '5d'\t:%5d", -i);
	test_printf(" '.5d'\t:%.5d", -i);
	test_printf(" '10.5d'\t:%10.5d", -i);
	test_printf(" '10.5d'\t:%010.5d", -i);
	test_printf(" '10.5d'\t:%10.*d", 10, -i);
}	