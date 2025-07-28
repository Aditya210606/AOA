#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using Lomuto partition scheme
int partition(int A[], int low, int high) {
    int pivot = A[high];  // pivot element
    int i = low - 1;       // index of smaller element

    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return i + 1;  // return pivot index
}

// Quicksort function
void quicksort(int A[], int low, int high) {
    if (low < high) {
        int q = partition(A, low, high); // partitioning index
        quicksort(A, low, q - 1);        // left sub-array
        quicksort(A, q + 1, high);       // right sub-array
    }
}

// Function to print the array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Main function
int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, n);

    quicksort(A, 0, n - 1);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
