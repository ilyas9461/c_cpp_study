// C program for array implementation of queue 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

typedef enum { false, true }boolean;

#define QUEUE_SIZE 10
typedef struct {
	int front; // Hatýrlatma, sadece dizi indislerini tutacaklarý için int türden
	int rear;
	int cnt;
	int *data;
}queue;

/*queue yapýsýný kullanmadan önce initialize etmek gerekir.
Fonksiyon oldukça basittir ve yapý deðiþkenlerinin
ilk deðerlerini vermektedir*/
queue* initialize(unsigned capacity);

/* Kuyruk boþ mu? Eleman sayýsýný tutan cnt yapý deðiþkeni 0 ise kuyruk boþtur ve geriye true
döndürülür.Eðer cnt 0’dan büyükse kuyrukta eleman vardýr ve geriye false 
deðeri döndürülür.*/
boolean isEmpty(queue* q);


/*Kuyruk dolu mu? Eleman sayýsýný tutan cnt yapý deðiþkeni QUEUE_SIZE’a eþit ise kuyruk doludur
ve geriye true döndürülür.Eðer cnt QUEUE_SIZE’dan küçükse kuyrukta dolu deðildir
ve geriye false deðeri
döndürülür.*/
boolean isFull(queue* q);

/*Bir kuyruða eleman ekleme fonksiyonu enqueue olarak bilinir ve bu fonksiyon, 
kuyruðun adresini ve eklenecek elemanýn deðerini parametre olarak alýr.Geri 
dönüþ deðeri olmayacaðý için türü void olmalýdýr.Ayrýca eleman ekleyebilmek 
için kuyruðun dolu olmamasý gerekir.
Eleman eklendikten sonra rear deðiþkeni en son eklenen elemanýn indis deðerini tutmaktadýr*/
void enqueue(queue* q, int x);

/*Kuyruktan eleman çýkarmak dequeue olarak bilinir. Ýlk giren elemaný çýkarmak demektir.
Çýkarýlan elemanýn veri deðeriyle geri döneceði için fonksiyonun tipi int olmalýdýr.*/
int dequeue(queue* q);

// Kuyruktan çýkarýlacak eleman
int front(queue* q);

// Kuyuruðun en son elemaný
int rear(queue* q);
 
int main()
{
	queue *q1= initialize(QUEUE_SIZE);

	enqueue(q1, 10);
	enqueue(q1, 20);
	enqueue(q1, 30);
	enqueue(q1, 40);

	printf("%d dequeued from queue\n\n",
		dequeue(q1));

	printf("Front item is %d\n", front(q1));
	printf("Rear item is %d\n", rear(q1));

	return 0;
}

queue* initialize(unsigned capacity)
{
	queue* _queue = (queue*)malloc(sizeof(queue));
	_queue->front = 0;

	// This is important, see the enqueue 
	_queue->rear = capacity - 1;
	_queue->data = (int*)malloc(capacity * sizeof(int));

	return _queue;
}

boolean isEmpty(queue* q) 
{
	return(q->cnt == 0);
}

boolean isFull(queue* q) 
{
	return(q->cnt == QUEUE_SIZE);
}

void enqueue(queue* q, int x) 
{
	if (!isFull(q)) {
		// kuyruk dolu mu diye kontrol ediliyor
		q->rear++; // ekleme öncesi rear arttýrýlýyor
		q->cnt++;
		if (q->rear == QUEUE_SIZE)
			q->rear = 0;
		/* Ekleme yapmadan önce rear 1 arttýrýlýyordu. Kuyruk dolu olmayabilir fakat
		rear indeksi dizinin son indisini gösteriyor olabilir. Böyle bir durumda
		dizide taþma hatasý olmamasý için rear’in deðeri kontrol ediliyor. rear son
		indisi gösteriyor ve kuyruk dolu deðilse rear deðeri 0’a set ediliyor */
		q->data[q->rear] = x;
	}
}

int dequeue(queue* q) 
{
	if (!isEmpty) { // kuyruk boþ mu diye kontrol ediliyor
		int x = q->data[q->front]; // front deðerinin saklanmasý gerekiyor
		q->front++;
		q->cnt--;
		if (q->front == QUEUE_SIZE)
			/* front dizinin sonunu gösteriyor olabilir. Dizi taþma hatasý olmamasý
			için kontrol edilmesi gerekir. */
			q->front = 0;
		return x; // çýkarýlan elemanýn data deðeriyle çaðrýldýðý yere geri dönüyor
	}
}

int front(queue* q)
{
	if (isEmpty(q))
		return INT_MIN;
	return q->data[q->front];
}

int rear(queue* q)
{
	if (isEmpty(q))
		return INT_MIN;
	return q->data[q->rear];
}