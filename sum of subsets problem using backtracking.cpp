#include <stdio.h>

void sumOfSubsets(int arr[], int n, int sum, int curr_sum, int index, int target_sum) {
    if (curr_sum == target_sum) {
        printf("Sum found: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    if (curr_sum > target_sum || index == n) {
        return;
    }

    // Include current element in subset
    sumOfSubsets(arr, n, sum, curr_sum + arr[index], index + 1, target_sum);

    // Exclude current element from subset
    sumOfSubsets(arr, n, sum, curr_sum, index + 1, target_sum);
}

int main() {
    int arr[] = {10, 5, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target_sum = 8;

    sumOfSubsets(arr, n, 0, 0, 0, target_sum);

    return 0;
}
