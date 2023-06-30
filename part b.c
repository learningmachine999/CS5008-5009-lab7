#include <stdio.h>

// Function to sort the array using bubble sort algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If we reach here, the element was not present
    return -1;
}

int main() {
    int n;

    printf("Input array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Input elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Input target: ");
    scanf("%d", &target);

    printf("\nThe array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nThe target:\n%d\n\n", target);

    // Sort the array using bubble sort
    bubbleSort(arr, n);


    printf("\n\nSearch result:\n");
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("-1\n");
    else
        printf("%d\n", result);

    return 0;
}
