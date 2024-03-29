#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <time.h>

struct graf {
        int dugum;
        double kenar;
        struct graf* sonraki;
           };

///******************************************

struct graf* YeniDugum(int veri,double mesafe) {

      struct graf* node = (struct graf*) malloc(sizeof(struct graf));
      node->dugum=veri;
      node->kenar=mesafe;
      node->sonraki = NULL;
      return node;
      }
struct graf* start = NULL;
struct graf* temp = NULL;

///******************************************

struct giris {
    char lat[82], long1[82], plakaKodu[82],rakim[82];
    char komsu[9][82];
    double dizi2[82], lat2, long2;
    int plakaKodu2,rakim2,plakaKodu3;
    int komsu2[9];
    double egimF[9],egimF2[9];
    double distance[9];
    double hipo[9],hipo2[9];
} giris[82];


///*********************************************** M A I N *******************************************************
int m=1;
int d[100]={0};
double path[50];

int main()
{
time_t start1,end;
time(&start1);

FILE *dosya=fopen("latlong.txt","r");
int i=0;
int a;

if(dosya!=NULL){
       a=0;
       for(i=0;i=!feof(dosya);i++){
       fscanf(dosya,"%s %s %s %s",giris[a].lat,giris[a].long1,giris[a].plakaKodu,giris[a].rakim);
       a++;
       }
}
fclose(dosya);
int q1,q2;
double x,y,z,t;

for(i=0; i<81; i++){
        sscanf(giris[i].lat,"%lf",&x);         giris[i].lat2=x;
        sscanf(giris[i].long1,"%lf",&y);       giris[i].long2=y;
        sscanf(giris[i].plakaKodu,"%lf",&z);  q1=z; giris[i].plakaKodu2=q1;
        sscanf(giris[i].rakim,"%lf",&t);     q2=t;  giris[i].rakim2=q2;
    //    printf("%lf\t%lf\t%d\t%d\n",giris[i].lat2,giris[i].long2,giris[i].plakaKodu2,giris[i].rakim2);
                }

FILE *dosya2;
dosya2=fopen("komsuluk.txt","r+");
int j,c,e;
i=0;
char ko[50];
char *ayrac=",";
if(dosya2!=NULL ) {
while(!feof(dosya2) && i<81) {
      fscanf(dosya2,"%s",ko);
      char *kelime=strtok(ko,ayrac);
      j=0;
      int m=0;
      while(kelime!=NULL) {
           if(j==0) {
            strcpy(giris[i].plakaKodu,kelime);
            sscanf(giris[i].plakaKodu,"%lf",&z);
            giris[i].plakaKodu2=z;
        }  else {
            strcpy(giris[i].komsu[m],kelime);
            sscanf(giris[i].komsu[m],"%d",&c);
            giris[i].komsu2[m]=c;
            m++;
             }
        kelime=strtok(NULL,ayrac);
        j++;
     }
i++;
}
}
fclose(dosya2);

///*******************************************

int baslangic,bitis;
g:
printf("baslangic sehrinin plakasini girin:");
scanf("%d",&baslangic);
     if(baslangic>81 || baslangic==0)
        {goto g; }

gg:
printf("bitis sehrinin plakasini girin    :");
scanf("%d",&bitis);
     if(bitis>81 || bitis==0)
        {goto gg; }

///************************** E G I M ****************************

int rakimFark[500];
double yeniEgim[500],latF[500],longF[500],R=6371;
double aa,cc,pi = 3.141592653589793;
double l1[100],l2[100],lg1[100],lg2[100];
int r1[100],r2[100];
int k=0;
for(i=0;i<81;i++) {

    l1[i]=giris[i].lat2;
    lg1[i]=giris[i].long2;
    r1[i]=giris[i].rakim2;

     for(j=0;j<9;j++) {
          for(k=0;k<81;k++){
             if(giris[k].plakaKodu2==giris[i].komsu2[j]) {
                l2[i]=giris[k].lat2;
                lg2[i]=giris[k].long2;
                r2[i]=giris[k].rakim2;

                latF[k]=(pi/180)*(l1[i]-l2[i]);
                longF[k]=(pi/180)*(lg1[i]-lg2[i]);
                rakimFark[k]=(r1[i]-r2[i]);

        double rr=(double)rakimFark[k];

               /// *** HAVERSINE *** ///
        aa=sin(latF[k]/2)*sin(latF[k]/2)+cos((pi/180)*l1[i])*cos((pi/180)*l2[i])*sin(longF[k]/2)*sin(longF[k]/2);
        double aa2=fabs(1-aa);
        double aa3=fabs(aa);
        cc=2*atan2(sqrt(aa3),sqrt(aa2));
        giris[i].distance[j]=R*cc;


if (i+1==baslangic){
          yeniEgim[k]=atan((rr+50.0)/giris[i].distance[j]);
          giris[i].egimF[j]=yeniEgim[k]*(180/pi);
          giris[i].egimF2[j]=giris[i].egimF[j];
          giris[i].hipo[j]=sqrt(pow(giris[i].distance[j],2)+pow((0.001*(rr+50.0)),2)); // rakim farklari km
          giris[i].hipo2[j]= giris[i].hipo[j];
          // printf("dddd %lf  ",giris[i].egimF[j]);
          //  printf("%d: %lf  ",i,giris[i].hipo[j]);
                 }
else {
          yeniEgim[k]=atan((rr)/giris[i].distance[j]);
          giris[i].egimF[j]=yeniEgim[k]*(180/pi);
          // printf(" %lf  ",giris[i].egimF[j]);
          giris[i].egimF2[j]=giris[i].egimF[j];
          giris[i].hipo[j]=sqrt(pow(giris[i].distance[j],2)+pow((0.001*(rr)),2)); // rakim farklari km oldu
          giris[i].hipo2[j]= giris[i].hipo[j];
         //printf("%d: %lf  ",i,giris[i].hipo[j]);
     }}}
         //printf(" %lf  ",giris[i].egimF[j]);
}        //printf("\n");
}
/// ***********************
int secim;
sec:
printf("\n\nHangi Problemi Cozmek Istiyorsunuz?\n");
printf("1 -Sabit ucretle kac yolcu ile sefer duzenlenirse en cok kari yapabilirim?\n");
printf("2 -Bir yolcudan kac TL alinirsa yuzde 50 kar yapilabilir?\n");
scanf("%d",&secim);

    switch(secim){
     case 1: SabitUcretProblemi (baslangic,bitis); break;
     case 2: YuzdeElliKarProblemi(baslangic,bitis); break;
     default : printf("Yanlis secim yaptiniz.\n"); goto sec;
                }
time(&end);
printf("\n\nProgramin Calisma Suresi: %.4lf\n",difftime(end,start1));

return 0;
}
///*************** P U S H **************///

void push(struct graf** start, int veri,double mesafe) {
     struct graf* node = YeniDugum(veri,mesafe);
   node->sonraki = *start;
    *start = node;
    //printf( "push %d \n",node->dugum);
   }

  ///************* P O P *****************///
int pop(struct graf** start) {
        if (bosmu(*start))
           {  }
struct graf* eklenecek = *start;
  *start = (*start)->sonraki;
int alinan = eklenecek->dugum;
//printf("pop %d\n",eklenecek->dugum);
      free(eklenecek);
       }


///************ B O S M U ****************///
int bosmu(struct graf *start)
{    return !start; }

///***************** Y A Z D I R ******************///
void yazdir(struct graf *start)
{
if(start==NULL) { }
else {
    printf("%d \n",start->dugum);
    printf("%d \n",start->kenar);
    yazdir(start->sonraki);
     }
}
///*********************************************************************************************************************

int rotaHesaplaniyor(int source,int dest,double egim) {

int i,j,n;
//FILE *dosya3=fopen("cozum.txt","a+");
i=source-1;
basadon:
for(j=0;j<9;j++) {
        if((giris[i].egimF2[j]>30.0 && giris[i].egimF2[j]<=egim && giris[i].egimF2[j]!=0.0) || (giris[i].egimF2[j]<-30.0 && giris[i].egimF2[j]>=-egim && giris[i].egimF2[j]!=0.0) ){
             if(grafControl(source)== 0) {
             double min=giris[i].hipo2[j];
             int minindex=j;

             for(n=0;n<9;n++) {
                if (min>giris[i].hipo2[n] && giris[i].hipo2[n]!=0 ) {
                    if(giris[i].egimF2[n]<=egim && giris[i].egimF2[n]>=-(egim) && giris[i].egimF2[n]!=0.0){
                        min=giris[i].hipo2[n];
                        minindex=n;
                               }
                             }
                           }
               source=giris[i].komsu2[minindex];
               min=giris[i].hipo2[minindex];

             //  fprintf(dosya3,"Sehir: %d \n", source);
             //  fprintf(dosya3,"Gidilen mesafe: %lf \n",min);

               push(&start,source,min);
               d[m]=source;
               path[m]=giris[i].hipo2[minindex];
               m++;
              // fprintf(dosya3,"----------------------------------------\n");

               if(source==dest) {
                    printf("İstenilen yere ulasildi\n");
                    goto sonagit;
                }  else
               {rotaHesaplaniyor(source,dest,egim);}

        } else if(grafControl(source)==1) {
               egimSifirla(source,giris[i].komsu2[j]);
               giris[i].egimF2[j]=0.0;
               pop(&start);
               d[m]=0;
               goto basadon;
        }
    }
}
source=d[m-1];
sonagit:  printf("\n");
}

///************************************* P R O B L E M L E R ************************************************
struct sabitUcret {
double karOrani;
int indeks;
}kar[47],t;

void SabitUcretProblemi(int baslangic,int bitis) {

FILE *dosya3=fopen("cozum.txt","w+");
fprintf(dosya3,"Baslangıc sehri: %d \n",baslangic);

int i,j,y,k,w=0,a=0;
int yolcuSay;
double egim;
double zeplinMaaliyet[46],yolcuMaaliyet[46];
double ucret=100.0;

printf("Baslangic sehri: %d \n",baslangic);
push(&start,baslangic,0.0);
d[0]=baslangic;

for(y=5;y<51;y++) {
    yolcuSay=y;
    egim=80.0-(double)yolcuSay;

    rotaHesaplaniyor(baslangic,bitis,egim);

    double path2[50]={0};
    double hipoToplam=0.0;

    for(i=0; i<30;i++){
        for(j=0; j<30;j++){
            if(path[j]==path[i])   {a++;}
                }if(a==1) {path2[i]=path[i];}
                else {path[i]=0.0; }
                            a=0;}

    for(k=0;k<20;k++)
    { hipoToplam+=path2[k];}
    printf("\nToplam gidilen yol:%lf \n",hipoToplam);

zeplinMaaliyet[w]=(hipoToplam/100.0)*1000.0;
yolcuMaaliyet[w]=ucret*(double)yolcuSay;
kar[w].karOrani=( (yolcuMaaliyet[w]-zeplinMaaliyet[w])/zeplinMaaliyet[w] )*100.0;
kar[w].indeks=w;
printf("%d yolcuda kar: %%%lf\n",w+5,kar[w].karOrani);
    w++;
}
printf("\n\n");

for(i=0;i<w-1;i++) {
    for(j=0;j<w-i-1;j++) {
      if (kar[j].karOrani<kar[j+1].karOrani)
      {
        t=kar[j];
        kar[j]=kar[j+1];
        kar[j+1]=t;
      }
    }
  }

printf("Max kar %d kisi ile saglanmistir\n\n",kar[0].indeks+5);
double maxEgim=80.0-(double)(kar[0].indeks+5);
d[0]=baslangic;
rotaHesaplaniyor(baslangic,bitis,maxEgim); // max karli yol icicn

a=0;
double maxPath[50]={0};
for(i=0; i<20;i++){
    for(j=0; j<20;j++){
        if(path[j]==path[i])   {a++;}
            }if(a==1) {maxPath[i]=path[i];}
            else {path[i]=0.0; }
        a=0;  }

yaz(maxPath,bitis,1);


for(k=1;k<46;k++) {
printf("%d yolcu sayisi icin gidilen yollar ve mesafeleri:\n",kar[k].indeks+5);
egim=80.0-(double)(kar[k].indeks+5);
d[0]=baslangic;

rotaHesaplaniyor(baslangic,bitis,egim);
a=0;
printf("Baslangic: %d\n",baslangic);
double path3[50]={0};
for(i=0; i<30;i++){
    for(j=0; j<30;j++){
     if(path[j]==path[i])   {a++;}
    }if(a==1) {path3[i]=path[i];}
    else {path[i]=0.0; }
    a=0;       }

for(y=0;y<30;y++) {
    if(d[y]==0 || path3[y]==0.0) {
        continue;
    }  else {
    printf("Sehir: %d\n ",d[y]);
    printf("Gidilen mesafe: %lf\n",path3[y]);
}   printf("-------------------- \n");
     }
printf("\n");
}

fclose(dosya3);
}
///****************************************************************************************************************************

void YuzdeElliKarProblemi (int baslangic,int bitis){

FILE *dosya3=fopen("cozum.txt","w+");
fprintf(dosya3,"Baslangic sehri: %d\n ",baslangic);

int yolcuSay=10,a=0,w=0,i,j;
double zeplinMaaliyet[5],yolcuMaaliyeti[5];

printf("Baslangic sehri: %d\n",baslangic);
d[0]=baslangic;
push(&start,baslangic,0.0);

while(yolcuSay<51){

    double egim=80.0-(double)yolcuSay;

    rotaHesaplaniyor(baslangic,bitis,egim);

      double path2[50]={0};
      double hipoToplam=0.0;

        for(i=0; i<20;i++){
            for(j=0; j<20;j++){
                if(path[j]==path[i])
                          {a++;}
            }if(a==1)
                {path2[i]=path[i];}
            else
            {path[i]=0.0; }
                a=0;}

        for(i=0;i<20;i++)
        {  //printf("+++++++++++++++++++++ %lf-- \n",path2[i]);
            hipoToplam+=path2[i];
        }     printf("\nToplam gidilen yol:%lf \n",hipoToplam);


zeplinMaaliyet[w]=(hipoToplam/100.0)*1000.0;
yolcuMaaliyeti[w]=(1.5*zeplinMaaliyet[w])/(double)yolcuSay;

printf("%%50 kar icin %d kisi icin Yolcu maaliyeti: %lf  TL\n",yolcuSay,yolcuMaaliyeti[w]);
printf("%d kisi icin gidilen sehirler ve aralarindaki mesafeler\n",yolcuSay);
yaz(path2,bitis,2);

w++;
int d[100]={0};

yolcuSay+=10;
    }

fclose(dosya3);
}

///******************///

void yaz(double p[],int bitis,int secim){
FILE *dosya3=fopen("cozum.txt","a+");
int i,j;

if(secim==1) {
    fprintf(dosya3,"Sabit ucret problemi \n");
} else if(secim==2) {
    fprintf(dosya3,"Yuzde elli kar problemi \n");
}

for(i=0;i<30;i++)
{   if(d[i]==0 || p[i]==0.0) {
        continue;
    }  else {
        for(j=0;j<81;j++) {
        if(d[i]==giris[j].plakaKodu2) {
            if(d[i]==bitis) {
            printf("Bitis sehri:%d \n",d[i]);
            printf("Gidilen mesafe:%lf \n",p[i]);

            fprintf(dosya3,"Bitis sehri: %d \n", d[i]);
            fprintf(dosya3,"Lat: %lf- Long: %lf  \n",giris[j].lat2,giris[j].long2);
            fprintf(dosya3,"Gidilen mesafe: %lf \n",p[i]);
            fprintf(dosya3,"---------------------------------- \n");
        }  else {
        printf("Sehir:%d \n",d[i]);
        printf("Gidilen mesafe:%lf \n",p[i]);

        fprintf(dosya3,"Sehir: %d \n", d[i]);
        fprintf(dosya3,"Lat: %lf- Long: %lf  \n",giris[j].lat2,giris[j].long2);
        fprintf(dosya3,"Gidilen mesafe: %lf \n",p[i]);
        fprintf(dosya3,"---------------------------------- \n");
        }
    }              }    }
    printf("\n");
}

}
///******************///

void egimSifirla(int a,int b) {
int i,j;
for(i=0;i<81;i++) {
    if(giris[i].plakaKodu2==b) {
        for(j=0;j<9;j++) {
            if(giris[i].komsu2[j]==a){
                giris[i].egimF2[j]=0;
            }        }    }         }
}
///******************///

int grafControl(int source){
     temp=start;
     while(temp!=NULL){
            if(temp->dugum==source) {
                return 1;
            }
     temp=temp->sonraki;
}
return 0;
}


