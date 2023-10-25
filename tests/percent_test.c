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
	test_printf("%.5%");
	test_printf("%.5%");
	test_printf("%010.5%");
	test_printf("hello world %");
	test_printf("%q");
}