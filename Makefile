# Homework 1

CC=gcc -std=c99

all: cast_conv

cast_conv: test.c cast_conv.c binary_convert2.c cast_conv.h
	${CC} -o cast_conv test.c cast_conv.c binary_convert2.c

clean:
	rm -f cast_conv