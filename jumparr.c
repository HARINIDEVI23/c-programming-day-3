#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printIndicesVisited(int nums[], int size, int indicesVisited[], int count) {
    printf("Jump from index 0 to ");
    for (int i = 0; i < count; i++) {
        printf("%d", indicesVisited[i]);
        if (i < count - 1) {
            printf(" -> ");
        }
    }
    printf(" -> %d, ", size - 1);
}

bool canJump(int nums[], int size) {
    int maxReach = 0;
    int indicesVisited[size];
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (i > maxReach) {
          
            printf("Explanation: Cannot reach index %d.\n", i);
            return false;
        }

        indicesVisited[count++] = i; // Store the index visited during the jump

   
        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach;

        
        if (maxReach >= size - 1) {
            printf("Explanation: ");
            printIndicesVisited(nums, size, indicesVisited, count);
            printf("reaches the last index %d.\n", size - 1);
            return true;
        }
    }

    return false;
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
    printf("Example 1 Output: %s\n", canJump(nums1, size1) ? "true" : "false");
    free(nums1);

    int size2;
    printf("Enter the size of the array for Example 2: ");
    scanf("%d", &size2);

    int *nums2 = (int *)malloc(size2 * sizeof(int));
    printf("Enter the elements of the array for Example 2: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &nums2[i]);
    }
    printf("Example 2 Output: %s\n", canJump(nums2, size2) ? "true" : "false");
    free(nums2);

    return 0;
}

