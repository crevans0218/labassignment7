#include <stdio.h>

int bubbleSort(int arr[], int n, int swaps[]) {
    int total_swaps = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
                total_swaps += 2;
            }
        }
    }
    return total_swaps;
}

int selectionSort(int arr[], int n, int swaps[]) {
    int total_swaps = 0;
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swaps[arr[i]]++;
            swaps[arr[min_idx]]++;
            total_swaps += 2;
        }
    }
    return total_swaps;
}

int main() {
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int swaps1[101] = {0};
    int total_swaps1 = bubbleSort(arr1, n1, swaps1);
    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", arr1[i], swaps1[arr1[i]]);
    }
    printf("total swaps: %d\n\n", total_swaps1);
    
    int swaps2[101] = {0};
    int total_swaps2 = selectionSort(arr2, n2, swaps2);
    printf("array2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", arr2[i], swaps2[arr2[i]]);
    }
    printf("total swaps: %d\n", total_swaps2);

    return 0;
}
