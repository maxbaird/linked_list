#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define UNUSED(x) (void)(x)

typedef struct{
  int h;
  int w;
  int d;
}Box;

int get_volume(Box *b){
  return (b->h * b->w * b->d);
}

int comparator(const void *e1, const void *e2){
  Box *b1 = (Box *)e1;
  Box *b2 = (Box *)e2;
 
  return (get_volume(b1) == get_volume(b2)) ? 0 : -1;
}

void printBox(Box *b){
  printf("\nb->h: %d\n"
         "b->w: %d\n"
         "b->d: %d\n\n",
         b->h,
         b->w,
         b->d);
}

static void *printFun(void * e, void *args)
{
  UNUSED(args); 
  printBox((Box *)e);
  return NULL;
}

int main(){
  Box b1 = {1,1,1};
  Box b2 = {2,2,2};
  Box b3 = {3,3,3};
  Box b4 = {4,4,4};
  Box b5 = {5,5,5};

  List l = NULL;

  l = LST_makeEmptyList(l, comparator); 

  LST_insert((void *)&b1, l, LST_first(l));
  LST_insert((void *)&b2, l, LST_first(l));
  LST_insert((void *)&b3, l, LST_first(l));
  LST_insert((void *)&b4, l, LST_first(l));
  LST_insert((void *)&b5, l, LST_first(l));
  
  LST_traverse(l, printFun, NULL);
  
  LST_deleteNode((void *)&b4, l);

  fprintf(stdout, "List again\n");
  LST_traverse(l, printFun, NULL);

  LST_deleteList(l);
  l = NULL;

  return EXIT_SUCCESS;
}
