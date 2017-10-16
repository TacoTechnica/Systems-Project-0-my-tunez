#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_list(struct node * head){

  while (head){ 
    printf("%d --> ", head->i); 
    head = head->next; // move to the next node
    }
  printf("NULL\n"); // print out the null at the end
}

struct node * insert_front(struct node * head, int cargo){
  struct node * new_head = malloc(sizeof(struct node)); 
  new_head->i = cargo; /new head of list

}

struct node * free_list(struct node * head){
  while (head){ 
    struct node * temp = head; 
    head = head->next; // move from current node to next node
    free(temp); // free current node using temp pointer
  }
  return head; // return null
}
	  
