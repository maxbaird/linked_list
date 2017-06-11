#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

#define FATAL_ERROR(MSG)            \
  do{                               \
    fprintf(stderr, "%s\n", MSG);   \
    exit(EXIT_FAILURE);             \
  }while(0);

#define UNUSED(x) (void)(x)

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef void* ElementType;
typedef int (*Comparator)(const void*, const void*);

struct Node{
       ElementType element;
       Position next;
};

Comparator element_comparator; /* Used to store a reference to a callback function to compare elements */

List makeEmptyList(List l, Comparator c);
int isEmpty(List l);
int isLast(Position p, List l);
Position find(ElementType e, List l);
void deleteNode(ElementType e, List l);
Position findPrevious(ElementType e, List l);
void insert(ElementType element, List l, Position p);
void deleteList(List l);
Position header(List l);
Position first(List l);
Position last(List l);
Position advance(Position p, List l);
ElementType retrieve(Position p);

#endif
