#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int low, int high){
    int temp = 0;
    temp = a[high];
    a[high] = a[low];
    a[low] = temp;
}

int part(int a[], int low, int high){
    int base = a[low];
    while (low < high){
        while(low < high && a[high] >= base){
            high--;
        }
        swap(a, low, high);
        while(low < high && a[low] <= base){
            low++;
        }
        swap(a, low, high);
    }
    return low;
}

void quickSort(int a[], int low, int high){
    if(low < high){
        int base = part(a, low, high);
        quickSort(a, low, base - 1);
        quickSort(a, base + 1, high);
    }
}

int howTo(const void * _a,const void * _b){
    int* a = (int*)_a;
    int* b = (int*)_b;
    return *a - *b;
}

int main(){
    int n = 0;
    void quickSort(int a[n], int low, int high);
    printf("How many numbers do you want to sort?: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    //quickSort(a, 0, n - 1);
    qsort(a, n, sizeof(a[0]), howTo);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}