#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_list(struct node * head){
  struct node * temp = head;

  while (head){
    printf("%d --> ", head->i);

      head = head->next;
    }
  printf("NULL\n");
}

struct node * insert_front(struct node * head, int cargo){
  struct node * new_head = malloc(sizeof(struct node)); 
  new_head->i = cargo;
  new_head->next = head;
  return new_head;

}

struct node * free_list(struct node * head){
  while (head){
    struct node * temp = head;
    head = head->next;
    free(temp);
  }
  return head;
}
	  
