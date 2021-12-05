#include <stdio.h>
#include <string.h>

char *returnArr(char* str)
{
    char c_sabit[] = "string";
    /*1. tanımlama şekli*/
    //static char retbuf[100];
    /* 2. tanımlama şekli */
    char *retbuf = malloc(100);  // Bellekten 100 elemanlık yer alınır

    sprintf(retbuf, "%s-%s", c_sabit, str);

    return retbuf;
}

int main()
{
    char *var_arr;
    char in_str[50];

    var_arr = returnArr("Sabit");
    printf("\n%s \n", var_arr);

    printf("\nInput String :");
    scanf("%s", in_str);
    var_arr = returnArr(in_str);
    printf("\n%s \n", var_arr);

    return 0;
}