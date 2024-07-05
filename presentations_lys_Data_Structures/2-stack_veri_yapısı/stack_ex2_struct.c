#include <stdio.h>

typedef enum { false, true }boolean;
#define STACK_SIZE 10

typedef struct {
    int data[STACK_SIZE]; // ihtiyaca g�re veri t�r� de�i�ebilir
    int top;
    /* s�rekli eleman ekleme ve silme i�lemi yap�laca�� i�in en �stteki
    * eleman�n indisini tutan top ad�nda bir de�i�ken tan�mlad�k */
}stack;


void push(stack* stk, int c);
void reset(stack* stk);
boolean isEmpty(stack* stk);
boolean isFull(stack* stk);
int pop(stack* stk);
/* peek i�lemi ???*/

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
    if (stk->top == -1) // stack bo� mu diye kontrol ediliyor
        printf("Stack bos");
    else {
        int indis = stk->top--; // -- operat�r�n�n i�lem s�ras�na dikkat
        //return indis;                 // ��kar�lan eleman�n indis de�eriyle geri d�n�yor
        return stk->data[indis]; // // ��kar�lan eleman�n de�eriyle geri d�n�yor
    }
}

boolean isEmpty(stack* stk) {
    return(stk->top == -1); // parantez i�erisindeki ifadeye dikkat
}

boolean isFull(stack* stk) {
    return(stk->top == STACK_SIZE);
}


