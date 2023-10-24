#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	test_printf("%.1s", "hello");
	test_printf("%.1d", 255);
	test_printf("%010.5d", 255);
	test_printf("%010.5x", 255);
	test_printf("%010.x", 255);
	test_printf("%.s", "");
	test_printf("%7.05s", "hello");
	test_printf("%.04s", NULL);
	test_printf("%3.s", NULL);
	test_printf("%.i", 0);
	test_printf("%5.i", 0);
	test_printf("%.u", 0);
	test_printf("%5.u", 0);
}