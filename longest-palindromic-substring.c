#include <string.h>
#include <stdbool.h>

bool isPalindrome(const char* s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int start = 0, size = 1;

    for (int i = 1; i < len; i++) {
        if (i - size >= 1 && isPalindrome(s, i - size - 1, i)) {
            start = i - size - 1;
            size += 2;
        } else if (isPalindrome(s, i - size, i)) {
            start = i - size;
            size += 1;
        }
    }

    char* result = (char*)malloc((size + 1) * sizeof(char));
    strncpy(result, s + start, size);
    result[size] = '\0';
    return result;
}
