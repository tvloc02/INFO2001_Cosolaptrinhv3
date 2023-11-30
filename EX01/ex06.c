include <stdio.h>
#include <string.h>

struct Student 
{
    char name[50];
    char id[10];
    int age;
    float gpa;
};

void displayStudent(struct Student s) {
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s", s.name);
    printf("Ma so: %s\n", s.id);
    printf("Tuoi: %d\n", s.age);
    printf("Diem: %.2f\n", s.gpa);
}
void sortStudentsByGrade(struct Student arr[], int n) {
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].gpa > arr[j + 1].gpa) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int searchStudentByName(struct Student arr[], int n, char searchName[]) {
    for (i = 0; i < n; i++) {
        if (strcmp(arr[i].name, searchName) == 0) {
            return i;  
        }
    }
    return -1;  
}
void sortStudentsByName(struct Student arr[], int n) {
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int searchStudentById(struct Student arr[], int n, int searchId) {
    for (i = 0; i < n; i++) {
        if (arr[i].id == searchId) {
            return i;  
        }
    }
    return -1;  
}



int main() {
    struct Student students[3]; 
    char searchName[50];
    int searchId, result;
    for (i = 0; i < 3; i++)
	{
        printf("\nThong tin cho sinh vien thu %d:\n", i + 1);
        printf("Nhap ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        printf("Ma so: ");
        fgets(students[i].id, sizeof(students[i].id), stdin);
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        printf("Diem (gpa): ");
        scanf("%f", &students[i].gpa);
        getchar(); 
    }
    printf("\nThong tin sinh vien truoc khi sap xep:\n");
    for (i = 0; i < 3; i++) {
        displayStudent(students[i]);
    }
    int choice;
    printf("\nChon cach sap xep (1: Theo ten, 2: Theo diem): ");
    scanf("%d", &choice);

    if (choice == 1) {
        sortStudentsByName(students, 3);
    } 
	else if (choice == 2) {
        sortStudentsByGrade(students, 3);
    }

    printf("\nThong tin sinh vien sau khi sap xep:\n");
    for (i = 0; i < 3; i++) {
        displayStudent(students[i]);
    }

    printf("\nNhap ten sinh vien can tim kiem: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 
    result = searchStudentByName(students, 3, searchName);
    if (result != -1) {
        printf("Tim thay sinh vien tai vi tri %d \n", result);
    } 
	else {
        printf("Khong tim thay sinh vien co ten \"%s\"\n", searchName);
    }

    printf("\nNhap ma so sinh vien can tim kiem: ");
    scanf("%s", &searchId);
    result = searchStudentById(students, 3, searchId);
    if (result != -1) {
        printf("Tim thay sinh vien tai vi tri %d\n", result);
    } 
	else {
        printf("Khong tim thay sinh vien co ma so %s\n", searchId);
    }

    return 0;
}
