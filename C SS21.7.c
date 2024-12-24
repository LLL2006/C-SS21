#include <stdio.h>

typedef struct {
    int id;
    char name[100];
    int age;
} Student;

int main() {
    FILE *fptr;
    int numStudents;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numStudents);
    getchar();

    Student *students = (Student *)malloc(numStudents * sizeof(Student));
    
    for (int i = 0; i < numStudents; i++) {
        printf("Nhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        getchar(); 

        printf("Ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0';
        }

        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        getchar();
    }

    fptr = fopen("students.txt", "w");

    for (int i = 0; i < numStudents; i++) {
        fprintf(fptr, "%d, %s, %d\n", students[i].id, students[i].name, students[i].age);
    }

    printf("Thong tin sinh vien da duoc ghi thanh cong.\n");

    fclose(fptr);
    free(students);

    return 0;
}

