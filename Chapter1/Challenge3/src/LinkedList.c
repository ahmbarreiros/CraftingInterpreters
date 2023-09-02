#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

struct node {
  int value;
  struct node* last;
  struct node* next;
};

struct linkedList {
  Node* head;
  Node* tail;
  int length;
};

LinkedList* create_list() {
  LinkedList* li = (LinkedList*)malloc(sizeof(LinkedList));
  if(li != NULL) {
    li->head = NULL;
    li->tail = NULL;
    li->length = 0;

    return li;
  }
}

void free_list(LinkedList* li) {
  if(li != NULL && li->head != NULL) {
    Node* head = li->head;
    Node* next = NULL;
    do {
      next = head->next;
      free(head);
    } while(next != NULL);
    li->length = 0;
    free(li);
  }
}

int insert_at_beginning(LinkedList* li, int value) {
  if(li != NULL) {
    Node *new_node = (Node*)malloc(sizeof(Node*));
    new_node->value = value;
    new_node->last = NULL;
    new_node->next = NULL;
    if(li->length == 0) {
      li->head = new_node;
      li->tail = new_node;
    } else {
      new_node->next = li->head;
      li->head->last = new_node;
      li->head = new_node;
    }
    li->length++;
    return 1;
  }
  return 0;
}

int insert_at_end(LinkedList *li, int value) {
  if(li != NULL) {
    Node *new_node = (Node*)malloc(sizeof(Node*));
    new_node->value = value;
    new_node->next = NULL;
    new_node->last = NULL;
    if(li->length == 0) {
      li->head = new_node;
      li->tail = new_node;
    } else {
      li->tail->next = new_node;
      new_node->last = li->tail;
      li->tail = new_node;
    }
    li->length++;
    return 1;
  }
  return 0;
}

int insert(LinkedList *li, int value, int position) {
  if(li != NULL) {
    if(position == 0) {
      return insert_at_beginning(li, value);
    } else if(position >= li->length) {
      return insert_at_end(li, value);
    }
    Node *new_node = (Node*)malloc(sizeof(Node*));
    new_node->value = value;
    new_node->next = NULL;
    new_node->last = NULL;
    if(li->length == 0) {
      li->head = new_node;
      li->tail = new_node;
    } else {
      int cont = 0;
      Node* node = li->head;
      while(node != NULL && cont < position) {
	node = node->next;
	cont++;
      }
      if(node != NULL && cont == position) {
	new_node->last = node->last;
	node->last->next = new_node;
	new_node->next = node;
	node->last = new_node;
      }
    }
    li->length++;
    return 1;
  }
  return 0;
}


void print_list(LinkedList *li) {
  if(li != NULL) {
    if(li->length != 0) {
      Node* node = li->head;
      while(node != NULL) {
	printf("%d\n", node->value);
	if(node->last != NULL) {
	  printf("last: %d\n", node->last->value);
	}
	node = node->next;
      }
    }
  }
}
