#include <stdio.h>

void bolenbulma(int x, int i) {
    if (i <= x) {
        if (x % i == 0) {
            printf("%d ", i);
        }
        bolenbulma(x, i + 1);
    }
}
int main() {
    int x;
    printf("INPUT: ");
    scanf("%d", &x);
    printf("OUTPUT: ");
    bolenbulma(x, 2);

    return 0;
}
