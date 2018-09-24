#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "../list.h"

int compareStudent(student_info *s1, student_info *s2)
{
  if(strcmp(s1->bio->first_name, s2->bio->first_name) && 
     strcmp(s1->bio->last_name, s2->bio->last_name))
  {
    return 0;  
  }

  return 1;
}

void print_function(void *element, void *args)
{
  (void)args; /* Suppress unused warning */
  print_student((student_info *)element);
}

void free_function(void *element)
{
  student_info *s = (student_info *)element;
  free(s->bio);
  free(s->uni_info);
  free(s);
}

int comparator(const void *e1, const void *e2)
{
  student_info *student1 = (student_info*)e1;
  student_info *student2 = (student_info*)e2;

  return compareStudent(student1, student2);
}

int main()
{
  bio_info *bioInfo1 = create_bio_info("John", "Adams", 17); 
  bio_info *bioInfo2 = create_bio_info("Mary", "Benn", 19); 
  bio_info *bioInfo3 = create_bio_info("Dionne", "Harris", 22); 
  bio_info *bioInfo4 = create_bio_info("Emmerson", "Campbell", 18); 

  university_info *uniInfo1 = create_university_info("Computer Science", 1, 3.0);
  university_info *uniInfo2 = create_university_info("Chemistry", 4, 2.9);
  university_info *uniInfo3 = create_university_info("Biology", 2, 3.8);
  university_info *uniInfo4 = create_university_info("Social Work", 2, 3.2);

  student_info *student1 = create_student(bioInfo1, uniInfo1);
  student_info *student2 = create_student(bioInfo2, uniInfo2);
  student_info *student3 = create_student(bioInfo3, uniInfo3);
  student_info *student4 = create_student(bioInfo4, uniInfo4);

  List l = NULL;

  l = LST_makeEmptyList(l, comparator);

  LST_insert((void *)student1, l, LST_last(l));
  LST_insert((void *)student2, l, LST_last(l));
  LST_insert((void *)student3, l, LST_last(l));
  LST_insert((void *)student4, l, LST_last(l));

  LST_traverse(l, print_function, NULL);

  LST_deleteList(l, free_function);
  l = NULL;

  return EXIT_SUCCESS;
}
