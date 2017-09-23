#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define FATAL_ERROR(MSG)            \
  do{                               \
    fprintf(stderr, "%s\n", MSG);   \
    exit(EXIT_FAILURE);             \
  }while(0);

#define UNUSED(x) (void)(x)

/* Safely frees memory to avoid dangling pointers
 *
 * @param ptr A reference to the memory to be freed
 */
static void safeFree (void **ptr)
{
  if (ptr != NULL && *ptr != NULL)
  {
    free (*ptr);
    *ptr = NULL;
  }
}

/* Creates an empty list.
 *
 * This function first determines if the list has already been initialized
 * and removes it if so. The members of this first node are initialized to
 * NULL. The element memeber is of type void* and is thus generic/type 
 * independent.
 *
 * @param   l The address of the list to be created.
 * @param   c A function pointer to a function to be used for comparing elements of the list.
 *            This function must accept const references to two elements and return an integer
 *            0 value if they're equal and a non-zero value otherwise.
 * @return  Returns a reference to the created list. If creation was unsuccessful an error
 *          message is printed followed by an exit.
 *
 */
List LST_makeEmptyList(List l, Comparator c){
     if(l != NULL){
          LST_deleteList(l); /* Remove existing nodes from list, if any */
     }
     l = (struct Node *)malloc(sizeof(struct Node));
     
     if(l == NULL){
          FATAL_ERROR("Out of memory!!\n");
     }
          
     l->element = NULL;
     l->next = NULL;
     l->comparator = c;
     
     return l;
}

/* Determines if a list is empty.
 *
 * @param   l A reference to the list to be checked.
 * @return  Returns a non-zero value if l is not null. Returns 0 otherwise.
 */
int LST_isEmpty(List l){
    return l->next == NULL;
}

/* Determines if a position in the list is the last node.
 *
 * @param   p A reference to the position in the list to be checked.
 * @param   l The list which contains the position.
 * @return  Returns a non-zero value if p is the last element. Returns 0 otherwise.
 */
int LST_isLast(Position p, List l){
    UNUSED(l);
    return p->next == NULL;
}

/* Determines the position of an element in the list.
 *
 * This function utilizes the comparator function specified at list creation
 * in order to determine equality and therefore depends on said function to 
 * perform an equality test.
 *
 * @param   e The element to be searched for within the list.
 * @param   l The list to be traversed.
 * @return  Returns the Position of e in l; Null if not found.   
 */
Position LST_find(void *element, List l){
         Position p;
         
         p = l->next;
         while(p != NULL && l->comparator(p->element, element) != 0)
                 p = p->next;
         
         return p;
}

/* Deletes the first occurence of e from a list.
 *
 * @param   e The element to be removed from the list.
 * @param   l The list to be traversed for e.
 */
void LST_deleteNode(void *element, List l){
     Position p, tempCell;
     
     p = LST_findPrevious(element, l);
     
     if(!LST_isLast(p, l)){
         tempCell = p->next;
         p->next = tempCell->next;
         safeFree((void **)&tempCell);
     }
}

/* Finds the previous node of first node matching element type e.
 * Assumes a header.
 *
 * @param   e The element to be searched for.
 * @param   l The list to be traversed for e.
 * @return  Returns the node behind the node containing the first match
 *          of e. If e is not found, then the next field of returned value
 *          is NULL. 
 */
Position LST_findPrevious(void *element, List l){
     Position p;
     
     p = l;
     while(p->next != NULL && l->comparator(p->next->element, element) != 0)
          p = p->next;
     
     return p;         
}

/* Insert (after legal position p), header impelementation assumed.
 * Parameter l is unused in this implementation.
 *
 * @param   e Used to initialize the value of the node's element.
 * @param   p The position of which to perform the insertion.
 */
void LST_insert(void *element, List l, Position p)
{
     UNUSED(l);
     Position tempCell;
     
     tempCell = (struct Node *)malloc(sizeof(struct Node)); 
     if(tempCell == NULL){
         FATAL_ERROR("Out of space!!!");
     }
       
     tempCell->element = element;
     tempCell->next = p->next;
     tempCell->comparator = NULL;
     p->next = tempCell;
}

/* Locates the header of a list l.
 *
 * @param   l The list who's header will be returned.
 * @return  Returns the header of list l.
 */
Position LST_header(List l){
  return l;
}

/* Finds the position of the first node in l.
 *
 * @param   l The list used to locate the position of it's first node.
 * @return  Returns the position of l's first node.
 */
Position LST_first(List l){
     Position p;
     p =(LST_isEmpty(l)) ? l : l->next;
     return p;
}

/* Finds the position of the last node in l.
 *
 * @param   l The list used to locate the position of it's last node.
 * @return  Returns the position of l's last node.
 */
Position LST_last(List l){
      Position p;
      p = l;
      
      while(p->next != NULL)
            p = p->next;
      
      return p;
}

/* Advances one step ahead of position p.
 *
 * @param   p The current position from which to advance.
 * @param   l The list used to advance to the next position ahead of p.
 * @return  Returns the node ahead of position p. If p is the last node
 *          then p is returned.
 */
Position LST_advance(Position p, List l){
    if(LST_isLast(p, l)){
       return p;
    }
    else{
       return p->next;
    }
}

/* Frees every node of list l.
 *
 * @param   l The list to be deleted. 
 */
void LST_deleteList(List l){
     Position p, temp;
     p = l->next; /* Header assumed */
     
     l->next = NULL;
     l->comparator = NULL;
     
     while(p != NULL){
             temp = p->next;
             safeFree((void **)&p);
             p = temp;
     }

     /* Finally, free the head of the list */
     safeFree((void **)&l);
}

/* Retrives element from node at specified position.
 *
 * @param   p The position of the node from which the element should be returned.
 * @return  The element found at position p.
 */
void *LST_retrieve(Position p){
            return p->element;
}

/* Traverses the list and applies a function with arguments to 
 * each element.
 *
 * @param   l The list to traverse
 * @param   f The function to apply to each element
 * @param   args The arguments to pass to f
 */
void LST_traverse(List l, LST_traverse_fun f, void *args)
{
  Position p = LST_header(l);
  void *element  = NULL;

  while((p = LST_advance(p, l)) && !LST_isLast(p, l))
  {
    element = LST_retrieve(p);
    f(element, args);
  }

  element = LST_retrieve(LST_last(l));
  f(element, args);
}
