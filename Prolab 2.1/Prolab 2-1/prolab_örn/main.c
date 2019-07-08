#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct komsu {
    char plaka;
    struct komsu* next;
};
struct komsu* start=NULL;

struct komsu* dugum_olustur(char plk)
{   struct komsu* yeni = (struct komsu*)malloc(sizeof(struct komsu));
    strcpy(yeni->plaka,plk);
    yeni->next = NULL;
    return yeni;
}

void ekle(char plk)  {
    struct komsu* ekle = dugum_olustur(plk);
    if (start == NULL){
        start = ekle;
    } else{
       struct komsu* temp = start;
        while (temp->next != NULL){
            temp = temp->next;
        }   }
    ekle->next=NULL;
}

struct sehirBil {  // bunlarla iþlem yapmaya gelince mutlaka çevirme yapman lazým
double lat[83];
double long1[83];
int rakim[83];
int plakaKodu[83];

int komsu[9][10];
double egimF[9][10];
} sehir[81];

struct gecici {
char latt[83];
char longg1[83];
char rakimm[83];
char plakaa[83];
} temp[83];


int main()
{
int i=0,j=0;
double x,y;
int z,t;
FILE *dosya;
dosya=fopen("bilgiler.txt","r+");

if(dosya!=NULL ) {
while(!feof(dosya) && i<82) {
    //fscanf(dosya,"%s %s %s %s",&sehir[i].lat,&sehir[i].long1,&sehir[i].plakaKodu,&sehir[i].rakim);
    fscanf(dosya,"%s %s %s %s",temp[i].latt,temp[i].longg1,temp[i].plakaa,temp[i].rakimm);

    if(i==0) {

    } else {

    strcpy(sehir[j].lat,temp[i].latt);
    strcpy(sehir[j].long1,temp[i].longg1);
    strcpy(sehir[j].plakaKodu,temp[i].plakaa);
    strcpy(sehir[j].rakim,temp[i].rakimm);

    printf("l:%s lg:%s p:%s r:%s\n",sehir[j].lat,sehir[j].long1,sehir[j].plakaKodu,sehir[j].rakim);
    j++;
    }
   //printf("l:%s lg:%s p:%s r:%s\n",temp[i].latt,temp[i].longg1,temp[i].plakaa,temp[i].rakimm);
    i++;
    }
} else {
    printf("dosya yok");
    }

fclose(dosya);
printf("\n\n");

/// *************** ///
char ko[50];
char *ayrac=" ,";
i=0;

FILE *dosya2;
dosya2=fopen("komsuluk.txt","r+");

if(dosya2!=NULL ) {
while(!feof(dosya2) && i<81) {
   // fscanf(dosya2,"%s %s %s %s %s %s %s %s %s %s",sehir[i].plakaKodu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu);

    fscanf(dosya2,"%s",ko);
    char *kelime=strtok(ko,ayrac);
    j=0;
    int m=0;
    while(kelime!=NULL) {
        if(j==0) {
            strcpy(sehir[i].plakaKodu,kelime);
             printf("%s\n",sehir[i].plakaKodu);
        } else {
            strcpy(sehir[i].komsu[m],kelime);
            printf("%s-",sehir[i].komsu[m]);
            m++;
        }
        kelime=strtok(NULL,ayrac);
        j++;
    }
    printf("\n");

  /* fgets(sehir[i].plakaKodu,4,dosya2);
   printf("--%s--\n",sehir[i].plakaKodu);

   for(j=0;j<9;j++) {
   fgets(sehir[i].komsu[j],4,dosya2);
   printf("%s*",sehir[i].komsu[j]);
}
    printf("\n");  */
    //printf("%s %s %s %s %s %s %s %s %s %s",sehir[i].plakaKodu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu);
    i++;
}
}

fclose(dosya2);

printf("******* DENEME **********\n");

for(i=0;i<81;i++) {
printf("%s,%s,%s,%s\n",sehir[i].lat,sehir[i].long1,sehir[i].plakaKodu,sehir[i].rakim);
    for(j=0;j<8;j++) {
    printf("%s-",sehir[i].komsu[j]);
    }
    printf("\n");
    }
/// ****************** ///

int yolcuSay, ucret;
double kar,egim;
printf("Yolcu Sayýsýný Giriniz: ");
scanf("%d",&yolcuSay);

if(yolcuSay<5 || yolcuSay>50){
    printf("Eksik veya Fazla Yolcu Girdiniz!");
       }

//egim=80-yolcuSay;

double yeniEgim[500];
double rakimFark[500];
double latF[500];
double longF[500];
double distance,a,c,R=6371;
int k=0;
/*
for(i=0; i<81 ; i++){
    for(j=0; j<81; j++){     // burada mutlaka linked list gerekli
        rakimFark[k]=sehir[i].komsu[j].rakim-sehir[i].rakim;
        /***      HAVERSINE     ***
        latF[k]=sehir[i].komsu[j].lat[j]-sehir[i].lat[i];
        longF[k]=sehir[i].komsu[j],long1[j]-sehir[i].long1[i];
    }
}
*/

double l1[100],l2[100];
double lg1[100],lg2[100];
int r1[100],r2[100];

for(i=0; i<81; i++){
    for(k=0;k<9;k++) {
        l1[k]=atof(sehir[i].lat);
        lg1[k]=atof(sehir[i].long1);
        r1[k]=atoi(sehir[i].rakim);

if (strcmp(sehir[i].komsu[k],"00")==0){goto a;}
        if(strcmp(sehir[i].komsu[k],sehir[i].plakaKodu)==0){
        l2[k]=atof(sehir[k].lat);
        lg2[k]=atof(sehir[k].long1);
        r2[k]=atoi(sehir[k].rakim);
        } else {
        l2[k]=0;
        lg2[k]=0;
        r2[k]=0;
        }
        latF[k]=l1[k]-l2[k];
        longF[k]=lg1[k]-lg2[k];
        rakimFark[k]=r1[k]-r2[k];
    // *** HAVERSÝNE *** //
    a=sin(latF[k]/2)*sin(latF[k]/2)+cos(l1[k])*cos(l2[k])*sin(longF[k]/2)*sin(longF[k]/2);
    c=2*atan2(sqrt(a),sqrt(1-a));
    distance=R*c;

    yeniEgim[k]=atan(rakimFark[k]/distance+50);
    printf("%+lf+  ",yeniEgim[k]);
       a: printf(" "); }
    printf("\n");
}

return 0;
}
