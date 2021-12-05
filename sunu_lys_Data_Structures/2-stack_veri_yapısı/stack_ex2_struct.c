#include <stdio.h>

typedef enum { false, true }boolean;
#define STACK_SIZE 10

typedef struct {
    int data[STACK_SIZE]; // ihtiyaca göre veri türü deðiþebilir
    int top;
    /* sürekli eleman ekleme ve silme iþlemi yapýlacaðý için en üstteki
    * elemanýn indisini tutan top adýnda bir deðiþken tanýmladýk */
}stack;


void push(stack* stk, int c);
void reset(stack* stk);
boolean isEmpty(stack* stk);
boolean isFull(stack* stk);
int pop(stack* stk);
/* peek iþlemi ???*/

int main() {
    int x;
    stack n;

    reset(&n);

    push(&n, 4);
    push(&n, 2);
    push(&n, 5);
    push(&n, 7);
    push(&n, 11);

    x = pop(&n);
    printf("%d\n", x);

    x = pop(&n);
    printf("%d\n", x);

    x = pop(&n);
    printf("%d\n", x);

    x = pop(&n);
    printf("%d\n", x);

    x = pop(&n);
    printf("%d\n", x);

    return 0;
}

void push(stack* stk, int c) {
    if (stk->top == STACK_SIZE - 1) // top son indisi tutuyorsa doludur
        printf("\nStack dolu\n\n");
    else {
        stk->top++;
        stk->data[stk->top] = c;
    }
}

void reset(stack* stk) {
    stk->top = -1;
}

int pop(stack* stk) {
    if (stk->top == -1) // stack boþ mu diye kontrol ediliyor
        printf("Stack bos");
    else {
        int indis = stk->top--; // -- operatörünün iþlem sýrasýna dikkat
        //return indis;                 // çýkarýlan elemanýn indis deðeriyle geri dönüyor
        return stk->data[indis]; // // çýkarýlan elemanýn deðeriyle geri dönüyor
    }
}

boolean isEmpty(stack* stk) {
    return(stk->top == -1); // parantez içerisindeki ifadeye dikkat
}

boolean isFull(stack* stk) {
    return(stk->top == STACK_SIZE);
}


