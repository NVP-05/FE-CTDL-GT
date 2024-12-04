#include <stdio.h>
#include <string.h>
#include <ctype.h>

int kiemTraPalindrome(const char str[], int left, int right) {
    while (left < right && !isalnum(str[left])) left++;
    while (left < right && !isalnum(str[right])) right--;
    if (left >= right) return 1;
    if (tolower(str[left]) != tolower(str[right])) return 0;
    return kiemTraPalindrome(str, left + 1, right - 1);
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if (kiemTraPalindrome(str, 0, strlen(str) - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}

