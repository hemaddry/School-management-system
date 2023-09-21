#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct Student {
    int id;
    char name[100];
    int age;
} Student;

typedef struct SchoolManagementSystem {
    Student students[MAX_STUDENTS];
    int studentCount;
} SchoolManagementSystem;

void initialize(SchoolManagementSystem *sms) {
    sms->studentCount = 0;
}

void insertStudent(SchoolManagementSystem *sms, int id, const char *name, int age) {
    if (sms->studentCount < MAX_STUDENTS) {
        sms->students[sms->studentCount].id = id;
        strcpy(sms->students[sms->studentCount].name, name);
        sms->students[sms->studentCount].age = age;
        sms->studentCount++;
        printf("Student data inserted successfully.\n");
    } else {
        printf("Maximum student capacity reached. Cannot insert more students.\n");
    }
}

void findStudentById(SchoolManagementSystem *sms, int id) {
    int found = 0;
    for (int i = 0; i < sms->studentCount; i++) {
        if (sms->students[i].id == id) {
            printf("Student found:\n");
            printf("ID: %d\nName: %s\nAge: %d\n", sms->students[i].id, sms->students[i].name, sms->students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void countStudents(SchoolManagementSystem *sms) {
    printf("Total number of students: %d\n", sms->studentCount);
}

void deleteStudent(SchoolManagementSystem *sms, int id) {
    int found = 0;
    for (int i = 0; i < sms->studentCount; i++) {
        if (sms->students[i].id == id) {
            for (int j = i; j < sms->studentCount - 1; j++) {
                sms->students[j] = sms->students[j + 1];
            }
            sms->studentCount--;
            printf("Student with ID %d deleted successfully.\n", id);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found. Deletion failed.\n", id);
    }
}

void updateStudent(SchoolManagementSystem *sms, int id, const char *name, int age) {
    int found = 0;
    for (int i = 0; i < sms->studentCount; i++) {
        if (sms->students[i].id == id) {
            strcpy(sms->students[i].name, name);
            sms->students[i].age = age;
            printf("Student data updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found. Update failed.\n", id);
    }
}

int main() {
    SchoolManagementSystem sms;
    initialize(&sms);

    insertStudent(&sms, 1, "Alice", 18);
    insertStudent(&sms, 2, "Bob", 17);
    insertStudent(&sms, 3, "Charlie", 19);

    countStudents(&sms);

    findStudentById(&sms, 2);

    deleteStudent(&sms, 2);
    countStudents(&sms);

    updateStudent(&sms, 1, "Alice Smith", 19);
    findStudentById(&sms, 1);

    return 0;
}