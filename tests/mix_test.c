#include <stdio.h>
#include <limits.h>

#include "tester.h"

int main()
{
	test_printf("");
	test_printf("", NULL);
	test_printf("", NULL, NULL, NULL);
	test_printf("%d");
}