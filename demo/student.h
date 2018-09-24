#ifndef __STUDENT_H__
#define __STUDENT_H__

typedef struct{
  char *first_name;
  char *last_name;
  int age;
}bio_info;

typedef struct{
  char *programme;
  int year;
  float gpa;
}university_info;

typedef struct{
  bio_info *bio; 
  university_info *uni_info;
}student_info;

bio_info *create_bio_info(char *first_name, char *last_name,  int age);
university_info *create_university_info(char *prog, int year, float gpa);
student_info *create_student(bio_info *b_info, university_info *uni_info);
void print_student(student_info *info);

#endif /* __STUDENT_H__ */
