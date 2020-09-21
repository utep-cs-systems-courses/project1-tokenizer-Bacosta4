#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int main(){
  char input[20];
  printf(">");
  scanf("%[^\n]%*c", input);
  printf("%s\n", input);
  printf("is space char %d\n", space_char(input[0]));
  printf("is non space char %d\n", non_space_char(input[0]));
  char test[50] = "Hello World!";
  char test1[50] = "Hello";
  char *p = word_start(test);
  printf("start %c\n",*p);
  char *f = word_terminator(test1);
  printf("end %c\n",*(f-1));
  return 0;
}

int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c == '\0')
    {
      return 1; // True if it contains a tab/ space
    }
  else
    {
      return 0;
    }
}

int non_space_char(char c)
{
  if ((c == '\t' || c == ' ') && c == '\0')
    {
      return 0; // True if not a tab/ space
    }
  else
    {
      return 1;
    }
}

char *word_start(char *str)
{
  for (int i = 0; i >= 0; i++)
    {
      if(non_space_char(str[1])) // Checks if there is non space
	{
	  char *p = &str[i];
	  return p;
	}
    }
  char *p = &str[0];
  return p;
}

char *word_terminator(char *str){
  for(int i = 0; i >=0;i++){
    if(non_space_char(str[i])){
      if(space_char(str[i+1]) || str[i+1] == '\n'){
	char *p = &str[i];
	return p;
      }
    }
  }
}
  
int count_words(char *str)
{
  int i = 0;
  int words= 0;
  char iterator;
  while ((iterator = *str++) != '\0')
    {
    if (non_space_char(iterator))
      {
      if(i == 0 && iterator != '\n')
	{
	words++;
	i = 1;
      }
    }
    else{
      i = 0;
    }
  }
  return words;
}
