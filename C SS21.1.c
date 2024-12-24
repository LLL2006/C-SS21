#include<stdio.h>

int main() {
	FILE *fptr;
	char myText[100];
	
	fptr = fopen("bt01.txt","w");
	
	printf("Nhap mot chuoi bat ky: ");
	fgets(myText,100,stdin);
	
	fprintf(fptr, "%s", myText);
	
	fclose(fptr);
	
	return 0;
}

