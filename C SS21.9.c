#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
	int ID;
	char title[50];
	char author[50];
	float price;
	char genre[30];
};

void inputBook(struct Book *b) {
	printf("Nhap ma sach: ");
	scanf("%d", &b->ID);
	getchar();
	
	printf("Nhap ten sach: ");
	fgets(b->title,50,stdin);
	b->title[strcspn(b->title, "\n")] = 0;
	
	printf("Nhap tac gia: ");
    fgets(b->author, 50, stdin);
    b->author[strcspn(b->author, "\n")] = 0;

	printf("Nhap gia tien: ");
    scanf("%f", &b->price);
    getchar();
	
	printf("Nhap the loai: ");
    fgets(b->genre, 30, stdin);
    b->genre[strcspn(b->genre, "\n")] = 0;
}

void saveBook(struct Book books[], int n) {
	FILE *outFile = fopen("books.txt", "wb");

    if (outFile == NULL) {
        printf("Khong the mo file da luu!\n");
        return;
    }

    fwrite(books, sizeof(struct Book), n, outFile);
    fclose(outFile);
    printf("Thong tin sach da duoc luu vao file.\n");
}

void loadBooks(struct Book books[], int *n) {
    FILE *inFile = fopen("books.txt", "rb");

    if (inFile == NULL) {
        printf("Khong the mo file da doc!\n");
        return;
    }

    *n = fread(books, sizeof(struct Book), 100, inFile);
    fclose(inFile);
    printf("Thong tin sach da duoc lay tu file.\n");
}

void displayBooks(struct Book books[], int n) {
    if (n == 0) {
        printf("Chua co sach nao trong danh sach!\n");
        return;
    }

    printf("\nDanh sach sach:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma sach: %d\n", books[i].ID);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].genre);
        printf("----------------------------\n");
    }
}

int main() {
	struct Book books[100];
	int n=0;
	int choice;
	
	do {
		printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
        	case 1:
        		printf("Nhap so luong sách: ");
                scanf("%d", &n);
                getchar(); 

                for (int i = 0; i < n; i++) {
                    printf("Nhap thông tin cho sach thu %d:\n", i + 1);
                    inputBook(&books[i]);
                }
        		break;
        	case 2:
        		saveBook(books, n);
        		break;
        	case 3:
        		loadBooks(books, &n);
        		break;
        	case 4:
        		displayBooks(books, n);
        		break;
        	case 5:
        		printf("Thoat chuong trinh.\n");
        		break;
		}
	} while (choice!=5);
	
	return 0;
}

