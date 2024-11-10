// Name - Mohd Anas
// Roll No - 202352322 

#include <stdio.h>
#include <string.h>

// Helper function to check if two substrings are equal
// Parameters:
// - str: input string
// - start1: starting index of first substring
// - start2: starting index of second substring
// - len: length of substrings to compare
int areEqual(char *str, int start1, int start2, int len) {
    for(int i = 0; i < len; i++) {
        if(str[start1 + i] != str[start2 + i]) 
            return 0;
    }
    return 1;
}

// Part 1: Function to check if a string belongs to language L
// Returns 1 if string is in form ww1w where w is non-empty
int belongsToL(char *str) {
    int n = strlen(str);
    
    // w must be non-empty and appear at start and end
    // Maximum length of w can be n/3 because:
    // - need space for w at start (len)
    // - need space for w1 in middle (at least 0)
    // - need space for w at end (len)
    for(int wlen = 1; wlen <= n/3; wlen++) {
        // Check if prefix w equals suffix w
        if(areEqual(str, 0, n-wlen, wlen)) {
            // Found matching w at start and end
            // Middle part w1 can be anything
            return 1;
        }
    }
    return 0;
}

// Part 2: Function to check if a string belongs to L*
// Uses dynamic programming to minimize calls to belongsToL
int belongsToLStar(char *str) {
    int n = strlen(str);
    
    // Empty string belongs to L* (L⁰)
    if(n == 0) return 1;
    
    // dp[i] = 1 if substring str[0...i-1] belongs to L*
    // dp[i] = 0 otherwise
    int dp[101] = {0}; // Assuming max length 100
    dp[0] = 1; // Empty string belongs to L*
    
    // For each ending position i
    for(int i = 1; i <= n; i++) {
        // Try all possible splits before position i
        for(int j = 0; j < i; j++) {
            // Check if:
            // 1. str[0...j-1] belongs to L* (dp[j])
            // 2. str[j...i-1] belongs to L
            
            // Extract str[j...i-1] to check if it's in L
            char temp[101];
            strncpy(temp, str + j, i - j);
            temp[i-j] = '\0';
            
            if(dp[j] && belongsToL(temp)) {
                dp[i] = 1; // Found valid split
                break;
            }
        }
    }
    
    return dp[n];
}

// Testing functions with example inputs
void testBelongsToL() {
    printf("\nTesting belongsToL function:\n");
    char test1[] = "aaa";       // w="a", w1=""
    char test2[] = "abcdefabc"; // w="abc", w1="def"
    char test3[] = "abcd";      // not in L
    
    printf("Test 1 (%s): %s\n", test1, belongsToL(test1) ? "Yes" : "No");
    printf("Test 2 (%s): %s\n", test2, belongsToL(test2) ? "Yes" : "No");
    printf("Test 3 (%s): %s\n", test3, belongsToL(test3) ? "Yes" : "No");
}

void testBelongsToLStar() {
    printf("\nTesting belongsToLStar function:\n");
    char test1[] = "";                          // empty string
    char test2[] = "abcdefabcghighighi";       // concatenation of two L strings
    char test3[] = "aaa";                      // single L string
    
    printf("Test 1 (empty): %s\n", belongsToLStar(test1) ? "Yes" : "No");
    printf("Test 2 (%s): %s\n", test2, belongsToLStar(test2) ? "Yes" : "No");
    printf("Test 3 (%s): %s\n", test3, belongsToLStar(test3) ? "Yes" : "No");
}

int main() {
    // Uncomment to run tests
    // testBelongsToL();
    // testBelongsToLStar();
    
    // Read input string and process
    char str[101]; // Assuming max length 100
    printf("Enter string to check: ");
    scanf("%s", str);
    
    printf("\nPart 1 (belongs to L): %s\n", belongsToL(str) ? "Yes" : "No");
    printf("Part 2 (belongs to L*): %s\n", belongsToLStar(str) ? "Yes" : "No");
    
    return 0;
}