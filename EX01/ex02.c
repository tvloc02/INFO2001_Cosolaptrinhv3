#include <stdio.h>
#include <string.h>

struct Student {
    char id[10];
    char name[50];
    int age;
    float gpa;
};

void initStudents(struct Student students[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Nhap ten: ");
        fflush(stdin); 
        fgets(students[i].name, sizeof(students[i].name), stdin);
        strtok(students[i].name, "\n"); 
        printf("Nhap ma so: ");
        scanf("%s", students[i].id);
        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);
        printf("Nhap diem: ");
        scanf("%f", &students[i].gpa);
        printf("\n");
    }
}

int main() {
    struct Student students[50];
    int choice;

    do {
        printf("CHUONG TRINH QUAN LY SINH VIEN\n");
        printf("1. Khoi tao danh sach\n");
        printf("2. Them moi mot sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Sap xep danh sach\n");
        printf("5. Tim kiem thong tin sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("Lua chon cua ban la gi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong sinh vien: ");
                int size;
                scanf("%d", &size);
                initStudents(students, size);
                break;


            case 0:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

    } while (choice != 0);

    return 0;
}
