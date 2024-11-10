// NAME - DEVYASH SAINI                             ROLL NO. - 202351030
// LAB ASSIGNMENT - 2                               SUBMITTED TO - DIBYENDU ROY

// For using standard input and output functions
#include <stdio.h>
// For getting current timestamp as random seed
#include <time.h>
// Standard library for performing general functions
#include <stdlib.h>
// For using string type
#include <string.h>


#define HEAP_CAPACITY 100000

// Global heap array and current size
int priority_queue[HEAP_CAPACITY];
int queue_size = 0;

// Function prototypes (keeping the original functions)
void bubble_up(int index);
void sink_down(int index);
void create_heap_from_string(char *input_str);
void sort_heap();
void display_heap();

// New function for standard library sort (qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to generate a random array
void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 90001 + 10000;  // [10000, 100000)
    }
}

// Function to measure time for array generation and sorting
double measure_time(void (*sort_function)(void), int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    // Generate random array
    generate_random_array(priority_queue, n);
    queue_size = n;

    // Sort the array
    if (sort_function == sort_heap) {
        sort_heap();
    } else {
        qsort(priority_queue, n, sizeof(int), compare);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) * 1000.0 / CLOCKS_PER_SEC;

    return cpu_time_used;
}

int main() {
    srand(time(0));  // Initialize random seed
    int user_choice, num;
    char input_buffer[256];

    // Display the menu options (keeping the original options and adding the new one)
    printf("\nHeap Operations Menu:\n");
    printf("1. Initialize empty min heap\n");
    printf("2. Build heap from input\n");
    printf("3. Insert element\n");
    printf("4. Extract minimum\n");
    printf("5. Perform heap sort\n");
    printf("6. Generate and sort random array\n");
    printf("7. Compare heap sort with standard sort (including generation time)\n");
    printf("8. Exit program\n");

    while (1) {
        printf("Select an option: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            // Cases 1-6 remain the same as in the original code
            case 1:
                queue_size = 0;
                printf("Empty min heap initialized.\n");
                break;

            case 2:
                printf("Enter numbers separated by commas: ");
                scanf(" %[^\n]", input_buffer);
                create_heap_from_string(input_buffer);
                display_heap();
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &num);
                if (queue_size < HEAP_CAPACITY) {
                    priority_queue[queue_size++] = num;
                    bubble_up(queue_size - 1);
                    display_heap();
                } else {
                    printf("Error: Heap is full.\n");
                }
                break;

            case 4:
                if (queue_size > 0) {
                    int min = priority_queue[0];
                    priority_queue[0] = priority_queue[--queue_size];
                    sink_down(0);
                    printf("Extracted minimum: %d\n", min);
                    display_heap();
                } else {
                    printf("Error: Heap is empty.\n");
                }
                break;

            case 5:
                if (queue_size > 0) {
                    printf("Sorted elements: ");
                    sort_heap();
                } else {
                    printf("Error: Heap is empty.\n");
                }
                break;

            case 6:
                printf("Enter array size: ");
                scanf("%d", &num);
                if (num > HEAP_CAPACITY) {
                    printf("Error: Maximum size is %d.\n", HEAP_CAPACITY);
                } else {
                    for (int i = 0; i < num; i++) {
                        priority_queue[queue_size++] = rand() % 90000 + 10000;
                        bubble_up(queue_size - 1);
                    }
                    printf("Generated heap: ");
                    display_heap();
                    printf("Sorted array: ");
                    sort_heap();
                }
                break;

            // Updated case for comparing heap sort with standard sort
            case 7:
                printf("Enter array size for comparison: ");
                scanf("%d", &num);
                if (num > HEAP_CAPACITY) {
                    printf("Error: Maximum size is %d.\n", HEAP_CAPACITY);
                } else {
                    double heap_time = measure_time(sort_heap, num);
                    double std_time = measure_time(NULL, num);
                    
                    printf("Heap Sort (including generation time): %.2f ms\n", heap_time);
                    printf("Standard Sort (including generation time): %.2f ms\n", std_time);
                }
                break;

            case 8:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void bubble_up(int index) {
    int parent;
    while (index > 0) {
        parent = (index - 1) / 2;
        if (priority_queue[index] >= priority_queue[parent]) {
            break;
        }
        // Swap element with its parent
        int temp = priority_queue[index];
        priority_queue[index] = priority_queue[parent];
        priority_queue[parent] = temp;
        index = parent;
    }
}

// Function to maintain heap property by moving an element down
void sink_down(int index) {
    int min_child;
    while (1) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        
        // Find the smaller child
        if (left_child >= queue_size) {
            break;  // No children, we're done
        } else if (right_child >= queue_size) {
            min_child = left_child;  // Only left child exists
        } else {
            // Both children exist, choose the smaller one
            min_child = (priority_queue[left_child] < priority_queue[right_child]) ? left_child : right_child;
        }
        
        if (priority_queue[index] <= priority_queue[min_child]) {
            break;  // Heap property satisfied
        }
        
        // Swap with the smaller child
        int temp = priority_queue[index];
        priority_queue[index] = priority_queue[min_child];
        priority_queue[min_child] = temp;
        index = min_child;
    }
}

// Function to create a heap from a string of comma-separated numbers
void create_heap_from_string(char *input_str) {
    int current_num = 0;
    int parsing_number = 0;

    // Iterate through each character in the input string
    for (int i = 0; input_str[i] != '\0'; i++) {
        if (input_str[i] >= '0' && input_str[i] <= '9') {
            // Build the number digit by digit
            current_num = current_num * 10 + (input_str[i] - '0');
            parsing_number = 1;
        } else if ((input_str[i] == ',' || input_str[i] == ' ') && parsing_number) {
            // Add the parsed number to the heap if there's space
            if (queue_size < HEAP_CAPACITY) {
                priority_queue[queue_size++] = current_num;
                bubble_up(queue_size - 1);
                current_num = 0;
            }
            parsing_number = 0;
        }
    }

    // Handle the last number if input doesn't end with a delimiter
    if (parsing_number && queue_size < HEAP_CAPACITY) {
        priority_queue[queue_size++] = current_num;
        bubble_up(queue_size - 1);
    }
}

// Function to perform heap sort
void sort_heap() {
    int original_size = queue_size;
    for (int i = 0; i < original_size; i++) {
        // Extract the minimum element and reorganize the heap
        int min_element = priority_queue[0];
        priority_queue[0] = priority_queue[--queue_size];
        sink_down(0);
        printf("%d ", min_element);
    }
    printf("\n");
}

// Function to display the current state of the heap
void display_heap() {
    printf("Current heap state: ");
    for (int i = 0; i < queue_size; i++) {
        printf("%d ", priority_queue[i]);
    }
    printf("\n");
}
