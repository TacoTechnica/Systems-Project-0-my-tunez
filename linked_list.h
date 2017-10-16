struct song_node {char name[256]; char artist[256]; struct node * next;};


void print_list(struct song_node *);

// Pointers because we don't need our strings to be mutable
struct song_node * insert_front(struct song_node *, char *name, char *artist);

struct song_node *insert_ordered(struct song_node *, char *name, char *artist);

struct song_node * free_list(struct song_node *);
