#include <stdio.h>
#include <stdlib.h>

// Declare the function signature
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1 = 0;
    int* result1 = twoSum(nums1, 4, target1, &returnSize1);
    if (result1 && returnSize1 == 2) {
        printf("Test 1 Passed: [%d, %d]\n", result1[0], result1[1]);
        free(result1);
    } else {
        printf("Test 1 Failed\n");
    }

    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2 = 0;
    int* result2 = twoSum(nums2, 3, target2, &returnSize2);
    if (result2 && returnSize2 == 2) {
        printf("Test 2 Passed: [%d, %d]\n", result2[0], result2[1]);
        free(result2);
    } else {
        printf("Test 2 Failed\n");
    }

    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3 = 0;
    int* result3 = twoSum(nums3, 2, target3, &returnSize3);
    if (result3 && returnSize3 == 2) {
        printf("Test 3 Passed: [%d, %d]\n", result3[0], result3[1]);
        free(result3);
    } else {
        printf("Test 3 Failed\n");
    }

    int nums4[] = {-1, -2, -3, -4, -5};
    int target4 = -8;
    int returnSize4 = 0;
    int* result4 = twoSum(nums4, 5, target4, &returnSize4);
    if (result4 && returnSize4 == 2) {
        printf("Test 4 Passed: [%d, %d]\n", result4[0], result4[1]);
        free(result4);
    } else {
        printf("Test 4 Failed\n");
    }

    return 0;
}
