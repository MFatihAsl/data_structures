#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack veri yapısı tanımı
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Stack fonksiyonları
void initialize(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full, cannot push element.\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot pop element.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Prefix ifade hesaplama
int evaluatePrefix(char prefix[]) {
    Stack stack;
    initialize(&stack);

    int result = 0;
    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        char current = prefix[i];

        if (isdigit(current)) {
            push(&stack, current - '0'); // Karakteri sayıya dönüştürüp stack'e ekle
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            switch (current) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Geçersiz ifade.\n");
                    return -1;
            }

            push(&stack, result); // Operasyon sonucunu stack'e ekle
        }
    }

    return pop(&stack); // Hesaplama sonucunu döndür
}

int main() {
    char prefix[] = "-+*9+28*+4863"; // Örnek bir prefix ifade
    int result = evaluatePrefix(prefix);

    if (result != -1) {
        printf("Prefix ifadenin sonucu: %d\n", result);
    }

    return 0;
}
