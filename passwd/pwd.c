// passwd.c

// By Jeremy Villegas
// Programming Asssignment Extra Credit
// 12/10/2008 FALL 08

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <iostream>
#include <vector>
#define MIN_STR_SIZE 3
#define MAX_STR_SIZE 128


static void pwd_error(char*);

int main()
{
  char ch, passwd[MAX_STR_SIZE+1];
  char regular_exp[MAX_STR_SIZE+1];
  char tok1[MAX_STR_SIZE],tok2[MAX_STR_SIZE],tok3[MAX_STR_SIZE];
  bool st_flag=false;
  int x=0,y=0,tok_cnt=0;
  printf("Enter regular expression: ");
  std::cin.getline(regular_exp,MAX_STR_SIZE,'\n');
  printf("Your string: %s\n", regular_exp);
  for(x=0;x<strlen(regular_exp);x++){
    if(regular_exp[x]=='('){
      ++tok_cnt;
      if(tok_cnt==1){
        y=0;
        while(regular_exp[x++]!=')'){
          tok1[y]=regular_exp[x];
          y++;
        }
      }
    }
  }
  printf("tok1: %s",tok1);
  return(0);

} // end of int main()

void pwd_error(char* s){
  printf("ERROR: %s\n",s);
  exit(EXIT_FAILURE);
}
 
