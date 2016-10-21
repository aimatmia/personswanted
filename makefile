GCC = gcc -g
　
all: tunes
　
tunes: playlist.o song_node.o main.o
	${GCC} main.o song_node.o playlist.o -o tunes
playlist.o: playlist.c playlist.h 
	${GCC} -c playlist.c
songnode: song_node.o
	${GCC} song_node.o -o tune
song_node.o: song_node.c song_node.h 
	${GCC} -c song_node.c
main.o: main.c playlist.h song_node.h 
	${GCC} -c main.c
clean: 
	rm *.o
