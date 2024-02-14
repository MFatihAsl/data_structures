#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack veri yapýsý tanýmý
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Stack fonksiyonlarý
void initialize(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack is full, cannot push element.\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot pop element.\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// Parantezlerin denge kontrolü
bool balanced(const char p[], size_t n) {
    Stack stack;
    initialize(&stack);

    for (size_t i = 0; i < n; i++) {
        char current = p[i];
        if (current == '(' || current == '{') {
            push(&stack, current);
        } else if (current == ')' || current == '}') {
            if (isEmpty(&stack)) {
                return false; // Eþleþen açýlýþ parantez yok
            }

            char top = pop(&stack);
            if ((current == ')' && top != '(') || (current == '}' && top != '{')) {
                return false; // Parantezler eþleþmiyor
            }
        }
    }

    return isEmpty(&stack); // Tüm parantezler eþleþti mi?
}

int main() {
    const char parentheses[] = "({()})"; // Test için örnek parantez dizisi
    size_t size = sizeof(parentheses) - 1;

    if (balanced(parentheses, size)) {
        printf("Parantezler dengeli!\n");
    } else {
        printf("Parantezler dengeli deðil!\n");
    }

    return 0;
}
