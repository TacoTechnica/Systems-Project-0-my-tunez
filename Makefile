
DEBUG_FLAG = -g 

all: music_organizer.o linked_list.o
	gcc music_organizer.o linked_list.o -o music_lib.out

run: all
	valgrind --leak-check=yes ./music_lib

music_organizer.o: music_organizer.c music_organizer.h linked_list.h
	gcc -c $(DEBUG_FLAG) music_organizer.c

linked_list.o: linked_list.c linked_list.h
	gcc -c $(DEBUG_FLAG) linked_list.c 

clean:
	rm music_lib
	rm *.o
