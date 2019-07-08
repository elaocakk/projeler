#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct veriler
{
    char numara[10];
    char isim[20];
    char soyisim[20];
    char kayitSirasi[10];
    char ogretimTuru[10];
};
void yaz(struct veriler ogrList[1000],int sayac);
void sil(struct veriler ogrList[1000],int sayac);
void numSirasi(struct veriler ogrList1[1000],int sayac);
void kayitSirasi(struct veriler ogrList1[1000],int sayac);
void numaraAt(struct veriler ogrList1[1000],int sayac);
void dagit(struct veriler ogrList1[1000],int sayac);
void ogrenciEkle(struct veriler ogrList1[1000],int sayac);
int i,j;
int main()
{

    int sayac=0;
    struct veriler ogrList[1000];///Ilk Okunan Dizi
    struct veriler ogrList1[1000];///Temize Gecilen Dizi

    FILE *fp=fopen("List.txt","r");
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp,"%s %s %s %s %s",&ogrList[i].numara,&ogrList[i].isim,&ogrList[i].soyisim,&ogrList[i].kayitSirasi,&ogrList[i].ogretimTuru);
        sayac++;
    }//Hatali dosyayi okuduk.
    fclose(fp);

    sil(ogrList,sayac);//Tekrar Eden Isimleri sildik.Bu isimleri guncel.txt ye yazdirdik.(Fonksiyonun Icinde)


    FILE *fp1=fopen("guncel.txt","r");//Temiz bir struct dizisi elde etmek icin guncellenmis dosyayi okuduk
    sayac=0;
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp1,"%s %s %s %s %s",&ogrList1[i].numara,&ogrList1[i].isim,&ogrList1[i].soyisim,&ogrList1[i].kayitSirasi,&ogrList1[i].ogretimTuru);
        sayac++;
    }
    fclose(fp1);

    kayitSirasi(ogrList1,sayac);

    numaraAt(ogrList1,sayac);

    numSirasi(ogrList1,sayac);

    int toplamOgrenciSayisi = guncelle(ogrList1,sayac);

    fp1=fopen("guncel.txt","r");//Temiz bir struct dizisi elde etmek icin guncellenmis dosyayi okuduk
    sayac=0;
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp1,"%s %s %s %s %s",&ogrList1[i].numara,&ogrList1[i].isim,&ogrList1[i].soyisim,&ogrList1[i].kayitSirasi,&ogrList1[i].ogretimTuru);
        sayac++;
    }
    fclose(fp1);

    //yaz(ogrList1,sayac-1);


    birinciIkinci(ogrList1,toplamOgrenciSayisi);

    int birinciSayisi=0;
    int ikinciSayisi=0;
    fp=fopen("birinci ogretim.txt","r");
    for(i=0; i<toplamOgrenciSayisi; i++)
    {
        if(strcmp(ogrList1[i].ogretimTuru,"I")==0)
            birinciSayisi++;
        else if(strcmp(ogrList1[i].ogretimTuru,"II")==0)
            birinciSayisi++;
    }
///##########################OGRENCI EKLEME##########################################



    int secim;
    int secim2;
    printf("\n\nogrenci eklemek istiyor musunuz?\n\nevet icin 1 hayir icin 2 girin.");
    scanf("%d",&secim);

tekrarSec://1-2 dýsýnda deger girilmesi durumu için
    if(secim==1)
    {

tekrarSec1:
            printf("Ogrenci 1. ogretim ise 1, 2. ogretim ise 2 giriniz.");
            scanf("%d",&secim2);

            if(secim2==1)
            {
                strcpy(ogrList1[toplamOgrenciSayisi+1].ogretimTuru,"I");
                int kayitNumarasi = atoi(ogrList1[toplamOgrenciSayisi].kayitSirasi)+1;
                sprintf(ogrList1[toplamOgrenciSayisi+1].kayitSirasi,"%d",kayitNumarasi);

                fp=fopen("guncel.txt","r");
                for(i=0; atoi(ogrList1[i].numara)<1702000; i++)
                {
                }
                fclose(fp);
                i=i-1;
                int ogrenciNo = atoi(ogrList1[i].numara)+1;
                sprintf(ogrList1[toplamOgrenciSayisi+1].numara,"%d",ogrenciNo);

                printf("Adini Giriniz:");
                scanf("%s",ogrList1[toplamOgrenciSayisi+1].isim);
                printf("Soyadini Giriniz:");
                scanf("%s",ogrList1[toplamOgrenciSayisi+1].soyisim);

                fp=fopen("guncel.txt","a");
                fprintf(fp,"%15s %15s %15s %15s %15s",&ogrList1[toplamOgrenciSayisi+1].numara,&ogrList1[toplamOgrenciSayisi+1].isim,&ogrList1[toplamOgrenciSayisi+1].soyisim,&ogrList1[toplamOgrenciSayisi+1].kayitSirasi,&ogrList1[toplamOgrenciSayisi+1].ogretimTuru);
                fclose(fp);
                fp=fopen("List.txt","a");
                fprintf(fp,"\n%s %s %s %s %s",&ogrList1[toplamOgrenciSayisi+1].numara,&ogrList1[toplamOgrenciSayisi+1].isim,&ogrList1[toplamOgrenciSayisi+1].soyisim,&ogrList1[toplamOgrenciSayisi+1].kayitSirasi,&ogrList1[toplamOgrenciSayisi+1].ogretimTuru);
                fclose(fp);
                fp=fopen("birinci ogretim.txt","a");
                fprintf(fp,"%15s %15s %15s %15s %15s\n",&ogrList1[toplamOgrenciSayisi+1].numara,&ogrList1[toplamOgrenciSayisi+1].isim,&ogrList1[toplamOgrenciSayisi+1].soyisim,&ogrList1[toplamOgrenciSayisi+1].kayitSirasi,&ogrList1[toplamOgrenciSayisi+1].ogretimTuru);
                fclose(fp);
                //sil(ogrList1,sayac+1);
                numSirasi(ogrList1,sayac+1);
               // guncelle(ogrList1,sayac+1);



            }
            else if(secim2==2)
            {
                strcpy(ogrList1[toplamOgrenciSayisi+1].ogretimTuru,"II");
                int kayitNumarasi = atoi(ogrList1[toplamOgrenciSayisi].kayitSirasi)+1;
                sprintf(ogrList1[toplamOgrenciSayisi+1].kayitSirasi,"%d",kayitNumarasi);

                int ogrenciNo = atoi(ogrList1[toplamOgrenciSayisi].numara)+1;
                sprintf(ogrList1[toplamOgrenciSayisi+1].numara,"%d",ogrenciNo);

                printf("Adini Giriniz:");
                scanf("%s",ogrList1[toplamOgrenciSayisi+1].isim);
                printf("Soyadini Giriniz:");
                scanf("%s",ogrList1[toplamOgrenciSayisi+1].soyisim);

                fp=fopen("guncel.txt","a");
                fprintf(fp,"%15s %15s %15s %15s %15s",ogrList1[toplamOgrenciSayisi+1].numara,ogrList1[toplamOgrenciSayisi+1].isim,ogrList1[toplamOgrenciSayisi+1].soyisim,ogrList1[toplamOgrenciSayisi+1].kayitSirasi,&ogrList1[toplamOgrenciSayisi+1].ogretimTuru);
                fclose(fp);

                fp=fopen("List.txt","a");
                fprintf(fp,"\n%s %s %s %s %s",&ogrList1[toplamOgrenciSayisi+1].numara,&ogrList1[toplamOgrenciSayisi+1].isim,&ogrList1[toplamOgrenciSayisi+1].soyisim,&ogrList1[toplamOgrenciSayisi+1].kayitSirasi,&ogrList1[toplamOgrenciSayisi+1].ogretimTuru);
                fclose(fp);

                fp=fopen("ikinci ogretim.txt","a");
                fprintf(fp,"%15s %15s %15s %15s %15s\n",&ogrList1[toplamOgrenciSayisi+1].numara,&ogrList1[toplamOgrenciSayisi+1].isim,&ogrList1[toplamOgrenciSayisi+1].soyisim,&ogrList1[toplamOgrenciSayisi+1].kayitSirasi,&ogrList1[toplamOgrenciSayisi+1].ogretimTuru);
                fclose(fp);
                //sil(ogrList1,sayac+1);
                numSirasi(ogrList1,sayac+1);
                //guncelle(ogrList1,sayac+1);


            }
            else
            {
                printf("\nYanlis Secim Yaptiniz.\n");
                goto tekrarSec1;
            }

    }

    else if(secim==2) {}

    else
    {
        printf("\nYanlis Secim Yaptiniz.\n");
        goto tekrarSec;
    }


    dagit(ogrList1,sayac);//Ogrencileri Siniflara Dagitan Fonksiyon.



    getchar();
    return 0;
}
int birinciIkinci(struct veriler ogrList1[1000],int sayac)
{
    FILE *fp=fopen("birinci ogretim.txt","w");
    for(i=0; i<sayac; i++)
    {
        if(strcmp(ogrList1[i].ogretimTuru,"I")==0)
        {
            fprintf(fp,"%15s %15s %15s %15s %15s\n",ogrList1[i].numara,ogrList1[i].isim,ogrList1[i].soyisim,ogrList1[i].kayitSirasi,ogrList1[i].ogretimTuru);

        }
    }
    fclose(fp);

    fp=fopen("ikinci ogretim.txt","w");
    for(i=0; i<sayac; i++)
    {
        if(strcmp(ogrList1[i].ogretimTuru,"II")==0)
        {
            fprintf(fp,"%15s %15s %15s %15s %15s\n",ogrList1[i].numara,ogrList1[i].isim,ogrList1[i].soyisim,ogrList1[i].kayitSirasi,ogrList1[i].ogretimTuru);

        }
    }
    fclose(fp);
}
int guncelle(struct veriler ogrList1[1000],int sayac)
{
    FILE *fp2 = fopen("guncel.txt","w");//Numara atamasi yaptiktan sonra guncel.txtyi tekrar guncelledik.
    int ogrenciSayisi=0;
    for(j=2; j<sayac; j++)
    {
        fprintf(fp2,"%15s %15s %15s %15s %15s\n",ogrList1[j].numara,ogrList1[j].isim,ogrList1[j].soyisim,ogrList1[j].kayitSirasi,ogrList1[j].ogretimTuru);
        ogrenciSayisi++;
    }
    fclose(fp2);
    return ogrenciSayisi;
}
void yaz(struct veriler ogrList[1000],int sayac)
{
    for(i=0; i<sayac; i++)
    {
        printf("%15s %15s %15s %15s %15s\n",ogrList[i].numara,ogrList[i].isim,ogrList[i].soyisim,ogrList[i].kayitSirasi,ogrList[i].ogretimTuru);
    }
}
void sil(struct veriler ogrList[1000],int sayac)
{
    clock_t basla,son;
    basla=clock();

    FILE *fp=fopen("sunum.txt","w");
    FILE *fp1=fopen("guncel.txt","w");
    fprintf(fp,"Tekrar Eden Isimler:\n");
    for(i=0; i<sayac-1; i++)
    {
        if(strcmp(ogrList[i].isim,ogrList[i-1].isim)==0 && strcmp(ogrList[i].soyisim,ogrList[i-1].soyisim)==0)
        {

            fprintf(fp,"%15s %15s\n",ogrList[i].isim,ogrList[i].soyisim);
            continue;
        }
        else
        {
            // printf("%10s %10s %10s %10s %10s\n",ogrList[i].numara,ogrList[i].isim,ogrList[i].soyisim,ogrList[i].kayitSirasi,ogrList[i].ogretimTuru);
            fprintf(fp1,"%15s %15s %15s %15s %15s\n",ogrList[i].numara,ogrList[i].isim,ogrList[i].soyisim,ogrList[i].kayitSirasi,ogrList[i].ogretimTuru);

        }
    }
    fprintf(fp,"Tekrar Eden Isimler Silindi.\n");
    printf("Tekrar Eden Isimler Silindi.\n");
    fclose(fp1);
    fclose(fp);
    son=clock();
    printf("Tekrar Eden Isimleri Silme Suresi : %lf\n\n",difftime(son,basla)/CLOCKS_PER_SEC);

}
void numSirasi(struct veriler ogrList1[1000],int sayac )
{
///Numaraya Gore Siralama
    clock_t basla,son;
    basla=clock();
    FILE *fp=fopen("sunum.txt","a");
    char yedek[20];
    for (i = 0 ; i < ( sayac - 1 ); i++)
    {
        for (j = 0 ; j < sayac - i - 1; j++)
        {
            if (atoi(ogrList1[j].numara)>atoi(ogrList1[j+1].numara ))
            {

                strcpy(yedek,ogrList1[j].kayitSirasi);
                strcpy(ogrList1[j].kayitSirasi,ogrList1[j+1].kayitSirasi);
                strcpy(ogrList1[j+1].kayitSirasi,yedek);

                strcpy(yedek,ogrList1[j].isim);
                strcpy(ogrList1[j].isim,ogrList1[j+1].isim);
                strcpy(ogrList1[j+1].isim,yedek);

                strcpy(yedek,ogrList1[j].soyisim);
                strcpy(ogrList1[j].soyisim,ogrList1[j+1].soyisim);
                strcpy(ogrList1[j+1].soyisim,yedek);

                strcpy(yedek,ogrList1[j].numara);
                strcpy(ogrList1[j].numara,ogrList1[j+1].numara);
                strcpy(ogrList1[j+1].numara,yedek);

                strcpy(yedek,ogrList1[j].ogretimTuru);
                strcpy(ogrList1[j].ogretimTuru,ogrList1[j+1].ogretimTuru);
                strcpy(ogrList1[j+1].ogretimTuru,yedek);
            }
        }
    }
    fprintf(fp,"Isimler Numaralarina Gore Tekrar Siralandi.\n");
    printf("Isimler Numaralarina Gore Tekrar Siralandi.\n");
    fclose(fp);
    son=clock();
    printf("Isimlerin Numaraya Gore Siralanma Suresi : %lf\n\n",difftime(son,basla)/CLOCKS_PER_SEC);
}
void kayitSirasi(struct veriler ogrList1[1000],int sayac)
{
    clock_t basla,son;
    basla=clock();
    FILE *fp=fopen("sunum.txt","a");
    char yedek[20];
    ///Kayit Sirasina Gore Siralama
    for (i = 0 ; i < ( sayac - 1 ); i++)
    {
        for (j = 0 ; j < sayac - i - 1; j++)
        {
            if (atoi(ogrList1[j].kayitSirasi)>atoi(ogrList1[j+1].kayitSirasi ))
            {

                strcpy(yedek,ogrList1[j].kayitSirasi);
                strcpy(ogrList1[j].kayitSirasi,ogrList1[j+1].kayitSirasi);
                strcpy(ogrList1[j+1].kayitSirasi,yedek);

                strcpy(yedek,ogrList1[j].isim);
                strcpy(ogrList1[j].isim,ogrList1[j+1].isim);
                strcpy(ogrList1[j+1].isim,yedek);

                strcpy(yedek,ogrList1[j].soyisim);
                strcpy(ogrList1[j].soyisim,ogrList1[j+1].soyisim);
                strcpy(ogrList1[j+1].soyisim,yedek);

                strcpy(yedek,ogrList1[j].numara);
                strcpy(ogrList1[j].numara,ogrList1[j+1].numara);
                strcpy(ogrList1[j+1].numara,yedek);

                strcpy(yedek,ogrList1[j].ogretimTuru);
                strcpy(ogrList1[j].ogretimTuru,ogrList1[j+1].ogretimTuru);
                strcpy(ogrList1[j+1].ogretimTuru,yedek);
            }
        }
    }
    fprintf(fp,"Isimler Kayit Sirasina Gore Siralandi.\n");
    printf("Isimler Kayit Sirasina Gore Siralandi.\n");
    fclose(fp);
    son=clock();
    printf("Kayit Sirasina Sokma Suresi : %lf\n\n",difftime(son,basla)/CLOCKS_PER_SEC);
}
void numaraAt(struct veriler ogrList1[1000],int sayac)
{
    clock_t basla,son;
    basla=clock();
    FILE *fp=fopen("sunum.txt","a");
///Birinci Ogretimlerin Numaralandirilmasi
    j=0;
    for(i=0; i<sayac; i++)
    {
        if(strcmp(ogrList1[i].ogretimTuru,"I")==0)
        {
            if(strcmp(ogrList1[i].numara,"-")==0)
            {

                sprintf(ogrList1[i].numara,"%d",1701001+j);
                j++;
            }
        }

    }
    ///Ikinci Ogretimlerin Numaralandirilmasi
    j=0;
    for(i=0; i<sayac; i++)
    {
        if(strcmp(ogrList1[i].ogretimTuru,"II")==0)
        {
            if(strcmp(ogrList1[i].numara,"-")==0)
            {

                sprintf(ogrList1[i].numara,"%d",1702001+j);
                j++;
            }
        }

    }
    printf("\nNumara Atamasi Yapildi.\n");
    fprintf(fp,"Numara Atamasi Yapildi.\n");
    fclose(fp);
    son=clock();
    printf("Numara Atama Suresi : %lf\n\n",difftime(son,basla)/CLOCKS_PER_SEC);

}
void dagit(struct veriler ogrList1[1000],int sayac)
{

    FILE *fp = fopen("guncel.txt","r");
    int ogrenciSayisi=0;
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp,"%s %s %s %s %s",&ogrList1[i].numara,&ogrList1[i].isim,&ogrList1[i].soyisim,&ogrList1[i].kayitSirasi,&ogrList1[i].ogretimTuru);
        ogrenciSayisi++;
    }

    fclose(fp);

    //yaz(ogrList1,ogrenciSayisi);

    struct veriler birinciOgretim[1000];
    int birinciSayisi;
    struct veriler ikinciOgretim[1000];
    int ikinciSayisi;
    j=0;
    for(i=0; i<ogrenciSayisi; i++)
    {
        if(strcmp(ogrList1[i].ogretimTuru,"I")==0)
        {
            j++;
        }
    }
    birinciSayisi=j;
    fp=fopen("birinci ogretim.txt","r");
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp,"%s %s %s %s %s",&birinciOgretim[i].numara,&birinciOgretim[i].isim,&birinciOgretim[i].soyisim,&birinciOgretim[i].kayitSirasi,&birinciOgretim[i].ogretimTuru);
    }
    fclose(fp);

    j=0;
    for(i=0; i<ogrenciSayisi+1; i++)
    {
        if(strcmp(ogrList1[i].ogretimTuru,"II")==0)
        {
            j++;
        }
    }
    fclose(fp);
    ikinciSayisi=j;
    fp=fopen("ikinci ogretim.txt","r");
    for(i=0; !feof(fp); i++)
    {
        fscanf(fp,"%s %s %s %s %s",&ikinciOgretim[i].numara,&ikinciOgretim[i].isim,&ikinciOgretim[i].soyisim,&ikinciOgretim[i].kayitSirasi,&ikinciOgretim[i].ogretimTuru);
    }
    fclose(fp);

///########################### SINIFLARI ALMA ###########################################
    int sinifSayisi;
tekrar:
    printf("\nSinif Sayisini Giriniz:");
    scanf("%d",&sinifSayisi);
    int maxdizi[sinifSayisi];
    int mindizi[sinifSayisi];

    int toplamKapasite=0;
    for(i=0; i<sinifSayisi; i++)
    {
        printf("%d. Sinifin Kapasitesini Girininiz:",i+1);
        scanf("%d",&maxdizi[i]);
        mindizi[i]=maxdizi[i];
        toplamKapasite = toplamKapasite + maxdizi[i];
    }
    if(toplamKapasite<birinciSayisi && toplamKapasite<ikinciSayisi)
    {
        system("cls");
        printf("Sinif Kapasiteleri Ogrenci Sayilarindan Dusuktur Tekrar Sinif Girisi Yapiniz.\n");
        goto tekrar;
    }

    clock_t basla,son;
    basla=clock();

    int gecici;
///Buyukten Kucuge
    for (i = 0 ; i < ( sinifSayisi - 1 ); i++)
    {
        for (j = 0 ; j < sinifSayisi - i - 1; j++)
        {
            if (maxdizi[j]<maxdizi[j+1])
            {
                gecici=maxdizi[j];
                maxdizi[j]=maxdizi[j+1];
                maxdizi[j+1]=gecici;

            }
        }
    }
///Kucukten Buyuye
    for (i = 0 ; i < ( sinifSayisi - 1 ); i++)
    {
        for (j = 0 ; j < sinifSayisi - i - 1; j++)
        {
            if (mindizi[j]>mindizi[j+1])
            {
                gecici=mindizi[j];
                mindizi[j]=mindizi[j+1];
                mindizi[j+1]=gecici;

            }
        }
    }
    printf("1. Ogretim Sayisi:%d\n",birinciSayisi);
    printf("2. Ogretim Sayisi:%d\n",ikinciSayisi);
    printf("Toplam Kapasite:%d\n",toplamKapasite);





///####################################### ESIT DAGITIM ########################################################
//fp=fopen("1. Ogretim Esit Dagitim.txt","w");
    int minumum = mindizi[0];
    int count=0;
    int sinifSayisi1=sinifSayisi;
    char dizi[20];
    char isim[20];
    for(j=0; j<sinifSayisi; j++)
    {

        sprintf(dizi,"%d",j+1);
        strcpy(isim,dizi);
        strcat(isim,". sinif 1. ogretim esit.txt");
        fp=fopen(isim,"w");

        if(birinciSayisi/sinifSayisi1>minumum)
        {
            fprintf(fp,"##################################################################################\n");
            fprintf(fp,"%d. Siniftaki Ogrenciler\n",j+1);
            for(i=0; i<minumum; i++)
            {
                fprintf(fp,"%15s %15s %15s %15s %15s\n",birinciOgretim[count].numara,birinciOgretim[count].isim,birinciOgretim[count].soyisim,birinciOgretim[count].kayitSirasi,birinciOgretim[count].ogretimTuru);
                count++;
            }
            birinciSayisi=birinciSayisi-mindizi[j];
            sinifSayisi1=sinifSayisi1-1;
            minumum=mindizi[j+1];
        }
        else
        {
            fprintf(fp,"##################################################################################\n");
            fprintf(fp,"%d. Siniftaki Ogrenciler\n",j+1);

            for(i=0; i<(birinciSayisi/sinifSayisi1)+1; i++)
            {
                fprintf(fp,"%15s %15s %15s %15s %15s\n",birinciOgretim[count].numara,birinciOgretim[count].isim,birinciOgretim[count].soyisim,birinciOgretim[count].kayitSirasi,birinciOgretim[count].ogretimTuru);
                count++;
            }
        }
        fclose(fp);
    }

    //fp=fopen("2. Ogretim Esit Dagitim.txt","w");
    minumum = mindizi[0];
    count=0;
    sinifSayisi1=sinifSayisi;
    for(j=0; j<sinifSayisi; j++)
    {
        sprintf(dizi,"%d",j+1);
        strcpy(isim,dizi);
        strcat(isim,". sinif 2. ogretim esit.txt");
        fp=fopen(isim,"w");
        if(ikinciSayisi/sinifSayisi1>minumum)
        {
            fprintf(fp,"##################################################################################\n");
            fprintf(fp,"%d. Siniftaki Ogrenciler\n",j+1);
            for(i=0; i<minumum; i++)
            {
                fprintf(fp,"%15s %15s %15s %15s %15s\n",ikinciOgretim[count].numara,ikinciOgretim[count].isim,ikinciOgretim[count].soyisim,ikinciOgretim[count].kayitSirasi,ikinciOgretim[count].ogretimTuru);
                count++;
            }
            ikinciSayisi=ikinciSayisi-mindizi[j];
            sinifSayisi1=sinifSayisi1-1;
            minumum=mindizi[j+1];
        }
        else
        {
            fprintf(fp,"##################################################################################\n");
            fprintf(fp,"%d. Siniftaki Ogrenciler\n",j+1);
            for(i=0; i<(ikinciSayisi/sinifSayisi1)+1; i++)
            {
                fprintf(fp,"%15s %15s %15s %15s %15s\n",ikinciOgretim[count].numara,ikinciOgretim[count].isim,ikinciOgretim[count].soyisim,ikinciOgretim[count].kayitSirasi,ikinciOgretim[count].ogretimTuru);
                count++;
            }
        }
        fclose(fp);
    }



///####################################### MINUMUM SINIF SAYISI ########################################################

    count =0;
    for(j=0; j<sinifSayisi; j++)
    {

        sprintf(dizi,"%d",j+1);
        strcpy(isim,dizi);
        strcat(isim,". sinif 1. ogretim minumum.txt");
        fp=fopen(isim,"w");

        fprintf(fp,"##################################################################################\n");
        fprintf(fp,"%d. Siniftaki Ogrenciler\n",j+1);
        for(i=0; i<maxdizi[j]; i++)
        {
            fprintf(fp,"%15s %15s %15s %15s %15s\n",birinciOgretim[count].numara,birinciOgretim[count].isim,birinciOgretim[count].soyisim,birinciOgretim[count].kayitSirasi,birinciOgretim[count].ogretimTuru);
            count++;

        }

        fclose(fp);
    }


    count=0;
    for(j=0; j<sinifSayisi; j++)
    {
        sprintf(dizi,"%d",j+1);
        strcpy(isim,dizi);
        strcat(isim,". sinif 2. ogretim minumum.txt");
        fp=fopen(isim,"w");
        fprintf(fp,"##################################################################################\n");
        fprintf(fp,"%d. Siniftaki Ogrenciler\n",j+1);
        for(i=0; i<maxdizi[j]; i++)
        {
            fprintf(fp,"%15s %15s %15s %15s %15s\n",ikinciOgretim[count].numara,ikinciOgretim[count].isim,ikinciOgretim[count].soyisim,ikinciOgretim[count].kayitSirasi,ikinciOgretim[count].ogretimTuru);
            count++;
        }

        fclose(fp);
    }
    printf("Ogrenciler Siniflara Esit Olacak Sekilde Dagitildi.\n");
    printf("Ogrenciler Siniflara Minumum Sinif Gerektirecek Sekilde Dagitildi.\n");
    fp=fopen("sunum.txt","a");
    fprintf(fp,"\n");

    fprintf(fp,"Ogrenciler Siniflara Esit Olacak Sekilde Dagitildi.\n");

    fprintf(fp,"\n");
    fprintf(fp,"Ogrenciler Minumum Sinif Sayisi Olacak Sekilde Dagitildi.\n");

    fprintf(fp,"\nAcikta Ogrenci Kalmadi.\n");
    fclose(fp);

    son=clock();
    printf("\nSiniflara Dagitma Suresi : %lf\n",difftime(son,basla)/CLOCKS_PER_SEC);

}
