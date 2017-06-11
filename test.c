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

  l = makeEmptyList(l, comparator); 

  insert((ElementType)&b1, l, first(l));
  insert((ElementType)&b2, l, first(l));
  insert((ElementType)&b3, l, first(l));
  insert((ElementType)&b4, l, first(l));
  insert((ElementType)&b5, l, first(l));
  
  Position p = header(l);
  Box *b = NULL;

  while((p = advance(p, l)) && !isLast(p, l)){
   b = (Box *)retrieve(p); 
   printBox(b);
  }

  deleteList(l);
  return EXIT_SUCCESS;
}
