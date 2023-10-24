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
}