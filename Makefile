all: main
main: main.cpp
	g++ -Wall -Werror main.cpp -o main
	run
run: ./main
