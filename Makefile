run: main
	./main

main: td_bis.o
	gcc -o main -Wall td_bis.o
	
td_bis.o: td_bis.c
	gcc -c td_bis.c


ham: hamm
	./hamm

hamm: hamm.o
	gcc -Wall -o hamm hamm.o
	
hamm.o: hamm.c
	gcc -c hamm.c



clean:
	rm -f td_bis.o
	rm -f main
