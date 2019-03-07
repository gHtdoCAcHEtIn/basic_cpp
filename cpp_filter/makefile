build: filter.cpp
	g++ -c -o filter.o filter.cpp
link: filter.o
	g++ -o a.out filter.o
all: build link
	./a.out
clean: 
	rm a.out filter.o
