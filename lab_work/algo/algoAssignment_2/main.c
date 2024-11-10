// Name - Mohd Anas
// Roll no - 202352322


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// max heap size
#define MAX_SIZE 100000

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
} // comparison function for qsort


typedef struct {
    int* array;
    int size;
    int capacity;
} MinHeap; // heap structure

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (int*)malloc(capacity * sizeof(int));
    return minHeap;
} // create a new Min Heap

void heapify(MinHeap* minHeap, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < minHeap->size && compare(minHeap->array[l], minHeap->array[smallest]) < 0)
        smallest = l;

    if (r < minHeap->size && compare(minHeap->array[r], minHeap->array[smallest]) < 0)
        smallest = r;

    if (smallest != i) {
        int temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[smallest];
        minHeap->array[smallest] = temp;
        heapify(minHeap, smallest);
    }
} // heapify function - to maintain heap property

void insert(MinHeap* minHeap, int key) {
    if (minHeap->size == minHeap->capacity) {
        printf("\nOverflow: Could not insert key\n");
        return;
    }

    int i = minHeap->size;
    minHeap->array[i] = key;
    minHeap->size++;

    while (i != 0 && compare(minHeap->array[(i - 1) / 2], minHeap->array[i]) > 0) {
        int temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
} // insert a new key

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
} // remove the minimum element (root) from min heap


void buildHeap(MinHeap* minHeap) {
    int startIdx = (minHeap->size / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
        heapify(minHeap, i);
} // build the min heap

void heapSort(int arr[], int n) {
    MinHeap* minHeap = createMinHeap(n);
    for (int i = 0; i < n; i++)
        insert(minHeap, arr[i]);
    
    for (int i = 0; i < n; i++)
        arr[i] = pop(minHeap);
    
    free(minHeap->array);
    free(minHeap);
} // heap sort function

void displayHeap(MinHeap* minHeap) {
    printf("Heap as array (index: value): ");
    for (int i = 0; i < minHeap->size; i++)
        printf("%d: %d ", i, minHeap->array[i]);
    printf("\n");
} // display the heap

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 90000 + 10000;  // Random number between 10000 and 99999
}

void Menu(int choice, MinHeap** minHeap) {
    int n, element;
    char input[1000];
    clock_t start, end;
    double cpu_time_used;

    switch (choice) {
        case 1:
            if (*minHeap != NULL) {
                free((*minHeap)->array);
                free(*minHeap);
            }
            *minHeap = createMinHeap(MAX_SIZE);
            printf("Empty min heap created.\n");
            break;

        case 2:
            if (*minHeap != NULL) {
                free((*minHeap)->array);
                free(*minHeap);
            }
            *minHeap = createMinHeap(MAX_SIZE);
            printf("Enter comma-separated list of integers: ");
            scanf(" %[^\n]", input);
            char* token = strtok(input, ",");
            while (token != NULL) {
                insert(*minHeap, atoi(token));
                token = strtok(NULL, ",");
            }
            buildHeap(*minHeap);
            displayHeap(*minHeap);
            break;

        case 3:
            if (*minHeap == NULL) {
                printf("Hey there! Let's create a heap before we proceed.\n");
                break;
            }
            printf("Enter element to insert: ");
            scanf("%d", &element);
            insert(*minHeap, element);
            displayHeap(*minHeap);
            break;

        case 4:
            if (*minHeap == NULL || (*minHeap)->size == 0) {
                printf("Heap is empty.\n");
                break;
            }
            printf("Popped element: %d\n", pop(*minHeap));
            displayHeap(*minHeap);
            break;

        case 5:
            if (*minHeap == NULL || (*minHeap)->size == 0) {
                printf("Heap is empty.\n");
                break;
            }
            printf("Sorted order --> ");
            int* tempArr = malloc((*minHeap)->size * sizeof(int));
            memcpy(tempArr, (*minHeap)->array, (*minHeap)->size * sizeof(int));
            int tempSize = (*minHeap)->size;
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
            double diff = ((double) (end - start)) / CLOCKS_PER_SEC - cpu_time_used;
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("STL sorting algorithm (qsort) time: %f %s\n", cpu_time_used < 1 ? cpu_time_used * 1000 : cpu_time_used, cpu_time_used < 1 ? "milliseconds" : "seconds");

            if (diff > 0) {
                printf("Heap Sort wins by %f %s\n", diff < 1 ? diff * 1000 : diff, diff < 1 ? "milliseconds" : "seconds");
            } else if (diff < 0) {
                printf("STL(qsort) wins by %f %s\n", -diff < 1 ? -diff * 1000 : -diff, -diff < 1 ? "milliseconds" : "seconds");
            } else {
                printf("Both sorting algorithms took the same time.\n");
            }

            free(arr); // free the memory so that it can be reused and not cause memory leak
            free(arr_copy); 
            break;

        case 7:
            // free the memory and exit the program
            if (*minHeap != NULL) {
                free((*minHeap)->array);
                free(*minHeap);
            }
            printf("Venturing out of the program!\n");
            exit(0);

        default:
            printf("Oops! That's a no-go. Try again!\n");
    }
}

int main() {
    MinHeap* minHeap = NULL;
    int choice;

    srand(time(NULL));

    while (1) {
        printf("\n1. Craft an empty min heap");
        printf("\n2. Forge heap from numbers");
        printf("\n3. Add a shiny new element");
        printf("\n4. Extract the mighty element");
        printf("\n5. Reveal the sorted treasure");
        printf("\n6. Heap Sort vs. Quick Sort showdown!");
        printf("\n7. Exit the heap realm");
        printf("\n--> [choice]: ");
        scanf("%d", &choice);

        Menu(choice, &minHeap);
    }

    return 0;
}