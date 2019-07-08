#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
int sn;

int ogrsayi=140;

printf("sinif sayisini girin");
scanf("%d",&sn);

int sdizi[sn];
printf("sinif kapasitelerini girin");
int i;

a:
for(i=0;i<sn;i++) {
    scanf("%d",&sdizi[i]);
}

int gecici,kapasiteTop=0;

for(i=0;i<sn;i++){ // kucukten buyuge sýralama, sýnýf kapasiteleri dizisi
        if(sdizi[i+1]<sdizi[i]){
            gecici=sdizi[i+1];
            sdizi[i+1]=sdizi[i];
            sdizi[i]=gecici;
             }
        }

for(i=0;i<sn;i++) {
    kapasiteTop=kapasiteTop+sdizi[i];
        }
//printf("%d\n",kapasiteTop);

/*
printf("1. ogretim ogrenci sayisi: %d\n",bosayi);
printf("2. ogretim ogrenci sayisi: %d\n",iosayi);
*/

if(ogrsayi>kapasiteTop){
    printf("yeni sinif girmelisiniz\n");
    printf("kapasiteleri tekrar girin:\n");
    sn++;
    goto a;
} else {

// ~~~~EN AZ SÝNÝF DAGÝLÝMÝ

int baslangic=0;
int maxbyt;
//ogrsayi=biosayi;
//ogrsayi=iosayi;
int a=sn;

tekrar:

if(ogrsayi>0){
    maxbyt=sdizi[a];

    if(ogrsayi>=maxbyt) { // max boyuttan buyukse dolduracak onu

    for(i=baslangic;i<maxbyt;i++) {
        printf("%d\n",i);
      //  fprintf(/*dosya adi ,"%s\t %s\t",kisi[i].isim2,kisi[i].soyad2);
            }
    printf("-----------------------\n");
    }
    else if(ogrsayi<maxbyt) {
            for(i=baslangic;i<ogrsayi;i++) {
                    printf("%d\n",i);
               // fprintf(// dosya adi,"%s\t %s\t",kisi[i].isim2,kisi[i].soyad2);
            }
            printf("---------------------\n");
            goto son;
    }
    ogrsayi=ogrsayi-maxbyt;
    baslangic=baslangic+maxbyt; // sonraki ewferde kaldigi yerden devam edebilsin

    a--;// diger max boyuta gecmeli cunku dizimiz kucukten buyuge sirali,en sonda degisecek
    goto tekrar;
}

son:

if(a>0){ // siniflarin hepsi kullanýlmazsa kalanlara 0 ata
    for(i=a;i>0;i--)
        sdizi[i]=0;
}

printf("\n");

for(i=0;i<a;i++)
    printf("%d \n",sdizi[i]);

printf("\n");

//fclose(ptr3);

/*
// ~~~~ ESÝT DAGÝLÝM

int baslangic=0;
int minbyt,bolum;
int ogrsayi;
int snf=sn; // snf i  bolumu bulurken kullaniyorum

tekrar:
if(ogrsayi>0){
    minbyt=sdizi[0];
    bolum=ogrsayi/snf;

    if(bolum>minbyt) {

        for(i=baslangic;i<minbyt;i++) { // once minbyt lu sinif dolacak
                fprintf(//sinif dosyasi,"%s\t %s\t",kisi[i].isim2,kisi[i].soyad2);
            }
    }
    else if(bolum<=minbyt) {

        for(j=1;j<snf;j++) { // geriye kalan siniflara dagitma
        for(i=baslangic;i<bolum;i++) {   // min boyuttan kucukse sýnýflara hepsini esit atayacak
        fprintf(//sinif dosyasi,"%s\t %s\t",kisi[i].isim2,kisi[i].soyad2);
            }
        baslangic+=bolum;
    }
        goto son:
    }
    ogrsayi=ogrsayi-minbyt;
    baslangic=baslangic+minbyt; // sonraki ewferde kaldigi yerden devam edebilsin

    snf--;

    sn++;// diger min boyuta gecmeli cunku dizimiz kucukten buyuge sirali halde
    goto tekrar:
}
son:
*/

}
return 0;
}
