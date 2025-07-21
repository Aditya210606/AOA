#include <stdio.h>

int binary_search(int A[], int n, int key) {
    int low = 1;
    int high = n = 8;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == key) {
            return mid;  // key found at index mid
        }
        else if (A[mid] < key) {
            low = mid + 1;  // key is in the right half
        }
        else {
            high = mid - 1; // key is in the left half
        }
    }

    return -1; // key not found
}

int main() {
    int A[] = {11, 22, 33, 44, 55, 66, 77, 88};
    int n = sizeof(A) / sizeof(A[0]);
    int key = 33;

    int result = binary_search(A, n, key);
    if (result != -1) {
        printf("Found %d at index %d.\n", key, result);
    } else {
        printf("%d not found in the array.\n", key);
    }

    return 0;
}
