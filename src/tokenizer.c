#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c != 0)
    {
      return 1; // True if it contains a tab/ space
    }
      return 0;
}

int non_space_char(char c)
{
  if ((c != '\t' || c != ' ') && c != 0)
    {
      return 1; // True if not a tab/ space
    }
      return 0;
}

char *word_start(char *str)
{
  if (i = 0; *str != 0; = i++)
    {
      if(non_space_char(*str))
	{
	  return 1;
	}
    }
  return *str
}

char *word_terminator(char *word)
{
  if (i = 0; *word != 0; i++)
    {
      if(space_char(*word))
	{
	  return 1;
	}
    }
  return *word;
}

int count_words(char *str)
{
  int count = 0;
  
   
      
