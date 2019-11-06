run: main
	./main

main: td_bis.o
	gcc -o main -Wall td_bis.o
	
td_bis.o: td_bis.c
	gcc -c td_bis.c
