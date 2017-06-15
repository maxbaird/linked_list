#ifndef __LIST_H__
#define __LIST_H__

#ifdef __cpusplus
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

#ifdef __cpusplus
}
#endif

#endif /* Include Guard */
