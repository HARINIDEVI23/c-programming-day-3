#include <stdio.h>
#include <stdlib.h>

void printArray(int digits[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", digits[i]);
    }
}

int* plusOne(int digits[], int size, int* newSize) {
   
    int carry = 1;

    printf("Starting with the least significant digit:\n");

    for (int i = size - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;

    
        printf("Digit at position %d: %d + 1 = %d, Carry = %d\n", size - i, digits[i] - 1, digits[i], carry);
    }

    if (carry > 0) {
        (*newSize)++;
        int* result = (int*)malloc((*newSize) * sizeof(int));
        result[0] = carry;

    
        printf("Carry after processing all digits: %d + 1 = %d, New Digit = %d\n", 0, carry, carry);

        for (int i = 0; i < size; i++) {
            result[i + 1] = digits[i];
        }
        return result;
    } else {
        return digits;
    }
}

int main() {

    int size1;
    printf("Enter the number of digits for Example 1: ");
    scanf("%d", &size1);

    int* digits1 = (int*)malloc(size1 * sizeof(int));
    printf("Enter the digits for Example 1 (from most significant to least significant): ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &digits1[i]);
    }

    int newSize1 = 0;
    int* result1 = plusOne(digits1, size1, &newSize1);

    printf("\nExample 1:\n");
    printf("Array represents the integer: ");
    printArray(digits1, size1);
    printf("\nIncrementing by one gives: ");
    printArray(result1, newSize1);
    printf("\nResult: [");
    for (int i = 0; i < newSize1; i++) {
        printf("%d", result1[i]);
        if (i < newSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(digits1);
    free(result1);


    int size2;
    printf("\nEnter the number of digits for Example 2: ");
    scanf("%d", &size2);

    int* digits2 = (int*)malloc(size2 * sizeof(int));
    printf("Enter the digits for Example 2 (from most significant to least significant): ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &digits2[i]);
    }

    int newSize2 = 0;
    int* result2 = plusOne(digits2, size2, &newSize2);

    printf("\nExample 2:\n");
    printf("Array represents the integer: ");
    printArray(digits2, size2);
    printf("\nIncrementing by one gives: ");
    printArray(result2, newSize2);
    printf("\nResult: [");
    for (int i = 0; i < newSize2; i++) {
        printf("%d", result2[i]);
        if (i < newSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(digits2);
    free(result2);

    return 0;
}
