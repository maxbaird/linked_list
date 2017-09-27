#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define UNUSED(x) (void)(x)

typedef struct{
  int h;
  int w;
  int d;
  int *data;
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

void boxCleanup(void *e)
{
  fprintf(stdout, "Calling cleanup\n");
  Box *b = (Box *)e;
  printBox(b);
  free(b->data);
}

static void printFun(void * e, void *args)
{
  UNUSED(args); 
  printBox((Box *)e);
}

int main(){
  int *ptr1 = malloc(1024 * sizeof(int));
  int *ptr2 = malloc(1024 * sizeof(int));
  int *ptr3 = malloc(1024 * sizeof(int));
  int *ptr4 = malloc(1024 * sizeof(int));
  int *ptr5 = malloc(1024 * sizeof(int));

  if(ptr1 == NULL || ptr1 == NULL || ptr1 == NULL || ptr1 == NULL || ptr1 == NULL)
  {
    fprintf(stderr, "Something fucked up\n");
    exit(EXIT_FAILURE);
  }

  Box b1 = {1,1,1, ptr1};
  Box b2 = {2,2,2, ptr2};
  Box b3 = {3,3,3, ptr3};
  Box b4 = {4,4,4, ptr4};
  Box b5 = {5,5,5, ptr5};

  List l = NULL;

  l = LST_makeEmptyList(l, comparator); 

  LST_insert((void *)&b1, l, LST_first(l));
  LST_insert((void *)&b2, l, LST_first(l));
  LST_insert((void *)&b3, l, LST_first(l));
  LST_insert((void *)&b4, l, LST_first(l));
  LST_insert((void *)&b5, l, LST_first(l));
  
  LST_traverse(l, printFun, NULL);
  
  LST_deleteNode((void *)&b4, l, NULL);

  fprintf(stdout, "List again\n");
  LST_traverse(l, printFun, NULL);

  Position p = LST_find((void *)&b5, l);
  Box *aBox = (Box *)LST_retrieve(p);
  fprintf(stdout, "Found box\n");
  printBox(aBox);

  LST_deleteList(l, NULL);
  l = NULL;

  return EXIT_SUCCESS;
}
