#include<stdio.h>

#include "music_organizer.h"
#include "linked_list.h"



int main() {
	struct song_node *songs = create_node();
	songs = insert_front(songs, "The A song", "Asdf");
	songs = insert_front(songs, "The B song", "Asdf");
	songs = insert_front(songs, "Song ladasifja", "Bbbb");
	songs = insert_front(songs, "Song M", "Ccc");
	print_list(songs);
	return 0;
}
