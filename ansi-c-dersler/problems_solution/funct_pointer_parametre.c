#include <stdio.h>

//https://beginnersbook.com/2014/01/c-passing-pointers-to-functions/

void salaryhike(int *var, int b)
{
    *var = *var + b;  // formal parametre var adres ise *var adresteki de�er olur.
                      // ve adresteki de�er de�i�ir.
}

int main()
{
    int salary = 0, bonus = 0;

    printf("Enter the employee current salary:");
    scanf("%d", &salary);
    printf("Enter bonus:");
    scanf("%d", &bonus);
    // salary de�i�keninn adresi giri� parametresi olarak veriliyor.
    // b�ylece salary de�i�keninin de�eri fonksiyon i�inden adresindeki
    // de�er de�i�tirilerek g�ncelleniyor
    salaryhike(&salary, bonus);

    printf("Final salary: %d", salary);
    return 0;
}