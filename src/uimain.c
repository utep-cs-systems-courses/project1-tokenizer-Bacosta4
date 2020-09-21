#include <stdio.h>
#include <tokenizer.h>

//Simple ui
int main()
{
  printf("Hello user.")
  char input[100];
  printf(">");
  fgets(input, 100, stdin);
  printf("%s", input);
}
