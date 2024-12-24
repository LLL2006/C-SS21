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

	fclose(fptr);
	
	return 0;
}

