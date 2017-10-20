#include<stdio.h>

#include "music_organizer.h"
#include "linked_list.h"

struct song_node *table[26];

int main() {

    // Initialize our song table
    int i;
    for(i = 0; i < 26; i++) {
        struct song_node *new_head = create_node();
        //JAJAJANK JAJAJANK JAJAJAJNK JANK JANK
        new_head->artist[0] = NULL;
        new_head->name[0] = NULL;
        table[i] = new_head;
    }

    /*struct song_node *songs = create_node();
	songs = insert_ordered(songs, "The B song", "Asdf");
	songs = insert_ordered(songs, "The A song", "Asdf");
	songs = insert_ordered(songs, "Song Ladasifja", "Bbbb");
	songs = insert_ordered(songs, "Song M", "Ccc");
	*/

	add_song("The B song", "Asdf");
	add_song("The A song", "Asdf");
	add_song("Song Ladasifja", "Bbbb");
	add_song("Song M", "Ccc");

    print_entire_library();

    printf("length of A list: %d\n", list_size(table[0]));
    printf("length of B list: %d\n", list_size(table[1]));
    printf("length of C list: %d\n", list_size(table[2]));
    printf("length of D list: %d\n", list_size(table[3]));    
    

    struct song_node *found = search_song("The A song", "Asdf");
    if (found) {
        printf("Found song! %s by %s\n", found->name, found->artist);
    } else {
        printf("Failed to find song\n");
    }

    print_songs_of_certain_artist("Asdf");
    print_songs_under_certain_letter('A');

    return 0;
}


// Finds what index to put in our song array
// based on the artist's first letter
int artist_to_index(char *artist) {
    char first = *artist;
    if (first >= 'a' && first <= 'z') {
        return (int)(first - 'a');
    } else {
        return (int)(first - 'A');
    }
}


struct song_node *add_song(char *name, char *artist) {
    int index = artist_to_index(artist);
    printf("INDEX: %d\n", index);
    return insert_ordered(table[index], name, artist);
}

struct song_node *search_song(char *song, char *artist) {
    struct song_node *head = table[artist_to_index(artist)];
    while( head ) {
        if (!strcmp(head->name, song)) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

struct song_node *search_artist(char *artist) {
    struct song_node *head = table[artist_to_index(artist)];
    while(head) {
        if (!strcmp(head->artist, artist)) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void print_songs_under_certain_letter(char letter) {
    printf("\nSongs under the letter \'%c\':\n-------------------\n", letter);
    print_list(table[artist_to_index(&letter)]);
}

void print_songs_of_certain_artist(char *artist) {
    struct song_node *current = search_artist(artist);

    printf("\nSongs by %s:\n----------------\n", artist);

    if (!current) {
        printf("None found!\n");
        return;
    }

    while(current && (strcmp(current->artist, artist) == 0)) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void print_entire_library() {
    printf("\n======ENTIRE MUSIC LIBRARY======\n\n");
    int i = 0;
    for(i = 0; i < 26; i++) {
        // If the node list isn't empty
        if (table[i]->next) {
            printf("\n~ %c ~\n ___________\n", 'A' + (char)i );
            print_list(table[i]);
        }
    }
    printf("\n================================\n");
}

void print_shuffle();

struct song_node *delete_song(char *song, char *artist);

void delete_all();
