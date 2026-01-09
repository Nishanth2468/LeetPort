/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the result
    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL; // Return NULL if malloc fails
    }

    // Iterate through the array to find two numbers that add up to the target
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2; // Indicate that the result has 2 elements
                return result;
            }
        }
    }

    // If no solution is found, returnSize is set to 0
    *returnSize = 0;
    free(result); // Free allocated memory if no solution
    return NULL;
}