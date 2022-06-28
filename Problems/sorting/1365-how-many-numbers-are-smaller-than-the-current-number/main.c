#include <stdio.h>
#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int *result = malloc(sizeof(int) * *returnSize);

    for (int i=0; i<numsSize; i++) {
        for (int j=0; j<numsSize; j++) {
            if (i != j && nums[j] < nums[i]) {
                result[i]++;
            }
        }
    }

    return result;
}

void printArrayElements(int *arr, int arrSize) {
    for (int i=0; i<arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 7;
    int arr[] = {2, 4, 1, 6, 3, 8, 10};
    printArrayElements(arr, n);
    printArrayElements(smallerNumbersThanCurrent(arr, n, &n), n);

    return 0;
}