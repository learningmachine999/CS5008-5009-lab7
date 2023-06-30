#include <stdio.h>

// Function to convert an integer to binary representation
int convertToBinary(int num) {
    int binary = 0, base = 1;
    while (num > 0) {
        binary += (num % 2) * base;
        num /= 2;
        base *= 10;
    }
    return binary;
}

// Function to convert binary representation to integer
int convertToInteger(int binary) {
    int num = 0, base = 1;
    while (binary > 0) {
        num += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    return num;
}

// Function to perform linear search on the array
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Input array size: ");
    scanf("%d", &size);

    int array[size];

    printf("Input elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int target;
    printf("Input target: ");
    scanf("%d", &target);

    printf("\nThe array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nThe target:\n%d\n", target);

    printf("\nConverted array:\n");
    for (int i = 0; i < size; i++) {
        int converted = convertToBinary(array[i]);
        printf("%d ", converted);
        array[i] = converted;
    }

    int convertedTarget = convertToBinary(target);
    printf("\n\nConverted target:\n%d\n", convertedTarget);

    int result = linearSearch(array, size, convertedTarget);

    printf("\nSearch result:\n%d\n", result);

    printf("\nOriginal array:\n");
    for (int i = 0; i < size; i++) {
        int original = convertToInteger(array[i]);
        printf("%d ", original);
        array[i] = original;
    }

    int originalTarget = convertToInteger(convertedTarget);
    printf("\n\nOriginal target:\n%d\n", originalTarget);

    return 0;
}
