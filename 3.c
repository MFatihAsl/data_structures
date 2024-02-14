#include <stdio.h>
#include <stdbool.h>

bool recursive(int sayi, int i) {
    if (sayi <= 1) {
        return false;
    } else if (i < sayi) {
        if (sayi % i == 0) {
            return false;
        } else {
            return recursive(sayi, i + 1);
        }
    } else {
        return true;
    }
}

int main() {
    int sayi;
    printf("Sayiyi Girin: ");
    scanf("%d", &sayi);

    if (recursive(sayi, 2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
