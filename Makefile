all: demo

demo: demo.c
	gcc -o demo demo.c -lm -Wall
