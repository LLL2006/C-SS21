#include<stdio.h>

int main() {
	FILE *fptr;
	char myText[100];
	
	fptr = fopen("bt01.txt","w");
	
	printf("Nhap mot chuoi bat ki: ");
    fgets(myText, 100, stdin);
    
    fprintf(fptr, "%s", myText);
    
    fclose(fptr);
    
    fptr = fopen("bt01.txt", "r");
    
    char firstChar = fgetc(fptr);
    
    printf("Ky tu dau tien trong file bt01.txt la: '%c'\n", firstChar);

	rewind(fptr);
	printf("Dòng d?u tiên trong file bt01.txt là: %s", myText);
	
	fclose(fptr);
	
	fptr = fopen("bt01.txt", "a");
	
	printf("Nhap mot chuoi de ghi them vao file: ");
    fgets(myText, 100, stdin);
    
    fprintf(fptr, "%s", myText);

    fclose(fptr);
    
	return 0;
}

