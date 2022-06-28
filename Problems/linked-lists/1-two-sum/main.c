#include <stdio.h>
#include <stdlib.h>

// int *twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     *returnSize = 2;
//     int *sum = (int *)malloc(2 * sizeof(int));

//     for (int i=0; i<numsSize-1; i++) {
//         for (int j=i+1; j<numsSize; j++) {
//             if (nums[i] + nums[j] == target) {
//                 sum[0] = i;
//                 sum[1] = j;
//                 break;
//             }
//         }
//     }

//     return sum;
// }

int *twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
}

void printArray(int *arr, int arrSize) {
    for (int i=0; i<arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numsSize;
    printf("Type in the size of the array: ");
    scanf("%d", &numsSize);

    int *nums = malloc(sizeof(int)*numsSize);
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 3;
    nums[3] = 15;

    int target = 6;
    
    printArray(nums, numsSize);

    int *sum = malloc(sizeof(int)*2), ret;
    sum = twoSum(nums, numsSize, target, &ret);
    printArray(sum, 2);


    return 0;
}