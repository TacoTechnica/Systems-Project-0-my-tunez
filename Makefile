all: music_library.o linked_list.o
	gcc music_library.o linked_list.o -o music_lib

run: all
	valgrind --leak-check=yes ./music_lib

music_library.o: music_library.c music_library.h linked_list.h
	gcc -cg music_library.c

linked_list.o: linked_list.c linked_list.h
	gcc -cg linked_list.c

clean:
	rm music_lib
	rm *.o
