// C program for array implementation of queue 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

typedef enum { false, true }boolean;

#define QUEUE_SIZE 10
typedef struct {
	int front; // Hat�rlatma, sadece dizi indislerini tutacaklar� i�in int t�rden
	int rear;
	int cnt;
	int *data;
}queue;

/*queue yap�s�n� kullanmadan �nce initialize etmek gerekir.
Fonksiyon olduk�a basittir ve yap� de�i�kenlerinin
ilk de�erlerini vermektedir*/
queue* initialize(unsigned capacity);

/* Kuyruk bo� mu? Eleman say�s�n� tutan cnt yap� de�i�keni 0 ise kuyruk bo�tur ve geriye true
d�nd�r�l�r.E�er cnt 0�dan b�y�kse kuyrukta eleman vard�r ve geriye false 
de�eri d�nd�r�l�r.*/
boolean isEmpty(queue* q);


/*Kuyruk dolu mu? Eleman say�s�n� tutan cnt yap� de�i�keni QUEUE_SIZE�a e�it ise kuyruk doludur
ve geriye true d�nd�r�l�r.E�er cnt QUEUE_SIZE�dan k���kse kuyrukta dolu de�ildir
ve geriye false de�eri
d�nd�r�l�r.*/
boolean isFull(queue* q);

/*Bir kuyru�a eleman ekleme fonksiyonu enqueue olarak bilinir ve bu fonksiyon, 
kuyru�un adresini ve eklenecek eleman�n de�erini parametre olarak al�r.Geri 
d�n�� de�eri olmayaca�� i�in t�r� void olmal�d�r.Ayr�ca eleman ekleyebilmek 
i�in kuyru�un dolu olmamas� gerekir.
Eleman eklendikten sonra rear de�i�keni en son eklenen eleman�n indis de�erini tutmaktad�r*/
void enqueue(queue* q, int x);

/*Kuyruktan eleman ��karmak dequeue olarak bilinir. �lk giren eleman� ��karmak demektir.
��kar�lan eleman�n veri de�eriyle geri d�nece�i i�in fonksiyonun tipi int olmal�d�r.*/
int dequeue(queue* q);

// Kuyruktan ��kar�lacak eleman
int front(queue* q);

// Kuyuru�un en son eleman�
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
		q->rear++; // ekleme �ncesi rear artt�r�l�yor
		q->cnt++;
		if (q->rear == QUEUE_SIZE)
			q->rear = 0;
		/* Ekleme yapmadan �nce rear 1 artt�r�l�yordu. Kuyruk dolu olmayabilir fakat
		rear indeksi dizinin son indisini g�steriyor olabilir. B�yle bir durumda
		dizide ta�ma hatas� olmamas� i�in rear�in de�eri kontrol ediliyor. rear son
		indisi g�steriyor ve kuyruk dolu de�ilse rear de�eri 0�a set ediliyor */
		q->data[q->rear] = x;
	}
}

int dequeue(queue* q) 
{
	if (!isEmpty) { // kuyruk bo� mu diye kontrol ediliyor
		int x = q->data[q->front]; // front de�erinin saklanmas� gerekiyor
		q->front++;
		q->cnt--;
		if (q->front == QUEUE_SIZE)
			/* front dizinin sonunu g�steriyor olabilir. Dizi ta�ma hatas� olmamas�
			i�in kontrol edilmesi gerekir. */
			q->front = 0;
		return x; // ��kar�lan eleman�n data de�eriyle �a�r�ld��� yere geri d�n�yor
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