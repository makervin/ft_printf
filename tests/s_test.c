#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	ft_printf	("lft\t:%s\n", "hello");
	printf		("std\t:%s\n", "hello");
	printf		("\n");
	ft_printf	("lft\t:%5s\n", "hello");
	printf		("std\t:%5s\n", "hello");
	printf		("\n");
	ft_printf	("lft\t:%10s\n", "hello");
	printf		("std\t:%10s\n", "hello");
	printf		("\n");
	ft_printf	("lft\t:%-10sH\n", "hello");
	printf		("std\t:%-10sH\n", "hello");
	printf		("\n");
	ft_printf	("lft\t:%s\n", NULL);
	printf		("std\t:%s\n", NULL);
	printf		("\n");
	ft_printf	("lft\t:% 10s\n", NULL);
	printf		("std\t:% 10s\n", NULL);
}