#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

FILE *dosya;// iþlem yapýlacak akýþý tanýmlayan FILE nesnesi iþaretçisidir

char isim[30];// isim deðiþkeni sil ve guncelle için kullanýldý 
int sorgula;// telefon fonksiyonun sorgulanmasýnda atama için gerkeli tanýmlama ayrý ayrý tanýmlamamk için burada

// rehber bilgilerinin tutulacaðý yapý oluþturuldu
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
	
    int islem, cikis, cevap;// islemler için tanýmlama
    
    system("cls");// ekraný temizlemek için
    
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
        
        system("cls");// ekraný temizlemek için
        
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

// yeni kiþi oluþturma fonksiyonu
void KisiEkle(){ 

	dosya = fopen("telrehber.txt", "a+");// kisilerin kaydedileceði dosya oluþturuldu
	rewind(dosya);// dosya parametresi ile gösterilen akýþýn aktif dosya konumunu en baþa alýr
	
	int kNo = 1;
	char cevap;
	
	if (dosya == NULL){ // eðer dosya açýlamaz ise bir uyarý verir
	
		printf("Dosya acilamadi!!"); 
	}
	else{
		
		system("cls");	// ekraný temizlemek için
		
		int kNo = 1;
		
		do{
			
			dosya = fopen("telrehber.txt", "a");// kisilerin kaydedileceði dosya oluþturuldu
			
			printf("\t\t<<%d. Kayit>>\n\n", kNo);	
			printf("\tYeni kisinin adi             : ");						
			scanf("%s", &reh.ad);
			fprintf(dosya, "%s ", reh.ad);
			printf("\tYeni kisinin soyadi          : ");					
			scanf("%s", &reh.soyad);
			fprintf(dosya, "%s ", reh.soyad);
			
			do{
		
				printf("\tYeni kisinin telefon numarasi: ");					 // %d yaptýk ama 11 hane almýyor
				scanf("%s", &reh.tel);
				sorgula = telefon(reh.tel);//alýnan telefon numarasý char tipinde telefon fonksiyonuna gönderilip sorgulanýor
			} while (sorgula != 1);
			
			fprintf(dosya, "%s ", reh.tel);		//doðru bilgi alýndýktan sonra dönen fonksiyondaki parametre yazdýrýlýor...
		
			printf("\n\t>%d. Kisi eklendi<\n\n", kNo);
			
			kNo++;
			
			fclose(dosya); // oluþturulan dosya kapatýldý
			
			printf("Devam etmek istiyor musunuz?(e/h): \n");
			scanf("%s", &cevap);
			
			if(cevap == 'h'){
				
				main();
			}
			
			
			
		}while(cevap == 'e');
		
	}
}

// kiþiyi güncelleme fonksiyonu
void Guncelle(char ad[60]){
	
	FILE *dosya, *yenidosya;// iþlem yapýlacak akýþý tanýmlayan FILE nesnesi iþaretçisidir
	
	int k = 0;// kiþinin rehberde kayýtlý olup olmadýðý sorgulanmak amacý ile tanýmlandý
	
	system("cls");// ekraný temizlemek için
	
	dosya = fopen("telrehber.txt", "r");// bu dosyadan adý alýr ve aþaðýdaki dosyada siler 
	yenidosya = fopen("telrehber1.txt", "w");// güncelleme için yeni dosya açýldý	
	
	while (fscanf(dosya, "%s", &reh.ad) != EOF){ // dosyada bulunan adlarý EOF a kadar okur
	
		fscanf(dosya, "%s", &reh.soyad);		// dosyadan okunan diðer bilgiler
		fscanf(dosya, "%s", &reh.tel);		
		
		if (!strcmp(reh.ad, isim)){// aranan isimle Karþýlaþtýrma yapýlýr doðruysa ekrana yazýdýrýlýr 
				
			printf("Guncellenecek Kisinin Bilgileri\n");
			printf("---------------------------------\n");
			printf("Ad           : %s\n", reh.ad);
			printf("Soyad        : %s\n", reh.soyad);
			printf("Cep telefonu : %s\n\n", reh.tel);
		}
	}
	
	if (dosya == NULL){// rehberde kiþi olup olmadýðý kontrol eder
	
		printf("Suan rehberinizde hicbir kisi ekli degil!");
	}
	else{
	
		rewind(dosya);// dosya parametresi ile gösterilen akýþýn aktif dosya konumunu en baþa alýr
		rewind(yenidosya);// yenidosya parametresi ile gösterilen akýþýn aktif dosya konumunu en baþa alýr
		
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
					sorgula = telefon(reh.tel);// alýnan telefon numarasý char tipinde telefon fonksiyonuna gönderilip sorgulanýor
				} while (sorgula != 1);
				
				printf("\n>Kisi guncellendi<\n\n");
				fprintf(yenidosya, "%s %s %s\t  \n", reh.ad, reh.soyad, reh.tel);
			} // Güncellenicek kiþi dosyada tespit edilmiþse yeni bilgiler alýnýr ve dosyaya yazdýrýlýr eðer kiþi dosyada yok ise o dosya bilgiler olduðu gibi yeni dosyaya yazdýrýlýr.	
			else{
				fprintf(yenidosya, "%s %s %s\t  \n", reh.ad, reh.soyad, reh.tel);
			}
		}
		
		_fcloseall(); // tüm dosyalarý kapatýr
		
		remove("telrehber.txt"); // ilk dosyayý siler
		rename("telrehber1.txt", "telrehber.txt"); // yeni dosyanon adý deðiþtirilir ve ilk dosyanýn adý yapýlýr
		
		if (k == 0){// dosya taramasý boþ ise uyarý verir
		
			printf("Bu kisi rehberde kayitli degildir...\n");
		}
	}
}

// kiþiyi silme fonksiyonu
void Sil(char ad[60]){
	
	system("cls");// ekraný temizlemek için
	
	FILE *dosya, *yenidosya;// iþlem yapýlacak akýþý tanýmlayan FILE nesnesi iþaretçisidir
	
	int a = 0, cevap;// burada a kiþinin rehberde kayýtlý olup olmadýðý sorgulanmak amacý ile tanýmlandý
	
	dosya = fopen("telrehber.txt", "r");// okuma modunda açýldý
	yenidosya = fopen("telrehber1.txt", "w");// yazma modunda açýldý
	
	if (dosya == NULL){// dosyada silecek kiþi yoksa uyarý verir

		printf("Suan rehberinizde hicbir kisi ekli degil!");
	}
	else{
	
		rewind(dosya);// dosya parametresi ile gösterilen akýþýn aktif dosya konumunu en baþa alýr
		rewind(yenidosya);// yenidosya parametresi ile gösterilen akýþýn aktif dosya konumunu en baþa alýr
		
		printf("\n%s kisisini silmek istediginize emin misiniz?\n1. Evet\n2. Hayir\n", isim);// adý girilen kiþinin silinmesine emin olunulumasýný sorar
		scanf("%d", &cevap);
		
		if (cevap == 1){
		
			while (!feof(dosya)){// dosya sonuna kadar okutuldu ve dosyadan bilgiler alýndý
			
				fscanf(dosya, "%s %s %s ", &reh.ad, &reh.soyad, &reh.tel);
				if (!strcmp(reh.ad, ad)){// dosyadaki tüm adlarý tarar ve girilen isim ile eþitse bu kýsýma girer ve bu kiþi hariç diðer kiþileri yeni dosyaya yazar böylece kiþi silinmiþ olur
				
					printf("\n\t\t<<Silinen Kisi Bilgileri>>\n");
					printf("\tAd:\t%s\n\tSoyad:  %s\n\tCepTel: %s\n\n", reh.ad, reh.soyad, reh.tel);
					printf("\n\t>Kisi silindi<\n"); 
					a = 1;
				}
				else{// bu kýsýmada kiþi yoksa girer böylece tüm dosya bilgiler deðiþtirilmeden yeni metin belgesine yazdýrýlmýþ olur
					fprintf(yenidosya, "%s %s %s\t  \n", reh.ad, reh.soyad, reh.tel);
				}
			}
			
			_fcloseall();// tüm dosyalar kapatýldý
			
			remove("telrehber.txt");// dosyas silindi	
			rename("telrehber1.txt", "telrehber.txt");// ve yeni oluþturulan dosyada silindi ve eski isimde tekrar dosya oluþturuldu
			
			if (a == 0)// kiþi rehberde deðilse uyarý verir
				printf("\nKisi rehberde kayitli degil!\n");
		}
		else if (cevap == 2){// cevap hayýr ise çýktý verir ve ne yapmak istediðini sorar
			
			printf("Cevabiniz HAYIR..\n "); 
		}
		else { // herhangibi yanlýþ tuþ basýmý olursa sürekli olarak ayný þeyi soracak
		
			Sil(isim);
		}
	}
}

// kayýtlý kiþileri listeleme fonksiyonu
void Listele(){
	
	dosya = fopen("telrehber.txt", "r");	// okuma modunda açýlmýþtýr
	
	char secim;
	
	if (dosya == NULL){// dosya açýlmassa NULL deðeri gelir buna gore istenilen gerçekleþtirilir
	
		printf("Suan rehberinizde hicbir kisi ekli degil!\nEkleme yapmak icin (e) tusuna basiniz!\n");// rehber oluþturulmamýþsa bu uyarý gösterilir
		scanf("%s", &secim);
			
		system("cls");// ekraný temizlemek için
			
		if (secim == 'e'){
			
			KisiEkle(); 
		}			
		else{
			
			printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
		}
	}
	else{ // dosya önceden varsa kisi eklenebilir
		
		system("cls");// ekraný temizlemek için
		
		printf("Telefon Rehberi \n");
		printf("---------------\n\n");
		
		while (fscanf(dosya, "%s %s %s", &reh.ad, &reh.soyad, &reh.tel) != EOF){	// dosya sonu belirteci EOF a kadar okunur ve ekrana yazdýrýlýr. 
		
			printf("Ad:\t%s\nSoyad:  %s\nCepTel: %s\n\n", reh.ad, reh.soyad, reh.tel);
		}
		
		fclose(dosya);// dosya kapatýldý
	}
}

void Arama(){
	
	system("cls");// ekraný temizlemek için

	char isim[30];
	int flag = 0;
	
	dosya = fopen("telrehber.txt", "r");
	
	if (dosya == NULL){
	
		printf("Dosya veya sunucu bulunamadi!\n"); 
	}
	else{
		
		system("cls");// ekraný temizlemek için
		
		printf("Aranan kisinin adini giriniz: ");
		scanf("%s", &isim);
		printf("\n"); 
		
		rewind(dosya);// dosya parametresi ile gösterilen akýþýn aktif dosya konumunu en baþa alýr
		
		while (fscanf(dosya, "%s", &reh.ad) != EOF){ // dosyada bulunan adlarý EOF a kadar okur
	
			fscanf(dosya, "%s", &reh.soyad);		// dosyadan okunan diðer bilgiler
			fscanf(dosya, "%s", &reh.tel);		
		
			if (!strcmp(reh.ad, isim)){// aranan isimle Karþýlaþtýrma yapýlýr doðruysa ekrana yazýdýrýlýr 
		
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
