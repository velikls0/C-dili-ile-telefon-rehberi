#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

FILE *dosya;// i�lem yap�lacak ak��� tan�mlayan FILE nesnesi i�aret�isidir

char isim[30];// isim de�i�keni sil ve guncelle i�in kullan�ld� 
int sorgula;// telefon fonksiyonun sorgulanmas�nda atama i�in gerkeli tan�mlama ayr� ayr� tan�mlamamk i�in burada

// rehber bilgilerinin tutulaca�� yap� olu�turuldu
struct rehber{ 
	
	char ad[60];     
	char soyad[60];  
	char tel[60]; 
}reh;

// kullanilan fonksiyonlar
int telefon(char x[12]);
void KisiEkle();                    
void Guncelle(char ad[60]);
void Sil(char ad[60]);     
void Listele();    
void Arama();

// ana fonksiyon
int main(){
	
	system("color 71");// konsolun rengini 7 sayesinde gri yapar
	
    int islem, cikis, cevap;// islemler i�in tan�mlama
    
    system("cls");// ekran� temizlemek i�in
    
    printf("\t\t\t-------TELEFON REHBERI SISTEMINE HOSGELDINIZ-------\n\n ");
    
    do{
    	
        printf("\n\t\t\t\t1. Yeni kisi olustur");
		printf("\n\t\t\t\t2. Mevcut kisiyi guncelle");
		printf("\n\t\t\t\t3. Mevcut kisiyi sil");
		printf("\n\t\t\t\t4. Mevcut kisiyi ara");
		printf("\n\t\t\t\t5. Mevcut kisileri listele");
		printf("\n\t\t\t\t6. Programdan cik");
		
		printf("\n\t\tLutfen yapmak istediginiz islemi seciniz:");
		scanf("%d", &islem);
		
		switch(islem){
        	
            case 1: 
            	
            	printf("Kisi ekleme yapmak istiyor musunuz?(e/h): \n");
				scanf("%s", &cevap);
				
				while(cevap == 'e'){
					
					KisiEkle();
					
				}
            	break;
            case 2: 
            	
            	printf("Guncelleme yapmak istiyor musunuz?(e/h): \n");
				scanf("%s", &cevap);
				
				while(cevap == 'e'){
					
					printf("Guncellenilecek kisini ismini giriniz: ");
					scanf("%s", &isim);
					Guncelle(isim);
					
					printf("Devam etmek istiyor musunuz?(e/h): \n");
					scanf("%s", &cevap);
					
				}
            	break;
            case 3: 
				
				printf("Silme yapmak istiyor musunuz?(e/h): \n");
				scanf("%s", &cevap);
				
				while(cevap == 'e'){
					
					printf("Silinecek kisinin kayitli adini giriniz: ");
					scanf("%s", &isim);
					Sil(isim);
					
					printf("Devam etmek istiyor musunuz?(e/h): \n");
					scanf("%s", &cevap);
					
				}
            	break;
            case 4: 
            	
            	printf("Arama yapmak istiyor musunuz?(e/h): \n");
				scanf("%s", &cevap);
				
				while(cevap == 'e'){
					
					Arama();
					
					printf("Devam etmek istiyor musunuz?(e/h): \n");
					scanf("%s", &cevap);
					
				}
            	break;
            case 5: 
				Listele();
            	break;
            case 6:
            	printf("\n\t\t>>Program sonlandirildi<<\n\n");	
            	exit(1);
            	break;
            default:
				printf("\n\tYanlis sayi girdiniz!\n\n");
				break;
        }
        
        printf("Cikis yapmak istiyor musunuz? Evet ise '1' hayir ise '0' giriniz! ");
        scanf("%d", &cikis);
        
        system("cls");// ekran� temizlemek i�in
        
    }while(cikis != 1);
    
    printf("\n\t\t>>Program sonlandirildi<<\n\n");
    
return 0;
}

// 11 haneli numara kontrol fonksiyonu
int telefon(char x[12]){
	
	int dogru = 0, yanlis = 1;
	
	if (x[11] != NULL || x[10] == NULL || x[9] == NULL || x[8] == NULL || x[7] == NULL || x[6] == NULL || x[5] == NULL || x[4] == NULL || x[3] == NULL || x[2] == NULL || x[1] == NULL){
		
		printf(">Telefon numaraniz 11 haneli olmali ve 0-9 arasi rakam icermelidir!<\n"); 
		
		return dogru;
	}
	else{
		
		return yanlis;
	} 
}

// yeni ki�i olu�turma fonksiyonu
void KisiEkle(){ 

	dosya = fopen("telrehber.txt", "a+");// kisilerin kaydedilece�i dosya olu�turuldu
	rewind(dosya);// dosya parametresi ile g�sterilen ak���n aktif dosya konumunu en ba�a al�r
	
	int kNo = 1;
	char cevap;
	
	if (dosya == NULL){ // e�er dosya a��lamaz ise bir uyar� verir
	
		printf("Dosya acilamadi!!"); 
	}
	else{
		
		system("cls");	// ekran� temizlemek i�in
		
		int kNo = 1;
		
		do{
			
			dosya = fopen("telrehber.txt", "a");// kisilerin kaydedilece�i dosya olu�turuldu
			
			printf("\t\t<<%d. Kayit>>\n\n", kNo);	
			printf("\tYeni kisinin adi             : ");						
			scanf("%s", &reh.ad);
			fprintf(dosya, "%s ", reh.ad);
			printf("\tYeni kisinin soyadi          : ");					
			scanf("%s", &reh.soyad);
			fprintf(dosya, "%s ", reh.soyad);
			
			do{
		
				printf("\tYeni kisinin telefon numarasi: ");					 // %d yapt�k ama 11 hane alm�yor
				scanf("%s", &reh.tel);
				sorgula = telefon(reh.tel);//al�nan telefon numaras� char tipinde telefon fonksiyonuna g�nderilip sorgulan�or
			} while (sorgula != 1);
			
			fprintf(dosya, "%s ", reh.tel);		//do�ru bilgi al�nd�ktan sonra d�nen fonksiyondaki parametre yazd�r�l�or...
		
			printf("\n\t>%d. Kisi eklendi<\n\n", kNo);
			
			kNo++;
			
			fclose(dosya); // olu�turulan dosya kapat�ld�
			
			printf("Devam etmek istiyor musunuz?(e/h): \n");
			scanf("%s", &cevap);
			
			if(cevap == 'h'){
				
				main();
			}
			
			
			
		}while(cevap == 'e');
		
	}
}

// ki�iyi g�ncelleme fonksiyonu
void Guncelle(char ad[60]){
	
	FILE *dosya, *yenidosya;// i�lem yap�lacak ak��� tan�mlayan FILE nesnesi i�aret�isidir
	
	int k = 0;// ki�inin rehberde kay�tl� olup olmad��� sorgulanmak amac� ile tan�mland�
	
	system("cls");// ekran� temizlemek i�in
	
	dosya = fopen("telrehber.txt", "r");// bu dosyadan ad� al�r ve a�a��daki dosyada siler 
	yenidosya = fopen("telrehber1.txt", "w");// g�ncelleme i�in yeni dosya a��ld�	
	
	while (fscanf(dosya, "%s", &reh.ad) != EOF){ // dosyada bulunan adlar� EOF a kadar okur
	
		fscanf(dosya, "%s", &reh.soyad);		// dosyadan okunan di�er bilgiler
		fscanf(dosya, "%s", &reh.tel);		
		
		if (!strcmp(reh.ad, isim)){// aranan isimle Kar��la�t�rma yap�l�r do�ruysa ekrana yaz�d�r�l�r 
				
			printf("Guncellenecek Kisinin Bilgileri\n");
			printf("---------------------------------\n");
			printf("Ad           : %s\n", reh.ad);
			printf("Soyad        : %s\n", reh.soyad);
			printf("Cep telefonu : %s\n\n", reh.tel);
		}
	}
	
	if (dosya == NULL){// rehberde ki�i olup olmad��� kontrol eder
	
		printf("Suan rehberinizde hicbir kisi ekli degil!");
	}
	else{
	
		rewind(dosya);// dosya parametresi ile g�sterilen ak���n aktif dosya konumunu en ba�a al�r
		rewind(yenidosya);// yenidosya parametresi ile g�sterilen ak���n aktif dosya konumunu en ba�a al�r
		
		while (!feof(dosya)){// dosya sonuna kadar tarama yapar
		
			fscanf(dosya, "%s %s %s ", &reh.ad, &reh.soyad, &reh.tel);
			if (strcmp(reh.ad, ad) == 0){
				
				k = 1;
				printf("\nGuncellen Kisi Bilgiler\n");
				printf("-------------------------\n");
				printf("\tAd        : ");
				scanf("%s", reh.ad);
				printf("\tSoyad     : ");
				scanf("%s", reh.soyad);
				
				do{
					
					printf("\tTel No    : ");
					scanf("%s", &reh.tel);
					sorgula = telefon(reh.tel);// al�nan telefon numaras� char tipinde telefon fonksiyonuna g�nderilip sorgulan�or
				} while (sorgula != 1);
				
				printf("\n>Kisi guncellendi<\n\n");
				fprintf(yenidosya, "%s %s %s\t  \n", reh.ad, reh.soyad, reh.tel);
			} // G�ncellenicek ki�i dosyada tespit edilmi�se yeni bilgiler al�n�r ve dosyaya yazd�r�l�r e�er ki�i dosyada yok ise o dosya bilgiler oldu�u gibi yeni dosyaya yazd�r�l�r.	
			else{
				fprintf(yenidosya, "%s %s %s\t  \n", reh.ad, reh.soyad, reh.tel);
			}
		}
		
		_fcloseall(); // t�m dosyalar� kapat�r
		
		remove("telrehber.txt"); // ilk dosyay� siler
		rename("telrehber1.txt", "telrehber.txt"); // yeni dosyanon ad� de�i�tirilir ve ilk dosyan�n ad� yap�l�r
		
		if (k == 0){// dosya taramas� bo� ise uyar� verir
		
			printf("Bu kisi rehberde kayitli degildir...\n");
		}
	}
}

// ki�iyi silme fonksiyonu
void Sil(char ad[60]){
	
	system("cls");// ekran� temizlemek i�in
	
	FILE *dosya, *yenidosya;// i�lem yap�lacak ak��� tan�mlayan FILE nesnesi i�aret�isidir
	
	int a = 0, cevap;// burada a ki�inin rehberde kay�tl� olup olmad��� sorgulanmak amac� ile tan�mland�
	
	dosya = fopen("telrehber.txt", "r");// okuma modunda a��ld�
	yenidosya = fopen("telrehber1.txt", "w");// yazma modunda a��ld�
	
	if (dosya == NULL){// dosyada silecek ki�i yoksa uyar� verir

		printf("Suan rehberinizde hicbir kisi ekli degil!");
	}
	else{
	
		rewind(dosya);// dosya parametresi ile g�sterilen ak���n aktif dosya konumunu en ba�a al�r
		rewind(yenidosya);// yenidosya parametresi ile g�sterilen ak���n aktif dosya konumunu en ba�a al�r
		
		printf("\n%s kisisini silmek istediginize emin misiniz?\n1. Evet\n2. Hayir\n", isim);// ad� girilen ki�inin silinmesine emin olunulumas�n� sorar
		scanf("%d", &cevap);
		
		if (cevap == 1){
		
			while (!feof(dosya)){// dosya sonuna kadar okutuldu ve dosyadan bilgiler al�nd�
			
				fscanf(dosya, "%s %s %s ", &reh.ad, &reh.soyad, &reh.tel);
				if (!strcmp(reh.ad, ad)){// dosyadaki t�m adlar� tarar ve girilen isim ile e�itse bu k�s�ma girer ve bu ki�i hari� di�er ki�ileri yeni dosyaya yazar b�ylece ki�i silinmi� olur
				
					printf("\n\t\t<<Silinen Kisi Bilgileri>>\n");
					printf("\tAd:\t%s\n\tSoyad:  %s\n\tCepTel: %s\n\n", reh.ad, reh.soyad, reh.tel);
					printf("\n\t>Kisi silindi<\n"); 
					a = 1;
				}
				else{// bu k�s�mada ki�i yoksa girer b�ylece t�m dosya bilgiler de�i�tirilmeden yeni metin belgesine yazd�r�lm�� olur
					fprintf(yenidosya, "%s %s %s\t  \n", reh.ad, reh.soyad, reh.tel);
				}
			}
			
			_fcloseall();// t�m dosyalar kapat�ld�
			
			remove("telrehber.txt");// dosyas silindi	
			rename("telrehber1.txt", "telrehber.txt");// ve yeni olu�turulan dosyada silindi ve eski isimde tekrar dosya olu�turuldu
			
			if (a == 0)// ki�i rehberde de�ilse uyar� verir
				printf("\nKisi rehberde kayitli degil!\n");
		}
		else if (cevap == 2){// cevap hay�r ise ��kt� verir ve ne yapmak istedi�ini sorar
			
			printf("Cevabiniz HAYIR..\n "); 
		}
		else { // herhangibi yanl�� tu� bas�m� olursa s�rekli olarak ayn� �eyi soracak
		
			Sil(isim);
		}
	}
}

// kay�tl� ki�ileri listeleme fonksiyonu
void Listele(){
	
	dosya = fopen("telrehber.txt", "r");	// okuma modunda a��lm��t�r
	
	char secim;
	
	if (dosya == NULL){// dosya a��lmassa NULL de�eri gelir buna gore istenilen ger�ekle�tirilir
	
		printf("Suan rehberinizde hicbir kisi ekli degil!\nEkleme yapmak icin (e) tusuna basiniz!\n");// rehber olu�turulmam��sa bu uyar� g�sterilir
		scanf("%s", &secim);
			
		system("cls");// ekran� temizlemek i�in
			
		if (secim == 'e'){
			
			KisiEkle(); 
		}			
		else{
			
			printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
		}
	}
	else{ // dosya �nceden varsa kisi eklenebilir
		
		system("cls");// ekran� temizlemek i�in
		
		printf("Telefon Rehberi \n");
		printf("---------------\n\n");
		
		while (fscanf(dosya, "%s %s %s", &reh.ad, &reh.soyad, &reh.tel) != EOF){	// dosya sonu belirteci EOF a kadar okunur ve ekrana yazd�r�l�r. 
		
			printf("Ad:\t%s\nSoyad:  %s\nCepTel: %s\n\n", reh.ad, reh.soyad, reh.tel);
		}
		
		fclose(dosya);// dosya kapat�ld�
	}
}

void Arama(){
	
	system("cls");// ekran� temizlemek i�in

	char isim[30];
	int flag = 0;
	
	dosya = fopen("telrehber.txt", "r");
	
	if (dosya == NULL){
	
		printf("Dosya veya sunucu bulunamadi!\n"); 
	}
	else{
		
		system("cls");// ekran� temizlemek i�in
		
		printf("Aranan kisinin adini giriniz: ");
		scanf("%s", &isim);
		printf("\n"); 
		
		rewind(dosya);// dosya parametresi ile g�sterilen ak���n aktif dosya konumunu en ba�a al�r
		
		while (fscanf(dosya, "%s", &reh.ad) != EOF){ // dosyada bulunan adlar� EOF a kadar okur
	
			fscanf(dosya, "%s", &reh.soyad);		// dosyadan okunan di�er bilgiler
			fscanf(dosya, "%s", &reh.tel);		
		
			if (!strcmp(reh.ad, isim)){// aranan isimle Kar��la�t�rma yap�l�r do�ruysa ekrana yaz�d�r�l�r 
		
				printf("Kisi Bilgileri\n");
				printf("--------------\n");
				printf("Ad           : %s\n", reh.ad);
				printf("Soyad        : %s\n", reh.soyad);
				printf("Cep telefonu : %s\n\n", reh.tel);
				printf("%s kisisi araniyor..\n\n", reh.ad);
				flag = 1;
			}
		}
		
		if (flag == 0){

			printf("\nBu kisi rehberde kayitli degil!\n\n");
		}
	}
}
