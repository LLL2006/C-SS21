#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int age;
} Student;

int main() {
    FILE *fptr;
    Student students[100];
    int count = 0;

    fptr = fopen("students.txt", "r");

    while (fscanf(fptr, "%d, %99[^,], %d\n", &students[count].id, students[count].name, &students[count].age) == 3) {
        count++;
    }

    fclose(fptr);

    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", students[i].id, students[i].name, students[i].age);
    }

    return 0;
}
