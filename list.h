#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef void* ElementType;
typedef int (*Comparator)(const void*, const void*);
typedef void* (*LST_traverse_fun)(ElementType, void *);

struct Node{
       Comparator comparator;
       ElementType element;
       Position next;
};

List LST_makeEmptyList(List l, Comparator c);
int LST_isEmpty(List l);
int LST_isLast(Position p, List l);
Position LST_find(ElementType e, List l);
void LST_deleteNode(ElementType e, List l);
Position LST_findPrevious(ElementType e, List l);
void LST_insert(ElementType element, List l, Position p);
void LST_deleteList(List l);
Position LST_header(List l);
Position LST_first(List l);
Position LST_last(List l);
Position LST_advance(Position p, List l);
ElementType LST_retrieve(Position p);
void LST_traverse(List l, LST_traverse_fun f, void *args);

#ifdef __cplusplus
}
#endif
