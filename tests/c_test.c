#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	test_printf("%c hello", 'a');
	test_printf("%c", 0);
	test_printf("%-c", 'a');
	test_printf("%5c", 'a');
	test_printf("%-5cH", 'a');
}