struct song_node {
	char name[256];
	char artist[256];
	struct song_node *next;
}

song_node *add_song(char *name, char *artist);

song_node *search_song(char *query);

song_node *search_artist(char *query);

void print_songs_under_certain_letter(char letter);

void print_songs_of_certain_artist(char *artist);

void print_entire_library();

void print_shuffle();

song_node *delete_song(song_node *node);

void delete_all();
