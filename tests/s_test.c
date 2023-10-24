#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	test_printf("%s", "hello");
	test_printf("%5s", "hello");
	test_printf("%10s", "hello");
	test_printf("%-10sH", "hello");
	test_printf("%s", NULL);
	test_printf("% 10s", NULL);
	test_printf("%.s", "");
	test_printf("%7.05s", "hello");
	test_printf("%.04s", NULL);
	test_printf("%3.s", NULL);
}