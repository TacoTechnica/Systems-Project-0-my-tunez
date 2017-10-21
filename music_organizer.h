
struct song_node *add_song(char *song, char *artist);

struct song_node *search_song(char *song, char *artist);

struct song_node *search_artist(char *query);

void print_songs_under_certain_letter(char letter);

void print_songs_of_certain_artist(char *artist);

void print_entire_library();

void print_shuffle();

void *delete_song(char *song, char *artist);

void delete_all();

int library_size();
