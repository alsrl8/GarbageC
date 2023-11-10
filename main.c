#include <stdio.h>

#include "student.h"

void run() {
    Class *cls = createClass("My Class");
    char studentName[50];

    for (int i = 0; i < 10; i++) {
        sprintf(studentName, "My Student%d", i + 1);
        Student *student = createStudent(studentName);
        if (student) {
            printf("new student: %s\n", studentName);
        } else {
            printf("Failed to make new student\n");
        }
        addStudentToClass(cls, student);
        releaseStudent(student);
    }

    releaseClass(cls);
}

int main() {
    run();
}