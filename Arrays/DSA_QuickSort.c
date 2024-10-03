#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high]; // ch?n ph?n t? cu?i c?ng l?m pivot
    int i = low - 1; // v? tr? c?a ph?n t? nh? h?n pivot

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]); // ho?n ??i n?u ph?n t? nh? h?n ho?c b?ng pivot
        }
    }
    swap(&array[i + 1], &array[high]); // ho?n ??i pivot v? ??ng v? tr?
    return i + 1; // tr? v? ch? s? c?a pivot
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high); // ph?n chia m?ng
        quicksort(array, low, pivot_index - 1);  // ?? quy s?p x?p ph?n b?n tr?i c?a pivot
        quicksort(array, pivot_index + 1, high); // ?? quy s?p x?p ph?n b?n ph?i c?a pivot
    }
}

int main() {
    int my_array[] = {64, 3, 2, 12, 22, 11, 90, 5};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    quicksort(my_array, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    return 0;
}
