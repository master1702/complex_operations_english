all : main.c player.c player.h
	gcc -c main.c player.c

main.o : main.c player.h
	gcc -c main.c 

player.o : player.c player.h
	gcc -c player.c 	

prog : player.o main.o
	gcc -o prog main.o player.o 
prog0 : main.o
	gcc -o prog main.o
clean :
	rm -rf *.o
	
mrproper : clean
	rm -rf prog.exe