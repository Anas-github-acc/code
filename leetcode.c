#include <stdio.h>
#include <string.h>

// Function to check if the string belongs to L
int L(char *x) {
    int len = strlen(x);

    // Try splitting the string into two equal parts
    for (int i = 1; i < len; i++) {
        int match = 1;
        // Compare the first i characters with the last i characters
        for (int k = 0; k < i; k++) {
            if (x[k] != x[len - i + k]) {  // Compare the first and last parts
                match = 0;
                break;
            }
        }
        if (match) {
            return 1;  // If the first and last parts match, return 1
        }
    }
    return 0;  // No match found
}

// Function to check if the string belongs to L*
int L_star(char *y) {
    int len = strlen(y);

    // Try splitting the string into two non-empty parts
    for (int i = 1; i < len; i++) {
        // Manually create the left and right parts
        char left[i + 1], right[len - i + 1];

        // Manually copy the left part
        for (int j = 0; j < i; j++) {
            left[j] = y[j];
        }
        left[i] = '\0';  // Null-terminate the left part

        // Manually copy the right part
        for (int j = 0; j < len - i; j++) {
            right[j] = y[i + j];
        }
        right[len - i] = '\0';  // Null-terminate the right part

        // Check if both left and right satisfy the L condition
        if (L(left) && L(right)) {
            return 1;  // Return 1 if both parts belong to L
        }
    }
    return 0;  // Return 0 if no valid split is found
}

int main() {
    char y[100];
    
    // Ensure the string is not empty
    scanf("%s", y);
    
    if (strlen(y) == 0) {
        // Handle the case where the string is empty
        printf("NO\n");
    } else {
        // Check if the string belongs to L*
        if (L_star(y)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
