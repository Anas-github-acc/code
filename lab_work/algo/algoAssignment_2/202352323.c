// NAME - NITIN KUMAR                                ROLL NO. - 202352323
// LAB ASSIGNMENT - 02                               SUBMITTED TO - DIBYENDU ROY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define HEAP_MAX_SIZE 100

// Structure for the custom min heap
typedef struct {
    int values[HEAP_MAX_SIZE];
    int size;
} CustomMinHeap;

// Custom comparison function for the new ordering
bool customOrder(int a, int b) {
    char strA[10], strB[10];
    sprintf(strA, "%d", a);
    sprintf(strB, "%d", b);
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    
    // Compare from right to left
    for (int i = 1; i <= lenA && i <= lenB; i++) {
        if (strA[lenA - i] != strB[lenB - i]) {
            return strA[lenA - i] < strB[lenB - i];
        }
    }
    return false; // Numbers are identical
}

// Function to swap two integers
void swapElements(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain heap property upwards
void heapifyUp(CustomMinHeap *heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && customOrder(heap->values[index], heap->values[parent])) {
        swapElements(&heap->values[index], &heap->values[parent]);
        heapifyUp(heap, parent);
    }
}

// Function to maintain heap property downwards
void heapifyDown(CustomMinHeap *heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap->size && customOrder(heap->values[leftChild], heap->values[smallest])) {
        smallest = leftChild;
    }
    if (rightChild < heap->size && customOrder(heap->values[rightChild], heap->values[smallest])) {
        smallest = rightChild;
    }
    if (smallest != index) {
        swapElements(&heap->values[index], &heap->values[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Function to insert an element into the heap
void insert(CustomMinHeap *heap, int value) {
    if (heap->size < HEAP_MAX_SIZE) {
        heap->values[heap->size] = value;
        heapifyUp(heap, heap->size);
        heap->size++;
    } else {
        printf("Heap is full. Cannot insert more elements.\n");
    }
}

// Function to remove and return the minimum element
int pop(CustomMinHeap *heap) {
    if (heap->size > 0) {
        int minValue = heap->values[0];
        heap->values[0] = heap->values[--heap->size];
        heapifyDown(heap, 0);
        return minValue;
    } else {
        printf("Heap is empty.\n");
        return -1;
    }
}

// Function to build a heap from an array
void buildHeap(CustomMinHeap *heap, int arr[], int n) {
    heap->size = n;
    for (int i = 0; i < n; i++) {
        heap->values[i] = arr[i];
    }
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapifyDown(heap, i);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    CustomMinHeap heap;
    buildHeap(&heap, arr, n);
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&heap);
    }
}

// Function to display the heap
void displayHeap(CustomMinHeap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d: %d\n", i, heap->values[i]);
    }
}

// Function to generate random numbers with specified digits
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 90000 + 10000;  // Random number between 10000 and 99999
}

// Function to measure sorting times
void measureSortingTimes(int arr[], int n) {
    int copyArr[n];
    memcpy(copyArr, arr, n * sizeof(int));

    clock_t start, end;
    double cpu_time_used;

    // Measure heap sort time
    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Heap sort time: %f %s\n", cpu_time_used < 1 ? cpu_time_used * 1000 : cpu_time_used, 
           cpu_time_used < 1 ? "milliseconds" : "seconds");

    // Measure qsort time
    start = clock();
    qsort(copyArr, n, sizeof(int), (int (*)(const void*, const void*))customOrder);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Standard sort time: %f %s\n", cpu_time_used < 1 ? cpu_time_used * 1000 : cpu_time_used, 
           cpu_time_used < 1 ? "milliseconds" : "seconds");
}


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
int qsortCompare(const void* a, const void* b) {
    return compare(*(int*)a, *(int*)b);
}

int main() {
    CustomMinHeap heap = {.size = 0};
    int choice;
    
    char input[1000];
    clock_t start, end;
    double cpu_time_used;

    do {
        printf("\nMenu:\n");
        printf("1. Create an empty min heap\n");
        printf("2. Build heap from input list\n");
        printf("3. Insert element into heap\n");
        printf("4. Pop element from heap\n");
        printf("5. Display sorted heap\n");
        printf("6. Generate random array and sort\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                heap.size = 0;
                printf("Empty min heap created.\n");
                break;
            case 2: {
                int n, i = 0;
                char input[1000], *token;
                printf("Enter comma-separated list of integers: ");
                scanf("%[^\n]", input);
                int arr[HEAP_MAX_SIZE];
                token = strtok(input, ",");
                while (token != NULL && i < HEAP_MAX_SIZE) {
                    arr[i++] = atoi(token);
                    token = strtok(NULL, ",");
                }
                buildHeap(&heap, arr, i);
                printf("Heap built. Current heap:\n");
                displayHeap(&heap);
                break;
            }
            case 3: {
                int value;
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&heap, value);
                printf("Heap after insertion:\n");
                displayHeap(&heap);
                break;
            }
            case 4: {
                int minValue = pop(&heap);
                if (minValue != -1) {
                    printf("Popped value: %d\n", minValue);
                    printf("Heap after popping:\n");
                    displayHeap(&heap);
                }
                break;
            }
            case 5: {
                int sortedArr[heap.size];
                memcpy(sortedArr, heap.values, heap.size * sizeof(int));
                heapSort(sortedArr, heap.size);
                printf("Sorted heap: ");
                for (int i = 0; i < heap.size; i++) {
                    printf("%d ", sortedArr[i]);
                }
                printf("\n");
                break;
            }
             case 6: {
                int n;
                printf("Enter the length of array: ");
                scanf("%d", &n);
                int arr[n];
                generateRandomArray(arr, n);
                printf("Generated random array: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                measureSortingTimes(arr, n);

                break;

             }
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
