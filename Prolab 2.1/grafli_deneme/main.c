#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <time.h>


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

/// ************** MAIN ******************
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


/// ************
int baslangic,bitis;
g:
printf("baslangic sehrinin plakasini girin:");
scanf("%d",&baslangic);
     if(baslangic>81 || baslangic==0)
        {goto g; }

d[0]=baslangic; // ilk sehri diziye attýk
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
double G[81][81];

for(i=0;i<81;i++) {
    for(j=0;j<9;j++) {
        for(k=0;k<81;k++) {
        if(giris[k].plakaKodu2==giris[i].k2[j]) {
            int a=giris[k].plakaKodu2;
            int b=giris[i].plakaKodu2;

            G[b-1][a-1]=giris[i].hipo2[j]; /// hipolarýn oldugu matris

            E[b-1][a-1]=giris[i].egimF[j]; /// egimlerin oldugu matris
        }
        }
    }
}


gidilenSehir[0]=baslangic;
gidilenMesafe[0]=0.0;

dijkstra(G,E,baslangic,bitis);




/*
/// *****************
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
*/

time(&end);
printf("\n\nProgramin Calisma Suresi: %.4lf\n",difftime(end,start1));

return 0;
}

/// **************************
#define INFINITY 9999
#define n 81
int gidilenSehir[25];
double gidilenMesafe[25];

void dijkstra(double G[][81],double E[][81],int baslangic,int bitis) {
int visited[81]={0};
double cost[81][81];

int i,j;

for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
        if(G[i][j]==0) {
            cost[i][j]=INFINITY; }
        else    {
            cost[i][j]=G[i][j];  }
} }

visited[baslangic+1]=1;

for(i=0;i<81;i++) {
    if(baslangic==i+1) {
        mindistance=INFINITY;

        for(j=0;j<81;j++) {
            if( G[i][j] < mindistance && !visited[i]) {
                mindistance=G[i][j];
                nextnode=i;     }
                }

visited[nextnode]=1;

for(i=0;i<n;i++) {
            if(!visited[i][nextnode] || !visited[nextnode][i]) {
                if(mindistance + cost[nextnode][i] < G[i][j] ) {
                    G[i][j]=mindistance + cost[nextnode][i];
                }
            printf("%lf\n",G[i][j]);
            }   }
    }
}


}


int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < 81; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
.
   return min_index;
}
