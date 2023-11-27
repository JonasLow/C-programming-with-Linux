#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);
/* add any other prototypes as needed */

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

struct student *createStudent(char studentName[], int studentAge){
    struct student * first;
    first = (struct student *) malloc(sizeof(struct student));
    strcpy(first->name, studentName);
    first->age = studentAge;
    first->next = NULL;
    
    return first;
}

struct student *append(struct student * end, struct student * newStudptr){
    end->next = newStudptr;
    end = newStudptr;
    return end;
}

void printStudents(struct student *start){
    while (start->next != NULL){
        printf("%s is %d years old.\n", start->name, start->age);
        start = start->next;
    }
    printf("%s is %d years old.\n", start->name, start->age);
}

void freeStudents(struct student *start){
    struct student * tmp;
    while (start->next != NULL){
        tmp = start->next;
        free(start);
        start = tmp;
    }
}