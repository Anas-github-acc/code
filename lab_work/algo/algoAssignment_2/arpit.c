#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEAP_SIZE 100000

typedef struct {
    int heap[MAX_HEAP_SIZE];
    int size;
} MinHeap;

int compare_custom(int a, int b) {
    char a_str[10], b_str[10];
    snprintf(a_str, sizeof(a_str), "%d", a);
    snprintf(b_str, sizeof(b_str), "%d", b);

    int len = strlen(a_str);
    for (int i = 0; i < len; i++) {
        if (a_str[i] != b_str[i]) {
            return a_str[i] - b_str[i];
        }
    }
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_down(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    // Agar left ka element chhota hai toh smallest ko left pe set kar do
    if (left < heap->size && compare_custom(heap->heap[left], heap->heap[smallest]) < 0) {
        smallest = left;
    }
    // Agar right ka element bhi chhota hai toh smallest ko right pe set kar do
    if (right < heap->size && compare_custom(heap->heap[right], heap->heap[smallest]) < 0) {
        smallest = right;
    }

    // Agar smallest current idx se alag hai toh swap karo aur recursive call karo
    if (smallest != idx) {
        swap(&heap->heap[idx], &heap->heap[smallest]);
        heapify_down(heap, smallest);
    }
}

void heapify_up(MinHeap* heap, int idx) {
    if (idx == 0) return;

    int parent = (idx - 1) / 2;
    // Agar current element parent se chhota hai toh swap karo aur upar chhodo
    if (compare_custom(heap->heap[idx], heap->heap[parent]) < 0) {
        swap(&heap->heap[idx], &heap->heap[parent]);
        heapify_up(heap, parent);
    }
}

void insert(MinHeap* heap, int value) {
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Heap is full!\n");
        return;
    }

    heap->heap[heap->size] = value;
    heap->size++;
    heapify_up(heap, heap->size - 1);

    printf("Inserted: %d\n", value);
}

int pop(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int min = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);

    return min;
}

void build_heap(MinHeap* heap, int* arr, int n) {
    heap->size = n;
    for (int i = 0; i < n; i++) {
        heap->heap[i] = arr[i];
    }

    // Niche se upar tak heapify karo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_down(heap, i);
    }
}

void heap_sort(MinHeap* heap) {
    int original_size = heap->size;
    // Heap se sab elements nikal ke sort karo
    while (heap->size > 0) {
        printf("%d ", pop(heap));
    }
    heap->size = original_size;  
    printf("\n");
}

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 90000 + 10000;  // Random number between 10000 and 99999
}

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare_int(const void* a, const void* b) {
    return ((int)a - (int)b);
}

int main() {
    MinHeap heap;
    heap.size = 0;

    
    clock_t start, end;
    int choice, n, value;
    int arr[MAX_HEAP_SIZE];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create an empty min heap\n");
        printf("2. Input a list of integers to build heap\n");
        printf("3. Insert a single element into the heap\n");
        printf("4. Pop an element from the heap\n");
        printf("5. Perform heap sort and display sorted integers\n");
        printf("6. Generate a random array and compare heap sort with built-in sort\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        // sare switch cases apply krna, according to users
        switch (choice) {
            case 1:
                heap.size = 0;
                printf("Created an empty min heap.\n");
                break;

            case 2:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Enter the integers: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                build_heap(&heap, arr, n);
                printf("Heap built successfully.\n");
                break;

            case 3:
                printf("Enter the integer to insert: ");
                scanf("%d", &value);
                insert(&heap, value);
                break;

            case 4:
                value = pop(&heap);
                if (value != -1) {
                    printf("Popped: %d\n", value);
                }
                break;

            case 5:
                printf("Heap sorted integers: ");
                heap_sort(&heap);
                break;
            case 6:
                

                printf("Enter the length of the array to generate: ");
                scanf("%d", &n);
                generate_random_array(arr, n);
                printf("Generated array: ");
                // print_array(arr, n);

                // Copy original array for both sorts
                int* arr_copy1 = malloc(n * sizeof(int));
                int* arr_copy2 = malloc(n * sizeof(int));
                memcpy(arr_copy1, arr, n * sizeof(int));
                memcpy(arr_copy2, arr, n * sizeof(int));

                // Heap Sort
                start = clock();
                build_heap(&heap, arr_copy1, n);  // Build heap with the random array
                heap_sort(&heap);                 // Sort the heap
                end = clock();
                double heap_sort_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Heap sort time: %f seconds\n", heap_sort_time);

                // Standard library sort (using qsort)
                start = clock();
                qsort(arr_copy2, n, sizeof(int), compare_int);
                end = clock();
                double qsort_time = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Standard sort time: %f seconds\n", qsort_time);

                free(arr_copy1);
                free(arr_copy2);
                break;


            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
