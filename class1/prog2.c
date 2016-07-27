#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _DOB {
  int day;
  int month;
  int year;
} DOB;

typedef struct _StudentInfo {
  int roll_no;
  char name[50];
  float cgpa;
  DOB age;
} StudentInfo;

void s_Display(StudentInfo *s) {
  printf("%d %s %f\n", s->roll_no, s->name, s->cgpa);
  printf("DOB: %d/%d/%d\n", s->age.day, s->age.month, s->age.year);
}

int main(int argc, char *argv[]) {
  StudentInfo si;
  si.roll_no = 1405109;
  strcpy(si.name, "Aviral Dasgupta");
  si.cgpa = 8.0;
  DOB dob;
  dob.day = 2;
  dob.month = 9;
  dob.year = 1996;
  si.age = dob;
  s_Display(&si);  
  return EXIT_SUCCESS;
}

