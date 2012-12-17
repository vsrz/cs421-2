#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define FILE_INPUT	"sequence.txt"
#define MAX_LANG_LENGTH	128

struct pstack{
  char element;
  struct pstack *next;
};

struct pstack *pcreate(struct pstack*);
struct pstack *premove(struct pstack*);

#ifdef DEBUG
void print(struct pstack*);
#endif

int main(int argc,char* argv[]){
  FILE *fp;
  int x=0;
  char buff[MAX_LANG_LENGTH],ch;
  struct pstack *p;

  // Attempt to open the file
  if((fp=fopen(FILE_INPUT,"r"))==NULL){
    perror(FILE_INPUT);
    exit(1);
  }

  // Read the grammar into a buffer
  fgets(buff,MAX_LANG_LENGTH,fp);
  printf("Contents of the file: %s\n",buff);

  // Initalize the stack
  p=malloc(sizeof(struct pstack));
  p->next=NULL;
  p->element='Z';

  // iterate through the grammar
  while(buff[x]!='\0'){
    switch(buff[x]){
      case 'i':
        p=pcreate(p);
        break;
      case 'e':
        p=premove(p);
        break;
    }
    x++;
  }
  // check to see if we had an "else" for every "if"
  if(p->element=='Z')
    printf("Sequence is syntactically correct\n");
  else
    printf("Incorrect sequence\n");
  return(0);
}

struct pstack *premove(struct pstack *p){
  // Remove an item from the stack and do a check.
  if(p->next==NULL){
    printf("Incorrect sequence\n");
    exit(1);
  }
  return(p->next);
}

struct pstack *pcreate(struct pstack *p){
  struct pstack *new;

  // Add an "if" to the stack
  new=malloc(sizeof(struct pstack));
  new->element='i';
  new->next=p;
  return(new); 
}
  
#ifdef DEBUG
void print(struct pstack *p){
  struct pstack *t=p;
  int x=0;
  while(t!=NULL){
    printf("%c, ",t->element);
    t=t->next;
  }
  printf("\n");
}
#endif
