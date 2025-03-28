#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to find a substring within a string using pointers
void substring(const char *str, int start, int length, char *result) {
    int i;
    const char *ptr = str + start;
    // Check if start and length are valid
    if (start < 0 || length < 0 || start >= strlen(str)) {
        result[0] = '\0'; // Set result to an empty string if parameters are invalid
        return;
    }

    for (i = 0; i < length && ptr[i] != '\0'; i++) {
        result[i] = ptr[i];
    }
    result[i] = '\0';
}

// Function to check if a string is a palindrome using pointers
bool isPalindrome(const char *str) {
    const char *left = str;
    const char *right = str;
    // Move right to the end of the string
    while (*right != '\0') {
        right++;
    }
    right--; // Adjust right to be the last character index

    while (left < right) {
        if (*left != *right) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to compare two strings using pointers
int stringCompare(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// Function to copy a string using pointers
void stringCopy(const char *src, char *dest) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

// Function to reverse a string using pointers
void stringReverse(const char *str, char *result) {
    const char *end = str;
    while (*end != '\0') {
        end++;
    }
    end--; // Adjust end to be the last character index

    while (end >= str) {
        *result = *end;
        result++;
        end--;
    }
    *result = '\0';
}

int main() {
    char str1[100], str2[100], str3[100];
    char result[100];
    int start, length;

    // Take input strings from the user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character

    printf("Enter the third string: ");
    fgets(str3, sizeof(str3), stdin);
    str3[strcspn(str3, "\n")] = '\0';  // Remove newline character

    // Prompt for substring start index and length
    printf("Enter the start index for the substring: ");
    scanf("%d", &start);
    printf("Enter the length of the substring: ");
    scanf("%d", &length);

    // Ensure user consumes newline character left by scanf
    while (getchar() != '\n');

    // Substring operation
    substring(str1, start, length, result);
    printf("Substring of '%s' starting at index %d with length %d: '%s'\n", str1, start, length, result);

    // Palindrome check
    bool palindrome = isPalindrome(str2);
    printf("'%s' is %sa palindrome\n", str2, palindrome ? "" : "not ");

    // String compare
    int cmp = stringCompare(str1, str3);
    printf("Comparison of '%s' and '%s': %d\n", str1, str3, cmp);

    // String copy
    stringCopy(str1, result);
    printf("Copy of '%s': '%s'\n", str1, result);

    // String reverse
    stringReverse(str1, result);
    printf("Reverse of '%s': '%s'\n", str1, result);

    // Verifying with built-in functions
    // Substring
    char built_in_substring[100];
    strncpy(built_in_substring, str1 + start, length);
    built_in_substring[length] = '\0';
    printf("Built-in Substring of '%s' starting at index %d with length %d: '%s'\n", str1, start, length, built_in_substring);

    // Palindrome check
    bool built_in_palindrome = true;
    const char *left = str2;
    const char *right = str2 + strlen(str2) - 1;
    while (left < right) {
        if (*left != *right) {
            built_in_palindrome = false;
            break;
        }
        left++;
        right--;
    }
    printf("Built-in check: '%s' is %sa palindrome\n", str2, built_in_palindrome ? "" : "not ");

    // String compare
    int built_in_cmp = strcmp(str1, str3);
    printf("Built-in comparison of '%s' and '%s': %d\n", str1, str3, built_in_cmp);

    // String copy
    char built_in_copy[100];
    strcpy(built_in_copy, str1);
    printf("Built-in copy of '%s': '%s'\n", str1, built_in_copy);

    // String reverse
    char built_in_reverse[100];
    int length_built_in = strlen(str1);
    for (int i = 0; i < length_built_in; i++) {
        built_in_reverse[i] = str1[length_built_in - i - 1];
    }
    built_in_reverse[length_built_in] = '\0';
    printf("Built-in reverse of '%s': '%s'\n", str1, built_in_reverse);

    return 0;
}
