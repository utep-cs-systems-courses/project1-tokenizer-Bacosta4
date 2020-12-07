#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if (c == ' ' || c == '\t') {
    return 1;
  }
  else {
    return 0;
  }
}

int non_space_char(char c) {
  if (c ==' ' || c == '\t' || c=='\0'){
    return 0;
  }
  else {
    return 1;
  }
}

char *word_start(char *str)
{
  for (int i = 0; i >= 0; i++) {                // Iterates until letter is found
    if(non_space_char(str[1])) {                // Checks if there is non space
	  char *p = &str[i];
	  return p;                             // Returns pointer
	}
    }
  char *p = &str[0];
  return p;
}

char *word_terminator(char *str){
                                                        // Checks until next space or new line
  for(int i = 0; i >=0;i++) {
      if(non_space_char(str[i])) {
	if(space_char(str[i+1]) || str[i+1] == '\n') {
	  char *p = &str[i];
	  return p;
      }
    }
  }
}
  
int count_words(char *str)
{
  int i = 0;
  int numWords= 0;
  char iterator;
  
  while ((iterator = *str++) != '\0') {
    if (non_space_char(iterator)) {
      if(i == 0 && iterator != '\n') {
	  numWords++;
	  i = 1;
	}
      }
    else {
	i = 0;
      }
    }
  return numWords;
}

char *copy_str(char *inStr, short len)
{
  char *ptr = (char*) malloc (len+1);
  for(int i = 0; i <= len; i++) {
      ptr[i] = inStr[i];
    }
  ptr[len+1] = '\0';
  return ptr;
}

void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != 0) {
    printf("%s\n", tokens[i]); // Prints all strings
      i++;
    }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != 0) {      // Goes through every token
    free(tokens[i]);           // Freeing while progressing
    i++;
  }
  free(tokens[i+1]);           // Free the zero terminator  
  free(tokens);                // Then the token itself
}

//Accepts a string and tokenizes it.
 char** tokenize(char* str){

   int numWords = count_words(str);
   //Malloc-ing tokens double-pointer.
   char **tokens = (char**)malloc((numWords+1)*sizeof(char*));

   //For every word, find the start and end of word.
   for(int i = 0; i < numWords; i++){
     char *wStart = word_start(str);
     char *wEnd = word_terminator(str);
     char *temp = wStart;
     int length = 0;
     //Finding the length of the word
     while(temp != wEnd){
       temp++;
       length++;
     }
     //Copying the word into tokens at index i.
     tokens[i] = copy_str(wStart,length);
     str = wEnd+1;
   }
   //The final index is reserved for the zero terminator.
   tokens[numWords+1] = '\0';
   return tokens;
 }
