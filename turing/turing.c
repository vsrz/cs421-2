// turing.c

// By Jeremy Villegas
// Programming Asssignment Project 2
// 12/10/2008 FALL 08

/*****************************************************************************
* Task: Design and implement a program to simulate a Turing Machine that 
* computes the successor function. That is, given a positive integer n as 
* input it returns the integer n + 1 as output.
*
* Input to the Turing machine: A positive integer represented as a string of
* 0's followed by a B. For example, the positive integer 7 is represented as 
* the string "0000000B".
*
* Output: Display each of the moves that your Turing machine goes through to 
* compute the successor function.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#define MIN_STR_SIZE 1
#define MAX_STR_SIZE 128

static void pwd_error(char*);

int main()
{
  char ch, s[MAX_STR_SIZE+1];
  int x=0,y=0,z=0;
  printf("Enter input string: ");
  while((ch = (char)getchar()) != '\n'){
    if((int)ch != 48) pwd_error("String may contain only 0's.");
    else s[x++]=ch;
  }
  // Is the string too short?
  if(x<MIN_STR_SIZE) pwd_error("String must contain at least one 0.");
  s[x++]='B';
  s[x++]='\n';
  // Iterate through each 0
  for(y=0;y<x;y++) {
    for(z=0;z<x+1;z++){
      if(z==y)printf("|q0|");
      printf("%c",s[z]);
    } 
    // If you find the last B, convert it to a zero
    if(s[y]=='B')s[y]='0';
  }
  return(0);

} // end of int main()

void pwd_error(char* s){
  printf("ERROR: %s\n",s);
  exit(EXIT_FAILURE);
}
 
