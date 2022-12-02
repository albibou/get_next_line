#!/bin/bash

gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=$1 ../get_next_line.c ../get_next_line_utils.c ../main.c 
$3 ./a.out test$2.txt > diff.txt
cat -e diff.txt 
diff test$2.txt diff.txt
rm -f ./a.out
