#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char input[100];
  char input2[100];
  List* history = init_history();
  add_history(history, "hello world");
  add_history(history, "a b c ");
  
  while(1) {
    printf("Choose the following:\n");
    printf("1. Input '1' to input\n");
    printf("2. Input '2' to view history\n");
    printf("3. Input '!' followed by a number to recall history\n");
    printf("4. Input '3' to exit\n");
    printf(">");
    fgets(input, 100, stdin);

    if (input[0] == '1') {
      printf("Enter sentence:\n>");
      fgets(input2, 100, stdin);
      char **tokens = tokenize(input2);
      print_tokens(tokens);
      add_history(history, input2);
      free_tokens(tokens);
    }
    else if (input[0] == '2') {
      print_history(history);
    }

    else if (input[0] == '!') {
      int id = atoi(input +1);
      printf("\n%s\n", get_history(history, id));

    }
    else if (input[0] == '3') {
      printf("End of program\n");
      free_history(history);
      return 0;
    }
  }
}
