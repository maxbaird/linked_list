#ifndef __LIST_H__
#define __LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* Include Guard */
