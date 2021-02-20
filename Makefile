main: main.c
	g++ -Wall -Werror main.cpp -o main
	run
run: ./main
