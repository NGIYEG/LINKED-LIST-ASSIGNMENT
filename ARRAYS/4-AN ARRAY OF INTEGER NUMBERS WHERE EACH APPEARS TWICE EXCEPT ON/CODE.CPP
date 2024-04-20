#include <stdio.h>

int singleNumber(int nums[], int numsSize) {
    int result = 0;
    
    // Using XOR operation to find the single element
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }

    return result;
}

int main() {
    int nums[] = {4, 2, 7, 2, 4};  // Example array with one element appearing only once
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int singleElement = singleNumber(nums, numsSize);

    printf("The single element that appears only once is: %d\n", singleElement);

    return 0;
}
