#include <stdio.h>

int removeDuplicates(int nums[], int numsSize) {
    if (numsSize == 0) {
        return 0; // Empty array, no duplicates to remove
    }

    int uniqueIndex = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[uniqueIndex]) {
            uniqueIndex++;
            nums[uniqueIndex] = nums[i];
        }
    }

    return uniqueIndex + 1;
}

int main() {
    int nums[] = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original Array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    int newLength = removeDuplicates(nums, numsSize);

    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }

    printf("\nNew Length: %d\n", newLength);

    return 0;
}
