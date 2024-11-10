// Name - Himanshu
// Roll no - 202351047

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Maximum heap size
#define MAX_SIZE 100000

// Custom comparison function
int compare(int a, int b) {
    char str_a[10], str_b[10];
    sprintf(str_a, "%d", a);
    sprintf(str_b, "%d", b);
    
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    
    for(int i = len_a - 1, j = len_b - 1; i >= 0 && j >= 0; i--, j--) {
        if(str_a[i] != str_b[j]) {
            return str_a[i] - str_b[j];
        }
    }
    return 0;
}

// Heap structure
typedef struct {
    int* array;
    int size;
    int capacity;
} MinHeap;

// Function to create a new Min Heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (int*)malloc(capacity * sizeof(int));
    return minHeap;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function
void heapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && compare(minHeap->array[left], minHeap->array[smallest]) < 0)
        smallest = left;

    if (right < minHeap->size && compare(minHeap->array[right], minHeap->array[smallest]) < 0)
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->array[idx], &minHeap->array[smallest]);
        heapify(minHeap, smallest);
    }
}

// Function to insert a new key
void insert(MinHeap* minHeap, int key) {
    if (minHeap->size == minHeap->capacity) {
        printf("\nOverflow: Could not insert key\n");
        return;
    }

    int i = minHeap->size;
    minHeap->array[i] = key;
    minHeap->size++;

    while (i != 0 && compare(minHeap->array[(i - 1) / 2], minHeap->array[i]) > 0) {
        swap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove the minimum element (root) from min heap
int pop(MinHeap* minHeap) {
    if (minHeap->size <= 0)
        return -1;
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->array[0];
    }

    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    heapify(minHeap, 0);

    return root;
}

// Function to build the min heap
void buildHeap(MinHeap* minHeap) {
    int startIdx = (minHeap->size / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
        heapify(minHeap, i);
}

// Heap Sort function
void heapSort(int arr[], int n) {
    MinHeap* minHeap = createMinHeap(n);
    for (int i = 0; i < n; i++)
        insert(minHeap, arr[i]);
    
    for (int i = 0; i < n; i++)
        arr[i] = pop(minHeap);
    
    free(minHeap->array);
    free(minHeap);
}

// Function to display the heap
void displayHeap(MinHeap* minHeap) {
    printf("Heap as array (index: value): ");
    for (int i = 0; i < minHeap->size; i++)
        printf("%d: %d ", i, minHeap->array[i]);
    printf("\n");
}

// Function to generate random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 90000 + 10000;  // Random number between 10000 and 99999
}

// Comparison function for qsort
int qsortCompare(const void* a, const void* b) {
    return compare(*(int*)a, *(int*)b);
}

// Main function
int main() {
    MinHeap* minHeap = NULL;
    int choice, n, element;
    char input[1000];
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));  // Seed for random number generation

    while (1) {
        printf("\n1. Create an empty min heap");
        printf("\n2. Build heap from comma-separated list");
        printf("\n3. Insert an element");
        printf("\n4. Pop an element");
        printf("\n5. Display sorted order");
        printf("\n6. Compare Heap Sort with standard library sort");
        printf("\n7. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (minHeap != NULL) {
                    free(minHeap->array);
                    free(minHeap);
                }
                minHeap = createMinHeap(MAX_SIZE);
                printf("Empty min heap created.\n");
                break;

            case 2:
                if (minHeap != NULL) {
                    free(minHeap->array);
                    free(minHeap);
                }
                minHeap = createMinHeap(MAX_SIZE);
                printf("Enter comma-separated list of integers: ");
                scanf(" %[^\n]", input);
                char* token = strtok(input, ",");
                while (token != NULL) {
                    insert(minHeap, atoi(token));
                    token = strtok(NULL, ",");
                }
                buildHeap(minHeap);
                displayHeap(minHeap);
                break;

            case 3:
                if (minHeap == NULL) {
                    printf("Please create a heap first.\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(minHeap, element);
                displayHeap(minHeap);
                break;

            case 4:
                if (minHeap == NULL || minHeap->size == 0) {
                    printf("Heap is empty.\n");
                    break;
                }
                printf("Popped element: %d\n", pop(minHeap));
                displayHeap(minHeap);
                break;

            case 5:
                if (minHeap == NULL || minHeap->size == 0) {
                    printf("Heap is empty.\n");
                    break;
                }
                printf("Sorted order: ");
                int* tempArr = malloc(minHeap->size * sizeof(int));
                memcpy(tempArr, minHeap->array, minHeap->size * sizeof(int));
                int tempSize = minHeap->size;
                heapSort(tempArr, tempSize);
                for (int i = 0; i < tempSize; i++)
                    printf("%d ", tempArr[i]);
                printf("\n");
                free(tempArr);
                break;

            case 6:
                printf("Enter the length of array: ");
                scanf("%d", &n);
                int* arr = malloc(n * sizeof(int));
                generateRandomArray(arr, n);

                int* arr_copy = malloc(n * sizeof(int));
                memcpy(arr_copy, arr, n * sizeof(int));

                // Heap Sort
                start = clock();
                heapSort(arr, n);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Heap Sort time: %f %s\n", cpu_time_used < 1 ? cpu_time_used * 1000 : cpu_time_used, cpu_time_used < 1 ? "milliseconds" : "seconds");

                // Standard library sort (using qsort)
                start = clock();
                qsort(arr_copy, n, sizeof(int), qsortCompare);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Standard library sort time: %f %s\n", cpu_time_used < 1 ? cpu_time_used * 1000 : cpu_time_used, cpu_time_used < 1 ? "milliseconds" : "seconds");

                free(arr);
                free(arr_copy);
                break;

            case 7:
                if (minHeap != NULL) {
                    free(minHeap->array);
                    free(minHeap);
                }
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}