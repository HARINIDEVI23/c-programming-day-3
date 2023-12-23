#include <stdio.h>
#include <stdlib.h>

void printSubarray(int nums[], int start, int end) {
    printf("The subarray [");
    for (int i = start; i <= end; i++) {
        printf("%d", nums[i]);
        if (i < end) {
            printf(", ");
        }
    }
    printf("] ");
}

void printExplanation(int nums[], int size, int maxStart, int maxEnd, int maxSum) {
    printf("has the largest sum %d\n", maxSum);
    printSubarray(nums, maxStart, maxEnd);
    printf("has the largest sum %d\n", maxSum);
}

void maxSubArraySum(int nums[], int size) {
    int maxStart = 0;
    int maxEnd = 0;
    int currentStart = 0;
    int maxEndingHere = nums[0];
    int maxSoFar = nums[0];

    for (int i = 1; i < size; i++) {
        if (maxEndingHere + nums[i] > nums[i]) {
            maxEndingHere = maxEndingHere + nums[i];
        } else {
            maxEndingHere = nums[i];
            currentStart = i;
        }

        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            maxStart = currentStart;
            maxEnd = i;
        }
    }

    printExplanation(nums, size, maxStart, maxEnd, maxSoFar);
}

int main() {

    int size1;
    printf("Enter the size of the array for Example 1: ");
    scanf("%d", &size1);

    int *nums1 = (int *)malloc(size1 * sizeof(int));
    printf("Enter the elements of the array for Example 1: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &nums1[i]);
    }
    printf("Example 1 Output: ");
    maxSubArraySum(nums1, size1);
    free(nums1);


    int size2;
    printf("Enter the size of the array for Example 2: ");
    scanf("%d", &size2);

    int *nums2 = (int *)malloc(size2 * sizeof(int));
    printf("Enter the elements of the array for Example 2: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &nums2[i]);
    }
    printf("Example 2 Output: ");
    maxSubArraySum(nums2, size2);
    free(nums2);


    int size3;
    printf("Enter the size of the array for Example 3: ");
    scanf("%d", &size3);

    int *nums3 = (int *)malloc(size3 * sizeof(int));
    printf("Enter the elements of the array for Example 3: ");
    for (int i = 0; i < size3; i++) {
        scanf("%d", &nums3[i]);
    }
    printf("Example 3 Output: ");
    maxSubArraySum(nums3, size3);
    free(nums3);

    return 0;
}
