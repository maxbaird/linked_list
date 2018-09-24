#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

static void print_bio_info(bio_info *info)
{
  fprintf(stdout, "First name: %s\n", info->first_name);
  fprintf(stdout, "Last name: %s\n", info->last_name);
  fprintf(stdout, "Age: %d\n", info->age);
}

static void print_university_info(university_info *info)
{
  fprintf(stdout, "Programme: %s\n", info->programme);
  fprintf(stdout, "Year: %d\n", info->year);
  fprintf(stdout, "GPA: %f\n", info->gpa);
}

bio_info *create_bio_info(char *first_name, char *last_name, int age)
{
  bio_info *b_info = malloc(sizeof(bio_info));

  if(b_info == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for bio data!\n");
    exit(EXIT_FAILURE);
  }

  b_info->first_name = first_name;
  b_info->last_name = last_name;
  b_info->age = age;

  return b_info;
}

university_info *create_university_info(char *prog, int year, float gpa)
{
  university_info *uni_info = malloc(sizeof(university_info));

  if(uni_info == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for university data!\n");
    exit(EXIT_FAILURE);
  }

  uni_info->programme = prog;
  uni_info->year = year;
  uni_info->gpa = gpa;

  return uni_info;
}

student_info *create_student(bio_info *b_info, university_info *uni_info)
{
  student_info *student = malloc(sizeof(student_info));

  if(student == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for student data!\n");
    exit(EXIT_FAILURE);
  }

  student->bio = b_info;
  student->uni_info = uni_info;

  return student;
}

void print_student(student_info *info)
{
  print_bio_info(info->bio);
  print_university_info(info->uni_info);
}
