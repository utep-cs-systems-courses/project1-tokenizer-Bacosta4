#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


//Simple ui
int main()
{
  
  printf("Hello User.")
    
  char input[100];

  while(1) {
    
    printf("Please choose an option:\n");
    printf("1. Input 's' to write a sentence\n");
    printf("2. Input 'h' to see all history\n");
    printf("3. Input '!' followed by a number to recall history\n");
    printf("4. Input 'q' to exit\n");

    printf(">");

    fgets(input, 100, stdin);

    switch(input[0])
      {

      case 's':

	printf("Please enter a sentence:\n >");

	break;



      case 'h':


	break;

      case '!':

	break;


      case 'q':

	printf("Thank you for using tokenizerln Goodbye!");

      return 0;

      break;

      default:
	printf("You have choosen an incorrect input.\n Try Again");

      }
  }
  return 0;
}
