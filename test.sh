#!/bin/bash
make all
cc tests/"$1"_test.c tests/tester.c -L. -L./libft -lftprintf -lft -I. -w -o test
./test