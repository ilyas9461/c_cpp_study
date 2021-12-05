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

/*		Makrolar ve sabitlerle ilgili tanýmlamlar	*/

#define clear_console() system("CLS")	//Konsolu temizlemek için oluþturulmuþ makro.

/* Bölümlerin tam isimlerinin oluþturulduðu sabit tanýmlamalarý*/
#define ECE "Electronics and Communication Engineering"
#define MIS "Management Information Systems"
#define COMP "Computer Engineering"
#define EEE "Electrical and Electronics Engineering"
#define SENG "Software Engineering"

/* Okul dönemi ilgili sabit tanýmlamalarý */
#define FALL "Fall"
#define SPRING "Spring"

/*	Oluþturulan trascriptin nasýl yazýlacaðýný belirten tanýmlamalar*/
#define PRINT_TOTAL			1
#define PRINT_SEQUENTIAL	0	

/* Toplam ders sayýsýný belirten sabit tanýmlamasý*/
#define TOTAL_COURSE_COUNT 5

/*		Yapýlarla (struct) ile ilgili çeþitli tanýmlamalar */

typedef struct{
	char number[10];
	char name[30];
	char surname[30];
	char dep_code[11];
	char *deparment;
}student;
/*	Öðrencilerile ilgili bilgilerin tutulduðu yapý.
	öðrenciler dosyasýndan gelen verileri tutar.
*/

typedef struct {
	char course_code[15];
	char course_title[50];
	int credit;
	char grade[3];
	float credit_earn;
}courses;
/*	Derslerle ilgili biligileri tutan yapý.
	Dersler dosaysýndan gelen bilgiler ve hesaplanan
	bilgileri tutar.
*/

typedef struct {
	char number[10];
	char year[10];
	char semestre;
	char course_code[10];
}student_registration;
/*	Öðrencilerin dönemlik kayýt olduklarý derslerle ilgili 
	bilgileri tutan yapý 
*/

typedef struct {
	char coures_code[10];
	int credit;
	int criter[3];
}course_criteria;
/* Derselerin baþarý kriterleri ile ilgili bilgileri tutan yapý*/

typedef struct {
	char student_number[10];
	char course_code[10];
	int performances[3];
}students_performances;
/*	Öðrencilerin derslerin sýnavalarýndan aldýklarý puan bilgilerini
	uygun formatta tutan yapý 
*/

/*	 Global deðiþkenlerin oluþturulmasý	*/

/* Tanýmlanan yapýlarla ilgili deðiþkenler */

//Buradaki deðiþkenlere her bir öðrenci için bir trascript oluþturulurken 
//gerekli olan bilgiler ilgili dosyalardan okunarak atanýr ve gerekli 
//hesaplamalar bu deðiþkenlerin tuttuðu bilgilere göre yapýlýrak konsola
//ve transcript dosya/dosyalarýna yazýlýr.

//Buna göre her bir deðiþken tip olarak tanýmlandýðý yapýya (struct) uygun
//verileri tutar. Burada tanýmlanarak programdaki her bir fonksiyon için 
//ulaþýlabilir olmalarý saðlanmýþtýr.

courses courses_data[TOTAL_COURSE_COUNT];				
student_registration student_regs[TOTAL_COURSE_COUNT];	
course_criteria course_criter[TOTAL_COURSE_COUNT];
students_performances performances[TOTAL_COURSE_COUNT];

/* Dosya tipinde deðiþkenler */
FILE* f_transcript;			// Toplam trascriptlerin yazýlacaðý dosya.
FILE* f_student_transcript; // Her bir öðrencinin transcritplerinin yazýlacaðý dosyalar için.

int id = 0;		// iþlemler menüsünde seçilen iþlem numarasýný tutar.

float total_credit_earn = 0.0;		// toplam kredi kazanýmý
float total_credit_hour = 0.0;		// toplam kredi saati

float grade_point_average_gpa = 0.0;//	GPA means Grade Point Average.
									//	GPA=(Total credit earned / Total credit hour) 

/*		Fonksiyon tanýmlalamalarý		*/

int process_selection(void);
/*  FONK	: int process_selection(void)
	Taným	: Menu halinde ekrana gelen iþlemlerin seçilip ilgili
			iþlemin çalýþtýrýlmasýný saðlayan fonksiyondur.

	Giriþ	: YOK
	Dönüþ	: Seçilen iþleme ait int tipinde bir sayý döndürür.	
*/
	
/*		Dosyalarýn içeriklerin listelendiði fonksiyonlar*/

// Final ödevinde belirtilen formatlara uygun olacak þekilde 
// dosyalara veriler,"Not Defteri" programý kullanýlarak elle girilmiþtir.
// Listeleme fonksiyonlarý hazýrlanan bu dosyalarýn belirtilen formatlara 
// uygun olup olmadýðýný test etmek için oluþturulmuþtur.

void student_list();	// "students.txt" dosyasýnda bulunan öðrencilere ait bilgileri listeler
void courses_list();	// "courses.txt" dosyasýnda bulunan derslere ait bilgileri listeler.
void student_course_registration_list();  //"registrations.txt" dsoyasýnda bulunan öðrenci 
										  // ders kayýlarýna ait bilgileri listeler.	
void course_criteria_list();	//"criteria.txt" dosyasýnda buluna ders kriterlerine ait bilgileri
								// listeler
void studentsCoursePerformancesList(); // "performances.txt" dosyasýnda bulunan öðrencilerin derslere
									   // ait puanlarýnýn olduðu kayýtlarý listeler. 

/*		Transcript oluþturmak için gerekli olan fonksiyonlar*/

char* get_deparment(char* department_code);
/*	FONK	: char* get_deparment(char* department_code);
	Taným	:Öðrenci bilgilerinin kaydedildiði "students.txt" dosyasýnda bölüm 
			bilgileri kýsaltma olarak kaydedilmiþtir. Bu kýsaltmlara göre 
			bölümlerin tam isimlerinin getirilmesini saðlar.
	Giriþ	:Dosyadan okunan string bölüm kýsaltma kodu.
	Dönüþ	:String olarak bölüm tam ismi.

*/

void get_student_course_registrations(char* ogr_no, student_registration* ogr_reg);
/*	FONK	: void get_student_course_registrations(char* ogr_no, student_registration* ogr_reg);
	Taným	: Öðrencilere ait dönemlik bütün ders kayýtlarýný getitirir ve arguman olarak verilen 
			yapýya aktarýr.
	Giriþ	: String olarak bilgisi getirilecek öðrencini numarasý ve bilgilerin aktarýlacaðý
			student_registration yapý tipinde dizi deðiþken.
	Dönüþ	: Bu fonksiyon dönüþ þeklinde return kullanarak bir dönüþ içermez fakat giriþ olarak
			verilen yapý tipinin adresine gerekli olan biligileri tanýmlanan yapýya uygun olacak
			þekilde aktarýr.

*/

course_criteria get_course_criteria(char* course_code);
/*	FONK	: course_criteria get_course_criteria(char* course_code);
	Taným	: Öðrencilere ait ders kodu bilgilerine göre ilgili dersin baþarý kriterlerini
			dosyadan okuyarak tanýmlanan yapýya gönderir.
	Giriþ	: String olarak ders kodu.
	Dönüþ	: Ders kriter bilglierinin tutulduðu course_criteria yapý tipi.
*/

students_performances get_performances(char* student_number, char* course_code);
/*	FONK	: students_performances get_performances(char* student_number, char* course_code);
	Taným	: Öðrencilerin derslere ait sýnavlardan aldýklarý puanlarý dosyadan okuyarak tanýmlanan
			yapýya gönderir.
	Giriþ	: String olarak öðrenci numarasý ve ders kodu.
	Dönüþ	: Derslere ait puanlarýn tutulduðu students_performances yapý tipi.
*/

void get_courses_data(void);
/*	FONK	: void get_courses_data(void);
	Taným	: courses yapý tipindeki courses_data isimli global deðiþkene dosyadan her bir ders 
			için gerekli olan bilgileri gönderir.
	Giriþ	: YOK
	Dönüþ	: YOK
*/
void get_grade(void);
/*	FONK	: void get_grade(void);
	Taným	: Öðrencilerin kayýt olduklarý derslere ait hesaplanan baþarý puanlarýnýn harfsel 
			karþýlýklarýný, not deðerlerini ve buna baðlý olarak kazanýmlarýný hesaplar.
	Giriþ	: YOK
	Dönüþ	: YOK
*/
void insert_char_array(char* arr, int location, char ch);
/*	FONK	: void insert_char_array(char* arr, int location, char ch);
	Taným	: Girilen string ifadenin istenilen yerine bir karakter aklenilmesini saðlar.
			registrations.txt dosyasýnda derslere ait yýl bilgisi 201920 þeklinde kaydedilmiþken
			transkript çýktýsýnda 2019-20 þeklinde olmasý gerekmektedir. Bu fonksiyon kullanýlarak
			araya'-' karakteri eklenmiþtir.
	Giriþ	: String olarak derse ait yýl bilgisi, int tipinde string içersinde karakterin 
			ekleneceði konum, char tipinde eklenecek karakter.
	Dönüþ	: return kullanarak bir dönüþ tipi yok. Fakat girilen stringin adresine karakter eklenmiþ 
			durumu gönderilir. Yýl bilgisini tutan yapýdaki dizi eleman sayýsýna eklenecek elemanda 
			göz önüne alýnarak dikkat edilmelidir.
*/
char* str_fall_spring(char *semestre);
/*	FONK	:	char* str_fall_spring(char* semestre);
	Taným	: Girilen sömestre bilgisine göre  1 ve 2 rakamlarýnýn yerine Fall ve Spring getirerek
			trancript bu þekilde yazýlmasýný saðlar.
	Giriþ	: char tipinde sömestr bilgisi.
	Dönüþ	: String ifade

*/
void print_transcript(student _ogr, bool console_file);
/*	FONK	: void print_transcript(student _ogr, bool console_file);
	Taným	: Dosyalardan okunan ve hesaplanan bilgilerin istenilen formata uygun olarak konsola ve transcript 
			dosya/dosyalarýna yazýlmasýný saðlar.
	Giriþ	: student yapý tipinde öðrenci numarasý, bool tipinde yazdýrma iþlevinin toplu mu yoksa sýralý bir
			þekilde olmasýnýn seçilmesini saðlayan sabit.
	Dönüþ	: YOK
*/
void createsStudentsTranscripts(bool operation);
/*	FONK	: void createsStudentsTranscripts(bool operation);
	Taným	: Bütün öðrencilere ait bilgileri dosyadan okuyarak ilgili fonksiyonlarý çaðýrýp öðrencilerin 
			trascriptleri için gerekli bilgilerin hazýrlanmasýný ve  bu biligilerin uygun formatta 
			transcript olark konsol ve dosya/dosylarda oluþturulmasýný saðlar.
	Giriþ	: bool tipinde transcript yazýlma iþlvinin belireþldiði sabit.
	Dönüþ	:YOK.
*/

/*		Diðer fonksiyonlar*/
int get_total_number_of_records(FILE* f);
/*	FONK	: int get_total_number_of_records(FILE* f);
	Taným	: Verilen dosyanýn toplam satýr sayýsýný hesaplar.
	Giriþ	: FILE tipinde dosya ismi string ifadesinde tam yolu.
	Dönüþ	: int tipinde satýr sayýsý
*/

void press_key();
/*  FONK	: void press_key();
	Taným	: Konsola veri yazdýrýldýðýnda verinin bir karaktere basýncaya kadar kalmasýný saðlar.

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
	/*		Listeleme iþlemleri*/
	printf(".........................................................\n");
	printf("[1]. Student List\n");
	printf("[2]. Courses List\n");
	printf("[3]. Student Course Registration List\n");
	printf("[4]. Course Criteria List\n");
	printf("[5]. Students Course Performances List\n");
	/*					Transcript iþlemleri							*/	
	printf(".........................................................\n");
	printf("[6]. Create Students' TOTAL Transcripts.\n");
	printf("[7]. Create transcript and Write to Console Separately\n");
	printf("[8]. \n");
	printf(".........................................................\n");
	printf("[9]. Exit\n");
	printf(".........................................................\n");
	do {
		printf("\nWhat is your choice ? [1-9]: ");
		id = _getche() - '0';	//getche() :Karakter girilir girilmez okuma iþlemi gerçekleþir
								//Seçim karakter bir sayý olacaðý için '1'-'9' arasý karakterin
								//1-9 arasý sayýya çevirmek amacýyla '0' karakterinden çýkarýyoruz.
		printf("\n");

	} while (id < 1 || id>9);

	return id;
}

/* Dosyalarýn içerik formatlarýný doðrulamak için oluþturulmuþ liste fonksiyonlarý. */
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
		/* %-08s -> sola dayalý 8 bosluk býrakarak yazdýr.*/
		printf("%s\t%-08s %-30s %-10s\n","Line","Number","NAME-SURNAME","DEPARTMAN");
		printf("----------------------------------------------------------\n");

		do {
			fscanf(f, "%s %s %s %s", student_no, student_name, student_surname, student_deparment);
			// Foprmatlý olarak konsola yazdýrma
			printf("%02u\t%-8s %-15s %-15s %-8s\n", ++sn, student_no, student_name, student_surname, student_deparment);

			if (sn % 10 == 0) {
				press_key();
				clear_console();
				printf("Student List : %u\n\n", total_record);
				printf("%s\t%-08s %-30s %-10s\n", "Line", "Number", "NAME-SURNAME", "DEPARTMAN");
				printf("----------------------------------------------------------\n");
			}
			/* Satýr satýr konsola yazdýrma*/
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

/*  Transcriptleri hazýrlamak için gerekli fonksiyonlar...*/
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
	int total_course = get_total_number_of_records(f);	// ders sayýsný getir...
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
			fgets(buf, sizeof(buf), f);	//Dosyada derselere ait bilgiler farklý formatta yazýldýðý için tam satýr okunup 
										//ders kodu ve tam ismi ifadeden aþaðýdaki kodlar ile ayrýþtýrýlmýþtýr.

			char *code_title = strtok(buf, " ");				// Derse ait ilk boþluk karkaterine kadar olan ders kodu alnýr
			strcpy(courses_data[line].course_code, code_title);	// yapýdaki ilgili yere kopyalanýr.

			int space_count = 0;

			while (code_title!= NULL) {
				if (space_count++ > 0) //	Derse ait ilk boþluk karakterinden sonraki diðer karkaterlerin hepsi
									   //	dersin tam ismini içerir bundan sonraki bütün boþluk karakteri arasýndaki
									   //	ifadeleri yapýdaki ders ismi kýsmýna sýrayla ekle.	
				{
					strcat(courses_data[line].course_title, code_title);
					strcat(courses_data[line].course_title, " "); //aralarýna boþluk ekle
				}
				code_title = strtok(NULL, " ");	// boþluk karakterine göre stringi alt stringe ayýr.
			}

			int length = strlen(courses_data[line].course_title);

			for (size_t i = 0; i < length; i++)		// Elde edilen karakterler yeni satýr('\n') içeriyorsa onun 
													// yerine null karakter koyma iþlemi. Yapýlmazsa print formatýný 
													// bozuyor.
			{
				if (courses_data[line].course_title[i] == '\n')
					courses_data[line].course_title[i] = '\0';
			}

			line++;		//yeni satýr
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
			
			// puan = (Sýnav1_puan * Sýnav1_kriter)+(Sýnav2_puan * Sýnav2_kriter)+(Sýnav3_puan * Sýnav3_kriter) 
		}

		if (puan[i] > 90 && puan[i] < 100) {
			strcpy(courses_data[i].grade, "A");
			earn_index = 0;
		}

		// (89+1) neden ? Derse ait sonuc puan hesaplanýrken, kriter deðerleri % olduðundan
		// sonuc puan float çýkmaktadýr. Bu durumda da eðer hesaplanan puan 89-90 arasýnda 
		// bir float olursa harfsel karþýlýðý bulunamamaktadýr. 
		// Bundan dolayý if'lerdeki sýnýr deðerler +1 geniþletilmiþtir.

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

	/*  transcripler tek bir dosyaya yazdýrýlýyor... */

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

	/* Her bir öðrenciye ait transcript, öðrenci no ya göre ayrý ayrý dosyalara yazdýrýlýyor...*/

	char transcript_file_path[50]="TranscriptFiles/"; // Klasör sorgulamasý yapýlmadý, oluþturulmuþ kabul edildi.
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

	total_credit_hour = total_credit_earn = 0.0; // yeni öðrenci için deðiþkenler resetleniyor.
}

void createsStudentsTranscripts(bool operation) {
	student ogr;
	FILE *f = "SourceFiles/courses.txt";
	unsigned int total_course=get_total_number_of_records(f);	// ders sayýsný getir...
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
			
			get_grade(); //Derslere ait notlarý ve kazanýmlarý hesapla

			grade_point_average_gpa = total_credit_earn / total_credit_hour;

			print_transcript(ogr,operation);	//Oluþturulan verilere göre verielen formatta
												//transcriptleri konsola ve dosya/dosylara yazdýr.

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