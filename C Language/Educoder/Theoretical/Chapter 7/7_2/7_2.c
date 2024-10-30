#include <stdio.h>

void move(int arr[], int n, int k) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++) {
        arr[i] = temp[i + k];
    }
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}
