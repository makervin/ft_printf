#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	char	*ptr = "hello, world";

	test_printf("%p", ptr);
	test_printf("%5p", ptr);
	test_printf("%20p", ptr);
	test_printf("%-20pH", ptr);
	test_printf("%20p", NULL);
}