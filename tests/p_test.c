#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	char	*ptr = "hello, world";

	ft_printf	("lft\t:%p\n", ptr);
	printf		("std\t:%p\n", ptr);
	printf		("\n");
	ft_printf	("lft\t:%5p\n", ptr);
	printf		("std\t:%5p\n", ptr);
	printf		("\n");
	ft_printf	("lft\t:%20p\n", ptr);
	printf		("std\t:%20p\n", ptr);
	printf		("\n");
	ft_printf	("lft\t:%-20pH\n", ptr);
	printf		("std\t:%-20pH\n", ptr);
	printf		("\n");
	ft_printf	("lft\t:%20p\n", NULL);
	printf		("std\t:%20p\n", NULL);
}