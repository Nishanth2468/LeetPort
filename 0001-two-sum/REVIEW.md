# Two Sum C Implementation Review

## 1. Time Complexity
The current implementation utilizes a brute-force approach. It iterates through the array with a nested loop, comparing every possible pair of elements `nums[i]` and `nums[j]` to check if their sum equals the `target`.
- **Time Complexity:** O(n²), where `n` is the number of elements in the `nums` array. For an array of size `n`, the outer loop runs `n` times, and the inner loop runs roughly `n/2` times on average. This is highly inefficient for large arrays (e.g., $n > 10^4$), as it results in millions of operations and could cause a Time Limit Exceeded (TLE) error on platforms like LeetCode.

## 2. Space Complexity
- **Space Complexity:** O(1). The only extra space allocated is for the `result` array, which strictly takes 2 integer slots (a constant amount of space), irrespective of the input size `n`.

## 3. Edge Cases Handled
- **Dynamic Allocation Failure:** The implementation thoughtfully checks if `malloc` fails (`if (!result)`) and handles it properly by setting `*returnSize = 0` and returning `NULL`.
- **No Solution Found:** If the loops finish executing without finding any valid pair (although the problem statement typically guarantees exactly one solution), the function safely sets `*returnSize = 0`, frees the dynamically allocated `result` array to prevent memory leaks, and returns `NULL`.

## 4. Code Readability and Style
- **Strengths:**
  - The variable naming (`nums`, `numsSize`, `target`, `returnSize`, `result`) is clear and adheres to standard C conventions.
  - The structure and indentation are clean, making the logic easy to follow.
  - Appropriate comments explain key parts of the logic (e.g., allocation, iteration, and memory cleanup).
- **Weaknesses:**
  - The primary weakness is algorithmic efficiency, as O(n²) is suboptimal for this problem.

## 5. Suggested Improvements
The optimal way to solve the "Two Sum" problem is to reduce the time complexity to O(n) by using a Hash Map (or Hash Table). As we iterate through the array, we can store each number's value and its index in the hash map. For each element `nums[i]`, we calculate its complement (`target - nums[i]`) and check if this complement already exists in the hash map.
- If it exists, we have found our pair.
- If it doesn't exist, we add the current `nums[i]` and its index `i` to the hash map.
This allows us to find the pair in a single pass through the array.

Since C does not have a built-in hash map in its standard library, we can either:
1. Implement a simple, customized hash table using an array of linked lists or open addressing.
2. Use a simpler implementation utilizing a struct-based hash map for O(n) performance.

An optimized version will be implemented in `0001-two-sum.c` using a basic Hash Map.
