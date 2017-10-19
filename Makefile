
# Set this to nothing if we don't want to compile with debug options
DEBUG_FLAG = -g
# Name of our compiled application (huzzah, variables exist)
APP_NAME = music_lib.out


all: music_organizer.o linked_list.o
	gcc music_organizer.o linked_list.o -o $(APP_NAME)

run: all
	valgrind --leak-check=yes ./$(APP_NAME)

music_organizer.o: music_organizer.c music_organizer.h linked_list.h
	gcc -c $(DEBUG_FLAG) music_organizer.c

linked_list.o: linked_list.c linked_list.h
	gcc -c $(DEBUG_FLAG) linked_list.c 

clean:
	rm -f $(APP_NAME)
	rm -f *.o
