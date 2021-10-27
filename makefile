all: tree.c main.c
		gcc -Wall -o AVLtree $^
clean:
		rm AVLtree