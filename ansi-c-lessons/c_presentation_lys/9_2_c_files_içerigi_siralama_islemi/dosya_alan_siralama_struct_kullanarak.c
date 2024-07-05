 void siralama_islemi(){
	FILE *f_sirala = "sirala.txt";//fopen("sirala.txt", "r");
	int satir_sys = satir_sayisi_bul(f_sirala);
	int i= 0,j=0;
	//Bellek ayırma işlemi dinamik yapılarak txt dosya boyutundaki değişimlere göre ayarlanabilir.
	//arama_islemi() bakınız.
	SONUC s[7];		//sabit bellek ayırma işlemi
	SONUC temp;

	f_sirala = fopen("sirala.txt", "r");
	while (!feof(f_sirala)){
		fscanf(f_sirala, "%s %s %s %s %s %s %s",
			  &s[i].ogrenci.no,&s[i].ogrenci.ad,&s[i].ogrenci.soyad,&s[i].ogrenci.bolum,&s[i].dogru,&s[i].yanlis,&s[i].puan);
		i++;
	}
	i = j = 0;
	fclose(f_sirala);

	for ( i = 0; i < satir_sys; i++)
	{
		for (j = 0; j < satir_sys - 1; j++){

			if (atof(s[j].puan) < atof(s[i].puan)){   //büyükten küçüğe doğru sıralama...(ascending)

				memcpy(&temp, &s[i], sizeof(s[j]));	//hedef,kaynak, size
				memcpy(&s[i], &s[j], sizeof(s[j]));
				memcpy(&s[j], &temp, sizeof(s[j]));
			}
		}
		
	}

	ekrani_temizle();
	f_sirala = fopen("sirala.txt", "w");
	//fprintf(f_sirala, "NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
	printf("NO\t AD-SOYAD \t\tBOLUM \tDOGRU \tYANLIS \tPUAN\n");
	
	for (i = 0; i < satir_sys; i++){
		//Dosyaya yaz..
		fprintf(f_sirala, "%s %s %s %s %s %s %s\n",
			s[i].ogrenci.no, s[i].ogrenci.ad, s[i].ogrenci.soyad, s[i].ogrenci.bolum, s[i].dogru, s[i].yanlis, s[i].puan);
		//Ekrana yaz
		printf("%s\t%s %s\t\t%s\t%s\t%s\t%s\n",
			s[i].ogrenci.no, s[i].ogrenci.ad, s[i].ogrenci.soyad, s[i].ogrenci.bolum, s[i].dogru, s[i].yanlis, s[i].puan);
	}
	fclose(f_sirala);
	
}