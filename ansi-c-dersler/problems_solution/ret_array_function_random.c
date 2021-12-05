
#include <stdio.h>

/* function to generate and return random numbers */
int *getRandom() {

    static int  r[10];
    int i;

    /* set the seed */
    srand((unsigned)time(NULL));

    for (i = 0; i < 10; i++) {
        r[i] = rand()%100;
        printf("r[%d] = %d\n", i, r[i]);
    }

    return r;
}

/* main function to call above defined function */
int main() {

    /* a pointer to an int */
    int *p;
    int i;

    p = getRandom();

    for (i = 0; i < 10; i++) {
        printf("*(p + %d) : %d\n", i, *(p + i));  // *(p + i) ile p[i] ayn� i�lemi yap�yor.
    }

    return 0;
}