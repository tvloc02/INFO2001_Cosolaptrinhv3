#include <stdio.h>
#include <string.h>

struct Employee 
{
    int employeeId;      
    char name[50];       
    char position[50];   
    float salary;        
};

struct Employee inputEmployee() 
{
    struct Employee e;
    printf("Nhap ma nhan vien: ");
    scanf("%d", &e.employeeId);
    getchar();  
    printf("Nhap ten nhan vien: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0'; 
    printf("Nhap chuc vu: ");
    fgets(e.position, sizeof(e.position), stdin);
    e.position[strcspn(e.position, "\n")] = '\0'; 
    scanf("%f", &e.salary);
    return e;
}

void displayEmployee(struct Employee e) 
{
    printf("\nThong tin nhan vien:\n");
    printf("Ma nhan vien: %d\n", e.employeeId);
    printf("Ten nhan vien: %s\n", e.name);
    printf("Chuc vu trong cong ty: %s\n", e.position);
    printf("Luong hang thang: %.2f\n", e.salary);
}

void addEmployee(struct Employee arr[], int *n)
{
    if (*n < 10) 
    {
        arr[*n] = inputEmployee();
        (*n)++;
        printf("Da them nhan vien thanh cong!\n");
    } else {
        printf("Danh sach nhan vien da day, khong the them nhan vien moi!\n");
    }
}

int deleteEmployee(struct Employee arr[], int *n, int employeeId) 
{
    int found = 0;
    int newCount = 0; 

    for (i = 0; i < *n; i++) {
        if (arr[i].employeeId == employeeId) 
        {
            found = 1;
        } else {
            arr[newCount] = arr[i];
            newCount++;
        }
    }

    if (found)
    {
        (*n)--;
        printf("Da xoa nhan vien co ma nhan vien %d!\n", employeeId);
        return 1; 
    } else {
        printf("Khong tim thay nhan vien co ma nhan vien %d!\n", employeeId);
        return 0;  
    }
}

void sortEmployeesById(struct Employee arr[], int n) 
{
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].employeeId > arr[j + 1].employeeId) 
            {
                struct Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
 int n;
    printf("So luong nhan vien la: ");
    scanf("%d", &n);
    struct Employee employees[n];  
    int employeeCount = 0;  
    addEmployee(employees, &employeeCount);
    for (i = 0; i < employeeCount; i++)
    {
        displayEmployee(employees[i]);
    }
    addEmployee(employees, &employeeCount);
    for (i = 0; i < employeeCount; i++)
    {
        displayEmployee(employees[i]);
    } 
    int employeeIdToDelete;
    printf("Nhap ma NV can xoa: ");
    scanf("%d", &employeeIdToDelete);
    deleteEmployee(employees, &employeeCount, employeeIdToDelete);
    
    for (i = 0; i < employeeCount; i++)
    {
        displayEmployee(employees[i]);
    }
    sortEmployeesById(employees, employeeCount);
    printf("\nDanh sach NV sau khi sap xep theo ma NV:\n");
    for (i = 0; i < employeeCount; i++) 
    {
        displayEmployee(employees[i]);
    }
    return 0;
}
