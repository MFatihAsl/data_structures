#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool recursive(char str[], int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return recursive(str, start + 1, end - 1);
}

bool isPalindrome(char str[]) {
    int length = strlen(str);
    return recursive(str, 0, length - 1);
}

int main() {
    char input[100];

    printf("Bir kelime girin: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("%s bir palindromdur.\n", input);
    } else {
        printf("%s bir palindrom değildir.\n", input);
    }

    return 0;
}
