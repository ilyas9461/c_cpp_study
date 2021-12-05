
/* struct ve union kullanarak bir karakterin ASCI ve BINARY 
   olarak gösterilmesi ...*/

#include <stdio.h>
#include <conio.h>

struct binary_8bit {
	unsigned char uid1 : 1;  // unsigned char yerine unsigend kullanılabilir.
	unsigned char uid2 : 1;	// iki nokta char tipindeki değişkenin  kaç bit olacağını belirtmek için kullanılır.
	unsigned char uid3 : 1; // kullnılmazsa tipin bit sayısı kadardır.
	unsigned char uid4 : 1;
	unsigned char uid5 : 1;
	unsigned char uid6 : 1;
	unsigned char uid7 : 1;
	unsigned char uid8 : 1; // 8. biti temsil ederr.
};

union ikili {

	char char_deger;			// Oluşturulan her iki üyede aynı bellek alanını paylaşır.
	struct binary_8bit ikili;	// Her ikiside 8 bit olduğu için char_deger üyesine atanan değer 
								// struct ile bitlere ayrılmış olur.

} union_bin_deger;

void fonk_charToBinary(char cd);

int main(void)
{

	printf("ASCII -> BINARY karakter ? ");
	scanf("%c", &union_bin_deger.char_deger);
	printf("\n				128 64 32 16 8 4 2 1\n");
	//union_bin_deger.char_deger = 65; /* 'A' 0100 0001 */
	printf("\nKarakter: %c , ASCII: %d , ", union_bin_deger.char_deger,union_bin_deger.char_deger);

	printf("Binary : ");

	if (union_bin_deger.ikili.uid8) printf("1 ");
	else printf("0 ");

	if (union_bin_deger.ikili.uid7) printf("1 ");
	else printf("0 ");

	if (union_bin_deger.ikili.uid6) printf("1 ");
	else printf("0 ");

	if (union_bin_deger.ikili.uid5) printf("1 ");
	else printf("0 ");

	if (union_bin_deger.ikili.uid4) printf("1 ");
	else printf("0 ");

	if (union_bin_deger.ikili.uid3) printf("1 ");
	else printf("0 ");

	if (union_bin_deger.ikili.uid2) printf("1 ");
	else printf("0 ");

	if (union_bin_deger.ikili.uid1) printf("1 ");
	else printf("0 ");

	printf("\n\nKarakter: %c , ASCII: %d , ", union_bin_deger.char_deger, union_bin_deger.char_deger);

	printf("Binary : ");
	
	fonk_charToBinary(union_bin_deger.char_deger);

	_getch();
}

void fonk_charToBinary(char cd)
{
	int _8bit_degeri=128; //1 byte yani, 8bit unsigned bir sayıda 8. bitin onlu değer karşılığı.
						  // (1000 0000)=128 

	for (_8bit_degeri = 128; _8bit_degeri>0; _8bit_degeri /= 2)  // 
	{
		if (cd & _8bit_degeri)	// bit şeklinde mantıksal and işlemi yap.
			 printf("1 ");
		else printf("0 ");
	}
	printf("\n");
}