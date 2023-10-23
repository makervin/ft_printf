#!/bin/bash
make all
cc tests/d_test.c -L. -L./libft -lftprintf -lft -I. -w -o test
./test