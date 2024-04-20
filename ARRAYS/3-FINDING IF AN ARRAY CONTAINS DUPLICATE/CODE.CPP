#include <stdio.h>
#include <stdbool.h>

bool containsDuplicate(int nums[], int numsSize) {
    // Check for duplicates using nested loops
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;  // Duplicate found
            }
        }
    }
    return false;  // No duplicates found
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 1};  // Example array with duplicates
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, numsSize)) {
        printf("The array contains duplicates.\n");
    } else {
        printf("The array does not contain duplicates.\n");
    }

    return 0;
}
