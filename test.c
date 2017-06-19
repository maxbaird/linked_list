#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

int main(){
  Box b1 = {1,1,1};
  Box b2 = {2,2,2};
  Box b3 = {3,3,3};
  Box b4 = {4,4,4};
  Box b5 = {5,5,5};

  List l = NULL;

  l = LST_makeEmptyList(l, comparator); 

  LST_insert((ElementType)&b1, l, LST_first(l));
  LST_insert((ElementType)&b2, l, LST_first(l));
  LST_insert((ElementType)&b3, l, LST_first(l));
  LST_insert((ElementType)&b4, l, LST_first(l));
  LST_insert((ElementType)&b5, l, LST_first(l));
  
  Position p = LST_header(l);
  Box *b = NULL;

  while((p = LST_advance(p, l)) && !LST_isLast(p, l)){
   b = (Box *)LST_retrieve(p); 
   printBox(b);
  }
  
  LST_deleteNode((ElementType)&b4, l);

  fprintf(stdout, "List again\n");
  p = LST_header(l);
  while((p = LST_advance(p, l)) && !LST_isLast(p, l)){
   b = (Box *)LST_retrieve(p); 
   printBox(b);
  }

  LST_deleteList(l);
  l = NULL;

  return EXIT_SUCCESS;
}
