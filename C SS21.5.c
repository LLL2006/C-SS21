#include<stdio.h>

int main() {
	FILE *fptr;
	char myText[100];
	int numLines;
	
	fptr=fopen("bt05.txt","w");
	
	printf("Nhap so dong can ghi vao file: ");
	scanf("%d",&numLines);
	getchar();
	
	for(int i=0; i<numLines; i++){
		printf("Nhap noi dung dong %d: ",i+1);
		fgets(myText, 100, stdin);
		fprintf(fptr, "%s", myText);
	}
	
	fclose(fptr);
	fptr=fopen("bt05.txt","r");
	
	while (fgets(myText, 100, fptr) != NULL) {
        printf("%s", myText);
    }
    
    fclose(fptr);
    
	return 0;
}

