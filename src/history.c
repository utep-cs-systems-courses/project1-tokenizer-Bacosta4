#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

//int main()
//{
//List* list = init_history();
//add_history(list, "hello world");
//add_history(list, "a b c ");
//add_history(list, "test string");

//char* str = get_history(list,1);
  //printf("%s\n",str);

  //print_history(list);
  //free_history(list);
  //printf("History freed\n");
  //print_history(list);
  //return 0;
//}

List *init_history()
{
  List* list = malloc(sizeof(struct s_List));
  return list;
}

void add_history(List *list, char *str)
{
  Item* new_node = malloc(sizeof(struct s_Item));

  new_node->str = str;

 
  if (list->root == NULL) {
    new_node->id = 1;
    new_node->next = NULL;
    list->root = new_node;
  }
  else {
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

  while(temp != NULL) {
    if(temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;
}

void print_history(List *list)
{
  Item *temp = list->root;

  while (temp != NULL) {
    printf("%s\n",temp->str);
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
