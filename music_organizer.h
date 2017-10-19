
struct song_node *add_song(char *name, char *artist);

struct song_node *search_song(char *query);

struct song_node *search_artist(char *query);

void print_songs_under_certain_letter(char letter);

void print_songs_of_certain_artist(char *artist);

void print_entire_library();

void print_shuffle();

struct song_node *delete_song(struct song_node *node);

void delete_all();
