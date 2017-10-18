all: music_organizer.o linked_list.o
	gcc music_organizer.o linked_list.o -o music_lib

run: all
	valgrind --leak-check=yes ./music_lib

music_organizer.o: music_organizer.c music_organizer.h linked_list.h
	gcc -c -g music_organizer.c linked_list.h music_organizer.h

linked_list.o: linked_list.c linked_list.h
	gcc -c -g linked_list.c linked_list.h

clean:
	rm music_lib
	rm *.o
