#include <stdio.h>

//https://beginnersbook.com/2014/01/c-passing-pointers-to-functions/

void salaryhike(int *var, int b)
{
    *var = *var + b;  // formal parametre var adres ise *var adresteki deðer olur.
                      // ve adresteki deðer deðiþir.
}

int main()
{
    int salary = 0, bonus = 0;

    printf("Enter the employee current salary:");
    scanf("%d", &salary);
    printf("Enter bonus:");
    scanf("%d", &bonus);
    // salary deðiþkeninn adresi giriþ parametresi olarak veriliyor.
    // böylece salary deðiþkeninin deðeri fonksiyon içinden adresindeki
    // deðer deðiþtirilerek güncelleniyor
    salaryhike(&salary, bonus);

    printf("Final salary: %d", salary);
    return 0;
}