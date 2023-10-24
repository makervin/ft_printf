#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	test_printf("%");
	test_printf("%%");
	test_printf("%%%");
	test_printf("%%%%");
	test_printf("%%%%%");
	test_printf("%5%");
}