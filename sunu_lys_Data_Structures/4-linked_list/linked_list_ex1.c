
#include <stdio.h>
#include <ctype.h>

#define clrConsole() system("cls")  // veya system("clear")
struct node {
	int data;
	struct node* next;
};

//struct node* head = NULL;

// Tek baðlý doðrusal listenin baþýna eleman eklemek
struct node* addhead(struct node* head, int key) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = head; // temp’in next’i þu anda head’i gösteriyor.
	/* Bazen önce listenin boþ olup olmadýðý kontrol edilir, ama gerekli deðil
	aslýnda. Çünkü boþ ise zaten head=NULL olacaktýr ve temp olan ilk düðümün
	next’i NULL gösterecektir. */
	head = temp; /* head artýk temp’in adresini tutuyor yani eklenen düðüm
	listenin baþý oldu. */
	return head;
}

struct node* addlast(struct node* head, int key) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	/* C++'ta struct node *temp = new node();
	* þeklinde kullanýlabileceðini unutmayýnýz. */
	temp->data = key;
	temp->next = NULL;
	struct node* temp2 = head;
	/* Aþaðýdaki while yapýsý traversal(dolaþma) olarak adlandýrýlýr */
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	return head;
}

/*
 * Creates a new node and inserts at middle of the linked list.
 * Yeni bir düðüm oluþturur ve baðlantýlý listenin ortasýna ekler.
 * Yani var olan düðümün baþ ve son elemanlarý arasýnda bir pozisyona 
 * yeni öðe ekler...
 */
void insertNodeAtMiddle(struct node* head,int data, int position)
{
	int i;
	struct node* newNode, * temp;

	newNode = (struct node*)malloc(sizeof(struct node));

	if (newNode == NULL)
	{
		printf("Unable to allocate memory.");
	}
	else
	{
		newNode->data = data; // Link data part
		newNode->next = NULL;

		temp = head;

		/*
		 * Traverse to the n-1 position
		 */
		for (i = 2; i <= position - 1; i++)
		{
			temp = temp->next;

			if (temp == NULL)
				break;
		}

		if (temp != NULL)
		{
			/* Link address part of new node */
			newNode->next = temp->next;

			/* Link address part of n-1 node */
			temp->next = newNode;

			printf("DATA INSERTED SUCCESSFULLY\n");
		}
		else
		{
			printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
		}
	}
	
}

// function to insert node into the middle 
// of the linked list 
void insertInToMiddle(struct node* head_ref, int data)
{	
	if (head_ref == NULL) {   // if list is empty 
		printf("UNABLE TO INSERT DATA into middle of list\n");
		return;
	}
	else {
		// made a new node 
		struct node* newNode= (struct node*)malloc(sizeof(struct node));
		newNode->data = data; // Link data part
		newNode->next = NULL;

		struct node* ptr = head_ref; //ptr is head of list
		int len = 0;
		// calculate length of the linked list 
		//, i.e, the number of nodes 
		while (ptr != NULL) {
			len++;
			ptr = ptr->next;
		}
		// 'count' the number of nodes after which 
		//  the new node is to be inserted 
		int count = ((len % 2) == 0) ? (len / 2) :
			(len + 1) / 2;
		ptr = head_ref;  //ptr again head of list (ptr is reset)...

		// 'ptr' points to the node after which  
		// the new node is to be inserted 
		while (count-- > 1)
			ptr = ptr->next;  //ptr moves through the list...
							  //It ends at the desired point(middle point).
		// insert the 'newNode' and adjust the 
		// required links 
		newNode->next = ptr->next;
		ptr->next = newNode;
		printf("\nDATA INSERTE into middle SUCCESSFULLY\n");
	}
}

void print_Middle(struct node* head)     //Function found the middle element in the linked list
{
	struct node* first_ptr = head;
	struct node* second_ptr = head;

	if (head != NULL)
	{
		//the only logic is to traverse the linked list with two pointers
		//one at normal speed and other twice the speed of first
		/*when the fast pointer reaches to the end, slow pointer will be in
		the middle of the linted list*/
		while (second_ptr != NULL && second_ptr->next != NULL)
		{
			second_ptr = second_ptr->next->next; //fast
			first_ptr = first_ptr->next;		 //slow 
		}
		printf("The middle element in the linked list is:- %d", first_ptr->data);  //slow 
	}
}

void insertInToMiddleTwoPointer(struct node** head_ref, int data)
{
	// if list is empty 
	if (*head_ref == NULL) {
		printf("UNABLE TO INSERT DATA into middle of list\n");
		return;
	}
	else {
		// made a new node 
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data; // Link data part
		newNode->next = NULL;

     	// assign values to the slow and fast  
		// pointers 
		struct node* slow = *head_ref;
		struct node* fast = (*head_ref)->next;

		while (fast && fast->next) {

			// move slow pointer to next node 
			slow = slow->next;

			// move fast pointer two nodes at a time 
			fast = fast->next->next;
		}

		// insert the 'newNode' and adjust the 
		// required links 
		newNode->next = slow->next;
		slow->next = newNode;
	}
}


void listinfo(struct node* head) {
	int i = 1;
	while (head != NULL) {
		printf("%d. Dugumunun Adresi = %p \n", i, head);
		printf("%d. Dugumunun verisi = %d \n", i, head->data);
		printf("%d. Dugumunun Bagli Oldugu Dugumun Adresi= %p\n\n", i, head->next);
		head = head->next;
		i++;
	}

	getch();
}


void print(struct node* head) {
	if (head == NULL) {
		printf("Listede eleman yok");
		return;
	}
	putch('\n');

	struct node* temp2 = head;
	while (temp2 != NULL) { // temp2->next!=NULL koþulu olsaydý son düðüm yazýlmazdý
		printf("%d -> ", temp2->data);
		temp2 = temp2->next;
	}
	printf("\"NULL\"\n");
	putch('\n');

	getch();
}

//Tek baðlý liste elemanlarýný özyinelemeli yazdýrmak
void print_recursive(struct node* head) {
	if (head == NULL)
		return;
	printf("%d\t", head->data);
	print_recursive(head->next);
}



int main()
{
	int secim, data;
	int pos = 0;
	struct node* head = NULL;
	

	while (1) {
		clrConsole();

		printf("1-Listenin Basina Eleman Ekle\n");
		printf("2-Listenin Sonuna Eleman Ekle\n");
		printf("3-Listenin Ortasýnda Bir Yer Eleman Ekle\n");
		printf("4-Listenin Ortasina Eleman Ekle\n");
		
		printf("-Listeden verilen bir degere sahip dugum silmek\n");
		printf("-Listeyi sil\n");
		printf("-Listedeki eleman sayisi\n");
		printf("15-Listeyi Yazdirma\n");
		printf("16-Listenin tum eleman bilgileri\n");

		printf("20-Programdan Cikma\n");

		printf("\nSeciminiz....?");

		scanf("%d", &secim);

		clrConsole();
		switch (secim)
		{
		case 1:
			printf("Eklemek istediginiz degerini giriniz..?");
			scanf("%d", &data);

			head = addhead(head, data);

			break;
		case 2:
			printf("Eklemek istediginiz degerini giriniz..?");
			scanf("%d", &data);

			head = addlast(head, data);

			break;
		case 3:
			
			printf("Veri ve pozisyon giriniz ?");
			scanf("%d %u", &data,&pos);
			insertNodeAtMiddle(head,data, pos);
			getch();
			break;

		case 4:
			printf("Ortaya Eklenecek Veri  giriniz ?");
			scanf("%d", &data);
			//insertInToMiddle(head, data);
			insertInToMiddleTwoPointer(head, data);
			getch();
			break;


			
		case 15:
			print(head);
			break;

		case 16:
			listinfo(head);
			break;
		case 20:
			exit(1);
			break;
		default: printf("Yanlis secim\n");
			break;

		}//switch

	}//while(1)
	return 0;
}	//main



