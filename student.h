#ifndef GARBAGEC_STUDENT_H
#define GARBAGEC_STUDENT_H

#include "object.h"

typedef struct {
    Object obj;
    char *name;
} Student;

typedef struct {
    Object obj;
    Student **pStudents;
    int num_students;
    char *class_name;
} Class;

extern Student **pStudent;
extern int studentNum;

Student *createStudent(const char *name);

Class *createClass(const char *class_name);

void retainStudent(Student *student);

void releaseStudent(Student *student);

void retainClass(Class *class);

void releaseClass(Class *class);

void addStudentToClass(Class *class, Student *student);

void releaseAllStudents();

#endif //GARBAGEC_STUDENT_H
