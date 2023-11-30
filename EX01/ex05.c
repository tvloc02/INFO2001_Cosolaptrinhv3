#include <stdio.h>
#include <time.h>

void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int arr[], int n) 
{
    for (i = 0; i < (n-1); i++)
        for (j = 0; j < (n-i-1); j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}
void selectionSort(int arr[], int n) 
{
    int i, j, min_idx;
    for (i = 0; i < (n-1); i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int arr[10];
    int i;

   
    printf("Nhap gia tri cho cac phan tu trong mang:\n");
    for (i = 0; i < 10; i++) {
        printf("Nhap gia tri cho phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

   
    printf("\nMang vua nhap:\n");
    for (i = 0; i < 10; i++)
	{
        printf("%d ", arr[i]);
    }

    clock_t start_bubble = clock();
    bubbleSort(arr, 10);
    clock_t end_bubble = clock();
    printf("\nMang sau khi sap xep:\n");
    for (i = 0; i < 10; i++)
	{
        printf("%d ", arr[i]);
    }
    printf("\nThoi gian de sap xep: %f giay\n"((double)end_bubble - start_bubble) / CLOCKS_PER_SEC);

    printf("\nKhoi phuc mang ve trang thai ban dau:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    clock_t start_selection = clock();
    selectionSort(arr, 10);
    clock_t end_selection = clock();
    printf("\nMang sau khi sap xep:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nThoi gian de lua chon: %f giay\n", ((double)end_selection - start_selection) / CLOCKS_PER_SEC);

    return 0;
}

