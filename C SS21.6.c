#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1, *fptr2;
    char myText[100];

    fptr1 = fopen("bt01.txt", "r");

    fptr2 = fopen("bt06.txt", "w");
    
    while (fgets(myText, 100, fptr1) != NULL) {
        fputs(myText, fptr2);
    }

    printf("Da sao chep noi dung thanh cong.\n");

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}

