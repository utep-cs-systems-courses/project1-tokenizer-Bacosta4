#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List));    // Allocate memory for list
  return list;
}

void add_history(List *list, char *str)
{
  Item *new_node = malloc(sizeof(Item));
  new_node->str = str;
 
  if (list->root == NULL) {   // If the first item in the list , it becomes the root.
    new_node->id = 1;
    new_node->next = NULL;
    list->root = new_node;
  }
  else {                          // otherwise make the new node a point to the old root, then
                                  //assign root to the new note
    int curr_id = list->root->id;
    curr_id++;
    new_node->id = curr_id;
    new_node->next = list->root;
    list->root = new_node;
  }
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;

  while(temp != 0) {
    if(temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;   // if not found, return null
}

void print_history(List *list)
{
  Item *temp = list->root->next;

  while (temp != NULL) {
    printf("&d. %s\n",temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item *temp = list->root;

  while(temp != NULL) {
    Item *curr = temp;
    temp = temp->next;
    free(curr);
  }
  free(temp);
  free(list);
}
