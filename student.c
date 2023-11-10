#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "student.h"

Student **pStudent = NULL;
int studentNum = 0;

Student *createStudent(const char *name) {
    Student **temp = (Student **) realloc(pStudent, (studentNum + 1) * sizeof(Student *));
    if (!temp) {
        return NULL;
    }
    pStudent = temp;

    Student *student = (Student *) malloc(sizeof(Student));
    if (student) {
        student->obj.ref_count = 1;
        student->name = strdup(name);  // string.h
    }
    pStudent[studentNum++] = student;
    return student;
}

Class *createClass(const char *class_name) {
    Class *class = (Class *) malloc(sizeof(Class));
    if (class) {
        class->obj.ref_count = 1;
        class->class_name = strdup(class_name); // string.h
        class->pStudents = NULL;
        class->num_students = 0;
        printf("new Class: %s\n", class_name);
    }
    return class;
}

void retainStudent(Student *student) {
    printf("Add reference count of Studnet(%s)\n", student->name);
    if (student) {
        student->obj.ref_count++;
    }
}

void releaseStudent(Student *student) {
    printf("Reduce reference count of Student(%s)\n", student->name);
    if (student && --student->obj.ref_count == 0) {
        free(student->name);
        free(student);
    }
}

void retainClass(Class *class) {
    if (class) {
        class->obj.ref_count++;
    }
}

void releaseClass(Class *class) {
    if (class && --class->obj.ref_count == 0) {
        free(class->class_name);
        for (int i = 0; i < class->num_students; i++) {
            releaseStudent(class->pStudents[i]);
        }
        free(class->pStudents);
        free(class);
        printf("Release class\n");
    }
}

void addStudentToClass(Class *class, Student *student) {
    retainStudent(student);
    Student **temp = (Student **) realloc(class->pStudents, (class->num_students + 1) * sizeof(Student *));
    if (temp == NULL) {
        fprintf(stderr, "Error reallocating memory\n");
        releaseStudent(student);
    } else {
        class->pStudents = temp;
        class->pStudents[class->num_students] = student;
        class->num_students++;
    }
}

void releaseAllStudents() {
    for (int i= 0; i < studentNum; i++ ){
        Student* student = pStudent[i];
        if (student) {
            free(student);
            printf("Release student%d\n", i + 1);
        }
    }
}