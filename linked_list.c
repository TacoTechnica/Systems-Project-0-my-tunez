#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct song_node *create_node() {
	struct song_node *new_node = malloc(sizeof(struct song_node));
	new_node->next = NULL;
	return new_node;
}


void print_list(struct song_node * head){
    while (head) {
        // if null, ignore
    	if (head->artist[0] && head->name[0]) {
            printf("%s : %s\n", head->artist, head->name);
    	}
        head = head->next; // move to the next node
    }
}

struct song_node * insert_front(struct song_node * head, char *name, char *artist){
  	struct song_node * new_head = create_node();
    strcpy(new_head->name, name);
    strcpy(new_head->artist, artist);
	new_head->next = head;
	return new_head;
}

struct song_node * free_list(struct song_node * head){
  while (head){
    struct song_node * temp = head;
    head = head->next; // move from current node to next node
    free(temp); // free current node using temp pointer
  }
  return head; // return null
}

struct song_node * insert_ordered(struct song_node *head, char *name, char *artist) {
	// Keep going until we find an artist alphabetically ahead
	while((head->next) && (strcmp(artist, head->next->artist) > 0)) {
		head = head->next;
	}
	// Now do the same thing but for our name
	/*while(head && (head->next) && (strcmp(artist, head->next->artist) == 0) && (strcmp(name, head->next->name) > 0)) {
		head = head->next;
	}*/
	// Now our head is in the right position!
	// Make a newnode and insert into the list
	struct song_node *newnode = (struct song_node *) malloc(sizeof(struct song_node));
	strcpy(newnode->name, name);
	strcpy(newnode->artist, artist);
	newnode->next = head->next;
	head->next = newnode;
	return newnode;
}


int list_size(struct song_node * head){
  if (!head) return 0;
  head = head->next; // skip past null node at front
  int i;
  for (i = 0; head; head= head->next, i++);
  return i;

}
