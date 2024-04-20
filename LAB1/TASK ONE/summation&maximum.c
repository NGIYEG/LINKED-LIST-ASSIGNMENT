#include <stdio.h>

// Function to calculate the sum of integers in an array
int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum integer in an array
int maximum(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array (0 <= n <= ∞): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid array size. Please enter a non-negative value.\n");
        return 1;  // Exit with an error code
    }

    // Declare an array of length n
    int arr[n];

    // Take user input for the array elements
    printf("Enter %d integers for the array:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Call the summation function and display the result
    int sum = summation(arr, n);
    printf("Sum of the integers: %d\n", sum);

    // Call the maximum function and display the result
    int maxVal = maximum(arr, n);
    printf("Maximum integer in the array: %d\n", maxVal);

    return 0;
}


