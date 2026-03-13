/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>

// Hash map node structure
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Hash map structure
typedef struct {
    Node** buckets;
    int size;
} HashMap;

// Create a new hash map
HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = (Node**)calloc(size, sizeof(Node*));
    return map;
}

// Calculate hash value
int hashFunction(int key, int size) {
    int hash = key % size;
    if (hash < 0) {
        hash += size;
    }
    return hash;
}

// Insert key-value pair into hash map
void insert(HashMap* map, int key, int value) {
    int index = hashFunction(key, map->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

// Search for a key in hash map and return its value (index), or -1 if not found
int search(HashMap* map, int key) {
    int index = hashFunction(key, map->size);
    Node* current = map->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

// Free the hash map memory
void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* current = map->buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }

    // A reasonable hash map size based on constraints, although sizes can be up to 10^4
    int mapSize = numsSize * 2 + 1;
    HashMap* map = createHashMap(mapSize);

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = search(map, complement);

        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            freeHashMap(map);
            return result;
        }

        insert(map, nums[i], i);
    }

    *returnSize = 0;
    freeHashMap(map);
    free(result);
    return NULL;
}
