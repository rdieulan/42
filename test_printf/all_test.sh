#!/bin/bash

nb=1

gcc "$nb"_ref.c -o ref
gcc "$nb"_test.c ../printf/ft_printf.c ../printf/libft/libft.a -o own

./ref > ref.txt
./own > own.txt
