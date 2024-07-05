/*	COMP124 Computer Programming
	2019-2020 Spring FINAL ASSIGNMENT
	IDE: Visual Studio 2019
	........
	.........
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>

/*		Makrolar ve sabitlerle ilgili tan�mlamlar	*/

#define clear_console() system("CLS")	//Konsolu temizlemek i�in olu�turulmu� makro.

/* B�l�mlerin tam isimlerinin olu�turuldu�u sabit tan�mlamalar�*/
#define ECE "Electronics and Communication Engineering"
#define MIS "Management Information Systems"
#define COMP "Computer Engineering"
#define EEE "Electrical and Electronics Engineering"
#define SENG "Software Engineering"

/* Okul d�nemi ilgili sabit tan�mlamalar� */
#define FALL "Fall"
#define SPRING "Spring"

/*	Olu�turulan trascriptin nas�l yaz�laca��n� belirten tan�mlamalar*/
#define PRINT_TOTAL			1
#define PRINT_SEQUENTIAL	0	

/* Toplam ders say�s�n� belirten sabit tan�mlamas�*/
#define TOTAL_COURSE_COUNT 5

/*		Yap�larla (struct) ile ilgili �e�itli tan�mlamalar */

typedef struct{
	char number[10];
	char name[30];
	char surname[30];
	char dep_code[11];
	char *deparment;
}student;
/*	��rencilerile ilgili bilgilerin tutuldu�u yap�.
	��renciler dosyas�ndan gelen verileri tutar.
*/

typedef struct {
	char course_code[15];
	char course_title[50];
	int credit;
	char grade[3];
	float credit_earn;
}courses;
/*	Derslerle ilgili biligileri tutan yap�.
	Dersler dosays�ndan gelen bilgiler ve hesaplanan
	bilgileri tutar.
*/

typedef struct {
	char number[10];
	char year[10];
	char semestre;
	char course_code[10];
}student_registration;
/*	��rencilerin d�nemlik kay�t olduklar� derslerle ilgili 
	bilgileri tutan yap� 
*/

typedef struct {
	char coures_code[10];
	int credit;
	int criter[3];
}course_criteria;
/* Derselerin ba�ar� kriterleri ile ilgili bilgileri tutan yap�*/

typedef struct {
	char student_number[10];
	char course_code[10];
	int performances[3];
}students_performances;
/*	��rencilerin derslerin s�navalar�ndan ald�klar� puan bilgilerini
	uygun formatta tutan yap� 
*/

/*	 Global de�i�kenlerin olu�turulmas�	*/

/* Tan�mlanan yap�larla ilgili de�i�kenler */

//Buradaki de�i�kenlere her bir ��renci i�in bir trascript olu�turulurken 
//gerekli olan bilgiler ilgili dosyalardan okunarak atan�r ve gerekli 
//hesaplamalar bu de�i�kenlerin tuttu�u bilgilere g�re yap�l�rak konsola
//ve transcript dosya/dosyalar�na yaz�l�r.

//Buna g�re her bir de�i�ken tip olarak tan�mland��� yap�ya (struct) uygun
//verileri tutar. Burada tan�mlanarak programdaki her bir fonksiyon i�in 
//ula��labilir olmalar� sa�lanm��t�r.

courses courses_data[TOTAL_COURSE_COUNT];				
student_registration student_regs[TOTAL_COURSE_COUNT];	
course_criteria course_criter[TOTAL_COURSE_COUNT];
students_performances performances[TOTAL_COURSE_COUNT];

/* Dosya tipinde de�i�kenler */
FILE* f_transcript;			// Toplam trascriptlerin yaz�laca�� dosya.
FILE* f_student_transcript; // Her bir ��rencinin transcritplerinin yaz�laca�� dosyalar i�in.

int id = 0;		// i�lemler men�s�nde se�ilen i�lem numaras�n� tutar.

float total_credit_earn = 0.0;		// toplam kredi kazan�m�
float total_credit_hour = 0.0;		// toplam kredi saati

float grade_point_average_gpa = 0.0;//	GPA means Grade Point Average.
									//	GPA=(Total credit earned / Total credit hour) 

/*		Fonksiyon tan�mlalamalar�		*/

int process_selection(void);
/*  FONK	: int process_selection(void)
	Tan�m	: Menu halinde ekrana gelen i�lemlerin se�ilip ilgili
			i�lemin �al��t�r�lmas�n� sa�layan fonksiyondur.

	Giri�	: YOK
	D�n��	: Se�ilen i�leme ait int tipinde bir say� d�nd�r�r.	
*/
	
/*		Dosyalar�n i�eriklerin listelendi�i fonksiyonlar*/

// Final �devinde belirtilen formatlara uygun olacak �ekilde 
// dosyalara veriler,"Not Defteri" program� kullan�larak elle girilmi�tir.
// Listeleme fonksiyonlar� haz�rlanan bu dosyalar�n belirtilen formatlara 
// uygun olup olmad���n� test etmek i�in olu�turulmu�tur.

void student_list();	// "students.txt" dosyas�nda bulunan ��rencilere ait bilgileri listeler
void courses_list();	// "courses.txt" dosyas�nda bulunan derslere ait bilgileri listeler.
void student_course_registration_list();  //"registrations.txt" dsoyas�nda bulunan ��renci 
										  // ders kay�lar�na ait bilgileri listeler.	
void course_criteria_list();	//"criteria.txt" dosyas�nda buluna ders kriterlerine ait bilgileri
								// listeler
void studentsCoursePerformancesList(); // "performances.txt" dosyas�nda bulunan ��rencilerin derslere
									   // ait puanlar�n�n oldu�u kay�tlar� listeler. 

/*		Transcript olu�turmak i�in gerekli olan fonksiyonlar*/

char* get_deparment(char* department_code);
/*	FONK	: char* get_deparment(char* department_code);
	Tan�m	:��renci bilgilerinin kaydedildi�i "students.txt" dosyas�nda b�l�m 
			bilgileri k�saltma olarak kaydedilmi�tir. Bu k�saltmlara g�re 
			b�l�mlerin tam isimlerinin getirilmesini sa�lar.
	Giri�	:Dosyadan okunan string b�l�m k�saltma kodu.
	D�n��	:String olarak b�l�m tam ismi.

*/

void get_student_course_registrations(char* ogr_no, student_registration* ogr_reg);
/*	FONK	: void get_student_course_registrations(char* ogr_no, student_registration* ogr_reg);
	Tan�m	: ��rencilere ait d�nemlik b�t�n ders kay�tlar�n� getitirir ve arguman olarak verilen 
			yap�ya aktar�r.
	Giri�	: String olarak bilgisi getirilecek ��rencini numaras� ve bilgilerin aktar�laca��
			student_registration yap� tipinde dizi de�i�ken.
	D�n��	: Bu fonksiyon d�n�� �eklinde return kullanarak bir d�n�� i�ermez fakat giri� olarak
			verilen yap� tipinin adresine gerekli olan biligileri tan�mlanan yap�ya uygun olacak
			�ekilde aktar�r.

*/

course_criteria get_course_criteria(char* course_code);
/*	FONK	: course_criteria get_course_criteria(char* course_code);
	Tan�m	: ��rencilere ait ders kodu bilgilerine g�re ilgili dersin ba�ar� kriterlerini
			dosyadan okuyarak tan�mlanan yap�ya g�nderir.
	Giri�	: String olarak ders kodu.
	D�n��	: Ders kriter bilglierinin tutuldu�u course_criteria yap� tipi.
*/

students_performances get_performances(char* student_number, char* course_code);
/*	FONK	: students_performances get_performances(char* student_number, char* course_code);
	Tan�m	: ��rencilerin derslere ait s�navlardan ald�klar� puanlar� dosyadan okuyarak tan�mlanan
			yap�ya g�nderir.
	Giri�	: String olarak ��renci numaras� ve ders kodu.
	D�n��	: Derslere ait puanlar�n tutuldu�u students_performances yap� tipi.
*/

void get_courses_data(void);
/*	FONK	: void get_courses_data(void);
	Tan�m	: courses yap� tipindeki courses_data isimli global de�i�kene dosyadan her bir ders 
			i�in gerekli olan bilgileri g�nderir.
	Giri�	: YOK
	D�n��	: YOK
*/
void get_grade(void);
/*	FONK	: void get_grade(void);
	Tan�m	: ��rencilerin kay�t olduklar� derslere ait hesaplanan ba�ar� puanlar�n�n harfsel 
			kar��l�klar�n�, not de�erlerini ve buna ba�l� olarak kazan�mlar�n� hesaplar.
	Giri�	: YOK
	D�n��	: YOK
*/
void insert_char_array(char* arr, int location, char ch);
/*	FONK	: void insert_char_array(char* arr, int location, char ch);
	Tan�m	: Girilen string ifadenin istenilen yerine bir karakter aklenilmesini sa�lar.
			registrations.txt dosyas�nda derslere ait y�l bilgisi 201920 �eklinde kaydedilmi�ken
			transkript ��kt�s�nda 2019-20 �eklinde olmas� gerekmektedir. Bu fonksiyon kullan�larak
			araya'-' karakteri eklenmi�tir.
	Giri�	: String olarak derse ait y�l bilgisi, int tipinde string i�ersinde karakterin 
			eklenece�i konum, char tipinde eklenecek karakter.
	D�n��	: return kullanarak bir d�n�� tipi yok. Fakat girilen stringin adresine karakter eklenmi� 
			durumu g�nderilir. Y�l bilgisini tutan yap�daki dizi eleman say�s�na eklenecek elemanda 
			g�z �n�ne al�narak dikkat edilmelidir.
*/
char* str_fall_spring(char *semestre);
/*	FONK	:	char* str_fall_spring(char* semestre);
	Tan�m	: Girilen s�mestre bilgisine g�re  1 ve 2 rakamlar�n�n yerine Fall ve Spring getirerek
			trancript bu �ekilde yaz�lmas�n� sa�lar.
	Giri�	: char tipinde s�mestr bilgisi.
	D�n��	: String ifade

*/
void print_transcript(student _ogr, bool console_file);
/*	FONK	: void print_transcript(student _ogr, bool console_file);
	Tan�m	: Dosyalardan okunan ve hesaplanan bilgilerin istenilen formata uygun olarak konsola ve transcript 
			dosya/dosyalar�na yaz�lmas�n� sa�lar.
	Giri�	: student yap� tipinde ��renci numaras�, bool tipinde yazd�rma i�levinin toplu mu yoksa s�ral� bir
			�ekilde olmas�n�n se�ilmesini sa�layan sabit.
	D�n��	: YOK
*/
void createsStudentsTranscripts(bool operation);
/*	FONK	: void createsStudentsTranscripts(bool operation);
	Tan�m	: B�t�n ��rencilere ait bilgileri dosyadan okuyarak ilgili fonksiyonlar� �a��r�p ��rencilerin 
			trascriptleri i�in gerekli bilgilerin haz�rlanmas�n� ve  bu biligilerin uygun formatta 
			transcript olark konsol ve dosya/dosylarda olu�turulmas�n� sa�lar.
	Giri�	: bool tipinde transcript yaz�lma i�lvinin belire�ldi�i sabit.
	D�n��	:YOK.
*/

/*		Di�er fonksiyonlar*/
int get_total_number_of_records(FILE* f);
/*	FONK	: int get_total_number_of_records(FILE* f);
	Tan�m	: Verilen dosyan�n toplam sat�r say�s�n� hesaplar.
	Giri�	: FILE tipinde dosya ismi string ifadesinde tam yolu.
	D�n��	: int tipinde sat�r say�s�
*/

void press_key();
/*  FONK	: void press_key();
	Tan�m	: Konsola veri yazd�r�ld���nda verinin bir karaktere bas�ncaya kadar kalmas�n� sa�lar.

*/

/* Ana fonnksiyon	*/	
int main(void) {
	do {
		printf("\n");
		id = process_selection();
		switch (id) {
		case 1:
			student_list();
			press_key();
			break;
		case 2:
			courses_list();
			press_key();
			break;
		case 3:
			student_course_registration_list();
			press_key();
			break;
		case 4:
			course_criteria_list();
			press_key();
			break;
		case 5:
			studentsCoursePerformancesList();
			press_key();
			break;
		case 6:
			createsStudentsTranscripts(PRINT_TOTAL);
			press_key();
			break;
		case 7:
			createsStudentsTranscripts(PRINT_SEQUENTIAL);
			press_key();
			break;
		}
	} while (id != 9);


	return 0;
}//main

/*	Alt fonksiyonlar	*/

int process_selection(void)
{
	int id;

	clear_console();
	printf(".........................................................\n");
	printf("\n		## Menu Process ##\n\n");
	/*		Listeleme i�lemleri*/
	printf(".........................................................\n");
	printf("[1]. Student List\n");
	printf("[2]. Courses List\n");
	printf("[3]. Student Course Registration List\n");
	printf("[4]. Course Criteria List\n");
	printf("[5]. Students Course Performances List\n");
	/*					Transcript i�lemleri							*/	
	printf(".........................................................\n");
	printf("[6]. Create Students' TOTAL Transcripts.\n");
	printf("[7]. Create transcript and Write to Console Separately\n");
	printf("[8]. \n");
	printf(".........................................................\n");
	printf("[9]. Exit\n");
	printf(".........................................................\n");
	do {
		printf("\nWhat is your choice ? [1-9]: ");
		id = _getche() - '0';	//getche() :Karakter girilir girilmez okuma i�lemi ger�ekle�ir
								//Se�im karakter bir say� olaca�� i�in '1'-'9' aras� karakterin
								//1-9 aras� say�ya �evirmek amac�yla '0' karakterinden ��kar�yoruz.
		printf("\n");

	} while (id < 1 || id>9);

	return id;
}

/* Dosyalar�n i�erik formatlar�n� do�rulamak i�in olu�turulmu� liste fonksiyonlar�. */
void student_list() {
	FILE* f= "SourceFiles/students.txt";
	int total_record = get_total_number_of_records(f);
	char buf[50];
	int sn = 0;

	char student_no[50];
	char student_name[50];
	char student_surname[50];
	char student_deparment[15];

	clear_console();
	fflush(stdout);

	f = fopen("SourceFiles/students.txt", "r");
	if (f != NULL) {
		printf("Student List : %u\n\n",total_record);
		//printf("Number\tNAME-SURNAME\t\tDEPARTMAN\n");
		/* %-08s -> sola dayal� 8 bosluk b�rakarak yazd�r.*/
		printf("%s\t%-08s %-30s %-10s\n","Line","Number","NAME-SURNAME","DEPARTMAN");
		printf("----------------------------------------------------------\n");

		do {
			fscanf(f, "%s %s %s %s", student_no, student_name, student_surname, student_deparment);
			// Foprmatl� olarak konsola yazd�rma
			printf("%02u\t%-8s %-15s %-15s %-8s\n", ++sn, student_no, student_name, student_surname, student_deparment);

			if (sn % 10 == 0) {
				press_key();
				clear_console();
				printf("Student List : %u\n\n", total_record);
				printf("%s\t%-08s %-30s %-10s\n", "Line", "Number", "NAME-SURNAME", "DEPARTMAN");
				printf("----------------------------------------------------------\n");
			}
			/* Sat�r sat�r konsola yazd�rma*/
			//fgets(buf,sizeof(buf), f);
			//printf("%s", buf);
		} while (!feof(f));
		fclose(f);
	}
	else printf("FILE NONE...\n");
	
	
}

void courses_list() {
	FILE* f;
	char buf[100];

	clear_console();
	fflush(stdout);

	f = fopen("SourceFiles/courses.txt", "r");
	if (f != NULL) {
		printf("Courses List :\n\n");
		printf("Code	Name\n");
		printf("---------------\n");
		
		do {
			fgets(buf, sizeof(buf),f);
			printf("%s", buf);

		} while (!feof(f));
		fclose(f);

	}
	else printf("FILE NONE...\n");
}

void student_course_registration_list() {
	FILE* f;
	char buf[100];

	clear_console();
	fflush(stdout);

	f = fopen("SourceFiles/registrations.txt", "r");
	if (f != NULL) {
		printf("Student Course Registration List :\n\n");
		printf("Number|Years|Semester|Course Code|\n");
		printf("---------------------------------------\n");
		do {
			fgets(buf, sizeof(buf), f);
			printf("%s", buf);

		} while (!feof(f));
		fclose(f);

	}
	else printf("FILE NONE...\n");
}

void course_criteria_list() {
	FILE* f;
	char buf[100];

	clear_console();
	fflush(stdout);

	f = fopen("SourceFiles/criteria.txt", "r");
	if (f != NULL) {
		printf("Course Criteria List :\n\n");
		printf("Code   |Cr|E1|E2|E3|\n");
		printf("-----------------------\n");
		do {
			fgets(buf, sizeof(buf), f);
			printf("%s", buf);

		} while (!feof(f));
		fclose(f);

	}
	else printf("FILE NONE...\n");
}

void studentsCoursePerformancesList() {
	FILE* f= "SourceFiles/performances.txt";
	int total_records = get_total_number_of_records(f);
	char student_number[25];
	char course_code[25];
	int criteria[5];
	int line = 0;
	clear_console();
	fflush(stdout);
	f = fopen("SourceFiles/performances.txt", "r");
	if (f != NULL) {
		printf("Students Course Performances List : %u\n\n",total_records);
		printf("Number\tCode\tEx1\tEx2\tEx3\t\n");			//Ex: Examine
		printf("------------------------------------\n");
		do {
			fscanf(f, "%s %s %u %u %u", student_number, course_code, &criteria[0], &criteria[1], &criteria[2]);
			printf("%s\t%-10s%3u\t%3u\t%3u\n", student_number, course_code, criteria[0], criteria[1], criteria[2]);
			line++;
			if (line % 15 == 0) {
				press_key();
				clear_console();

				printf("Students Course Performances List : %u\n\n", total_records);
				printf("Number\tCode\tEx1\tEx2\tEx3\t\n");
				printf("------------------------------------\n");
				
			}


		} while (!feof(f));
		fclose(f);
	}
}

/*  Transcriptleri haz�rlamak i�in gerekli fonksiyonlar...*/
char* get_deparment(char* department_code) {

	if (strcmp(department_code, "ECE") == 0) return ECE;
	if (strcmp(department_code, "MIS") == 0) return MIS;
	if (strcmp(department_code, "COMP") == 0) return COMP;
	if (strcmp(department_code, "EEE") == 0) return EEE;
	if (strcmp(department_code, "SENG") == 0) return SENG;

	return '\0';
}

void get_student_course_registrations(char *ogr_no, student_registration *ogr_reg) {
	FILE* f = "SourceFiles/courses.txt";
	int total_course = get_total_number_of_records(f);	// ders say�sn� getir...
	student_registration reg;
	int course_count = 0;

	f = fopen("SourceFiles/registrations.txt", "r");
	if (f != NULL) {
		do {
			fscanf(f, "%s %s %c %s", reg.number, reg.year, &reg.semestre, reg.course_code);
			if (strcmp(ogr_no, reg.number) == 0) {
				ogr_reg[course_count++] = reg;
			}
			if (course_count >= total_course) break;
		} while (!feof(f));
		fclose(f);
	}
	else printf("FILE NONE...\n");

}

course_criteria get_course_criteria(char *course_code) {
	course_criteria criteria = { 0 };
	FILE* f;
	f = fopen("SourceFiles/criteria.txt", "r");
	if (f != NULL) {
		do {
			fscanf(f, "%s %u %u %u %u",
				criteria.coures_code, &criteria.credit, &criteria.criter[0], &criteria.criter[1], &criteria.criter[2]);
			if (strcmp(course_code, criteria.coures_code) == 0) {
				return criteria;
				fclose(f);
			}
		
		} while (!feof(f));
		fclose(f);

	}
	else printf("FILE NONE...\n");
	return criteria;;
}

students_performances get_performances(char *student_number,char* course_code) {
	students_performances perform = { 0 };
	FILE* f;
	f = fopen("SourceFiles/performances.txt", "r");
	if (f != NULL) {
		do {
			fscanf(f, "%s %s %u %u %u", 
				perform.student_number, perform.course_code, &perform.performances[0], &perform.performances[1], &perform.performances[2]);
			if (strcmp(student_number, perform.student_number) == 0) {
				if (strcmp(course_code, perform.course_code) == 0) {
					fclose(f);
					return perform;
				}
			}
		} while (!feof(f));
		fclose(f);
	}
	else printf("FILE NONE...\n");
	return perform;
}

void get_courses_data(void) {
	
	FILE* f;
	char buf[50] = { '\0' };
	int line = 0;
	int size_of_courses_data = sizeof(courses_data);
	memset(courses_data, '\0', size_of_courses_data);

	f = fopen("SourceFiles/courses.txt", "r");
	if (f != NULL) {
		do {
			fgets(buf, sizeof(buf), f);	//Dosyada derselere ait bilgiler farkl� formatta yaz�ld��� i�in tam sat�r okunup 
										//ders kodu ve tam ismi ifadeden a�a��daki kodlar ile ayr��t�r�lm��t�r.

			char *code_title = strtok(buf, " ");				// Derse ait ilk bo�luk karkaterine kadar olan ders kodu aln�r
			strcpy(courses_data[line].course_code, code_title);	// yap�daki ilgili yere kopyalan�r.

			int space_count = 0;

			while (code_title!= NULL) {
				if (space_count++ > 0) //	Derse ait ilk bo�luk karakterinden sonraki di�er karkaterlerin hepsi
									   //	dersin tam ismini i�erir bundan sonraki b�t�n bo�luk karakteri aras�ndaki
									   //	ifadeleri yap�daki ders ismi k�sm�na s�rayla ekle.	
				{
					strcat(courses_data[line].course_title, code_title);
					strcat(courses_data[line].course_title, " "); //aralar�na bo�luk ekle
				}
				code_title = strtok(NULL, " ");	// bo�luk karakterine g�re stringi alt stringe ay�r.
			}

			int length = strlen(courses_data[line].course_title);

			for (size_t i = 0; i < length; i++)		// Elde edilen karakterler yeni sat�r('\n') i�eriyorsa onun 
													// yerine null karakter koyma i�lemi. Yap�lmazsa print format�n� 
													// bozuyor.
			{
				if (courses_data[line].course_title[i] == '\n')
					courses_data[line].course_title[i] = '\0';
			}

			line++;		//yeni sat�r
		} while (!feof(f));
		fclose(f);
	}

}

void get_grade(void) {
						//	 A  , A- , B+ , B  , B- , C+ , C  , C- , D+ , D  , D- , F
	const float earn[12] = { 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 1.3, 1.0, 0.7, 0.0 };
	int earn_index = 11;
	total_credit_earn = 0.0;

	float puan[TOTAL_COURSE_COUNT] = { 0 };
	
	for (size_t i = 0; i < TOTAL_COURSE_COUNT; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			puan[i] +=(float) (performances[i].performances[j] * course_criter[i].criter[j]/100.0f);
			
			// puan = (S�nav1_puan * S�nav1_kriter)+(S�nav2_puan * S�nav2_kriter)+(S�nav3_puan * S�nav3_kriter) 
		}

		if (puan[i] > 90 && puan[i] < 100) {
			strcpy(courses_data[i].grade, "A");
			earn_index = 0;
		}

		// (89+1) neden ? Derse ait sonuc puan hesaplan�rken, kriter de�erleri % oldu�undan
		// sonuc puan float ��kmaktad�r. Bu durumda da e�er hesaplanan puan 89-90 aras�nda 
		// bir float olursa harfsel kar��l��� bulunamamaktad�r. 
		// Bundan dolay� if'lerdeki s�n�r de�erler +1 geni�letilmi�tir.

		if (puan[i] > 85 && puan[i] < (89+1)) {
			strcpy(courses_data[i].grade, "A-");
			earn_index = 1;
		}
		if (puan[i] > 80 && puan[i] < (84+1)) {
			strcpy(courses_data[i].grade, "B+");
			earn_index = 2;
		}
		if (puan[i] > 75 && puan[i] < (79+1)) {
			strcpy(courses_data[i].grade, "B");
			earn_index = 3;
		}
		if (puan[i] > 70 && puan[i] < (74+1)) {
			strcpy(courses_data[i].grade, "B-");
			earn_index = 4;
		}
		if (puan[i] > 65 && puan[i] <(69+1)) {
			strcpy(courses_data[i].grade, "C+");
			earn_index = 5;
		}
		if (puan[i] > 60 && puan[i] < (64+1)) {
			strcpy(courses_data[i].grade, "C");
			earn_index = 6;
		}
		if (puan[i] > 55 && puan[i] < (59 + 1)) {
			strcpy(courses_data[i].grade, "C-");
			earn_index = 7;
		}
		if (puan[i] > 50 && puan[i] < (54 + 1)) {
			strcpy(courses_data[i].grade, "D+");
			earn_index = 8;
		}
		if (puan[i] > 45 && puan[i] < (49 + 1)) {
			strcpy(courses_data[i].grade, "D");
			earn_index = 9;
		}
		if (puan[i] > 40 && puan[i] < (44 + 1)) {
			strcpy(courses_data[i].grade, "D-");
			earn_index = 10;
		}
		if (puan[i] > 0 && puan[i] < (39 + 1)) {
			strcpy(courses_data[i].grade, "F");
			earn_index = 11;
		}
		courses_data[i].credit_earn = earn[earn_index] * course_criter[i].credit;

		total_credit_earn += courses_data[i].credit_earn;

	}
}

void insert_char_array(char* arr, int location, char ch) {

	int len = strlen(arr);
	for (size_t i = len; i>=location; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[location - 1] = ch;
	arr[len+1] = '\0';		// diziyi string yap.
}

char *str_fall_spring(char *semestre) {

	if (semestre == '1') return FALL;
	if (semestre == '2') return SPRING;

	return '\0';
}

void print_transcript(student _ogr, bool console_file) {
	
	insert_char_array(student_regs[0].year, 5, '-');
	char *str_semestre=str_fall_spring(student_regs[0].semestre);

	printf("---------------------------------------------------------------------------------------\n");
	printf("Name\t\t:%s\n", _ogr.name);
	printf("Surname\t\t:%s\n", _ogr.surname);
	printf("Student No\t:%s\n", _ogr.number);
	printf("Department\t:%s\n", _ogr.deparment);
	printf("-----------------------------------------------------------------------------------------\n");
	printf("Academic year :%s Semester : %s\n", student_regs[0].year, str_semestre);
	printf("-----------------------------------------------------------------------------------------\n");
	printf("%-15s%-35s\t%s\t%s\t%s\n", "Course Code", "Course Title", "Credit", "Grade", "Credit earned");
	for (size_t i = 0; i < TOTAL_COURSE_COUNT; i++)
	{
		printf("%-15s%-35s\t%u\t%s\t%3.1f\n",
			student_regs[i].course_code, courses_data[i].course_title, course_criter[i].credit, courses_data[i].grade, courses_data[i].credit_earn);
	}
	printf("-----------------------------------------------------------------------------------------\n");
	printf("Total credit earned: %3.1f\n", total_credit_earn);
	printf("Total credit hour: %3.1f\n", total_credit_hour);
	printf("GPA: %3.2f \n", grade_point_average_gpa);
	printf("-----------------------------------------------------------------------------------------\n");

	/*  transcripler tek bir dosyaya yazd�r�l�yor... */

	fprintf(f_transcript,"---------------------------------------------------------------------------------------\n");
	fprintf(f_transcript, "Name\t\t:%s\n", _ogr.name);
	fprintf(f_transcript, "Surname\t\t:%s\n", _ogr.surname);
	fprintf(f_transcript, "Student No\t:%s\n", _ogr.number);
	fprintf(f_transcript, "Department\t:%s\n", _ogr.deparment);
	fprintf(f_transcript, "-----------------------------------------------------------------------------------------\n");
	fprintf(f_transcript, "Academic year :%s Semester : %s\n", student_regs[0].year, str_semestre);
	fprintf(f_transcript, "-----------------------------------------------------------------------------------------\n");
	fprintf(f_transcript, "%-15s%-35s\t%s\t%s\t%s\n", "Course Code", "Course Title", "Credit", "Grade", "Credit earned");
	for (size_t i = 0; i < TOTAL_COURSE_COUNT; i++)
	{
		fprintf(f_transcript, "%-15s%-35s\t%u\t%s\t%3.1f\n",
			student_regs[i].course_code, courses_data[i].course_title, course_criter[i].credit, courses_data[i].grade, courses_data[i].credit_earn);
	}
	fprintf(f_transcript, "-----------------------------------------------------------------------------------------\n");
	fprintf(f_transcript, "Total credit earned: %3.1f\n", total_credit_earn);
	fprintf(f_transcript, "Total credit hour: %3.1f\n", total_credit_hour);
	fprintf(f_transcript, "GPA: %3.2f \n", grade_point_average_gpa);
	fprintf(f_transcript, "-----------------------------------------------------------------------------------------\n");

	/* Her bir ��renciye ait transcript, ��renci no ya g�re ayr� ayr� dosyalara yazd�r�l�yor...*/

	char transcript_file_path[50]="TranscriptFiles/"; // Klas�r sorgulamas� yap�lmad�, olu�turulmu� kabul edildi.
	strcat(transcript_file_path, _ogr.number);
	strcat(transcript_file_path, ".txt");

	f_student_transcript = fopen(transcript_file_path,"w");
	if (f_student_transcript != NULL) {

		fprintf(f_student_transcript, "---------------------------------------------------------------------------------------\n");
		fprintf(f_student_transcript, "Name\t\t:%s\n", _ogr.name);
		fprintf(f_student_transcript, "Surname\t\t:%s\n", _ogr.surname);
		fprintf(f_student_transcript, "Student No\t:%s\n", _ogr.number);
		fprintf(f_student_transcript, "Department\t:%s\n", _ogr.deparment);
		fprintf(f_student_transcript, "-----------------------------------------------------------------------------------------\n");
		fprintf(f_student_transcript, "Academic year :%s Semester : %s\n", student_regs[0].year, str_semestre);
		fprintf(f_student_transcript, "-----------------------------------------------------------------------------------------\n");
		fprintf(f_student_transcript, "%-15s%-35s\t%s\t%s\t%s\n", "Course Code", "Course Title", "Credit", "Grade", "Credit earned");
		for (size_t i = 0; i < TOTAL_COURSE_COUNT; i++)
		{
			fprintf(f_student_transcript, "%-15s%-35s\t%u\t%s\t%3.1f\n",
				student_regs[i].course_code, courses_data[i].course_title, course_criter[i].credit, courses_data[i].grade, courses_data[i].credit_earn);
		}
		fprintf(f_student_transcript, "-----------------------------------------------------------------------------------------\n");
		fprintf(f_student_transcript, "Total credit earned: %3.1f\n", total_credit_earn);
		fprintf(f_student_transcript, "Total credit hour: %3.1f\n", total_credit_hour);
		fprintf(f_student_transcript, "GPA: %3.2f \n", grade_point_average_gpa);
		fprintf(f_student_transcript, "-----------------------------------------------------------------------------------------\n");

		fclose(f_student_transcript);
	}
	else {
		press_key();
		clear_console();
		printf("FILE NOE:%s", transcript_file_path);
	}

		
	if (console_file == PRINT_SEQUENTIAL) {
		press_key();
		clear_console();
	}

	total_credit_hour = total_credit_earn = 0.0; // yeni ��renci i�in de�i�kenler resetleniyor.
}

void createsStudentsTranscripts(bool operation) {
	student ogr;
	FILE *f = "SourceFiles/courses.txt";
	unsigned int total_course=get_total_number_of_records(f);	// ders say�sn� getir...
	total_credit_hour = 0.0;

	get_courses_data();		//derslere ait verileri getir

	f_transcript = fopen("TranscriptFiles/total_transcript.txt", "w");
	f = fopen("SourceFiles/students.txt", "r");

	clear_console();
	fflush(stdout);

	if (f != NULL) {
		do {
			fscanf(f, "%s %s %s %s", ogr.number, ogr.name,ogr.surname,ogr.dep_code);
			ogr.deparment = get_deparment(ogr.dep_code);

			get_student_course_registrations(ogr.number, student_regs);

			for (size_t i = 0; i < TOTAL_COURSE_COUNT; i++)
			{
				course_criter[i] = get_course_criteria(student_regs[i].course_code);
				performances[i] = get_performances(student_regs[i].number, student_regs[i].course_code);
				total_credit_hour += course_criter[i].credit;
			}
			
			get_grade(); //Derslere ait notlar� ve kazan�mlar� hesapla

			grade_point_average_gpa = total_credit_earn / total_credit_hour;

			print_transcript(ogr,operation);	//Olu�turulan verilere g�re verielen formatta
												//transcriptleri konsola ve dosya/dosylara yazd�r.

		} while (!feof(f));
		fclose(f);
		fclose(f_transcript);
	}
}

int get_total_number_of_records(FILE* f) {
	int line = 0;
	char buf[100];
	FILE* _file;
	_file = fopen(f, "r");
	if (f != NULL) {
		do {
			fgets(buf, sizeof(buf), _file);
			line++;
		} while (!feof(_file));
		fclose(_file);
	}
	else line = -1;
	return line;
}

void press_key() {
	char ch = 0;
	printf("\n\nPress a key to continue...\n\n");
	while (ch == 0) {
		ch = _getche();  // Error C4996 'getch':The POSIX name for this item is deprecated.Instead, use the ISO Cand C++ conformant name : _getch
	}
}