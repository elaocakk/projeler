#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>


/// *********************************

struct giris {
    char lat[82], long1[82], plakaKodu[82],rakim[82];
    char komsu[9][82];

    double dizi2[82], lat2, long2;
    int plakaKodu2,rakim2,plakaKodu3;
    int k2[9];
    double egimF[9];
    double distance[9];
    double hipo[9],hipo2[9];
} giris[82];


int main()
{
FILE *dosya=fopen("latlong.txt","r");
int i;
i=0;
if(fopen("latlong.txt","r")){
printf("dosya acildi\n");
}
int a;
if(dosya!=NULL){
         a=0;
       for(i=0;i=!feof(dosya);i++){
        fscanf(dosya,"%s %s %s %s",giris[a].lat,giris[a].long1,giris[a].plakaKodu,giris[a].rakim);
        a++;    }
}
fclose(dosya);


for(i=0;i<81;i++){
      //printf("%s %s %s %s\n",giris[i].lat,giris[i].long1,giris[i].plakaKodu,giris[i].rakim);
         }
int q1,q2;
double x,y,z,t;

for(i=0; i<81; i++){

        sscanf(giris[i].lat,"%lf",&x);         giris[i].lat2=x;
        sscanf(giris[i].long1,"%lf",&y);       giris[i].long2=y;
        sscanf(giris[i].plakaKodu,"%lf",&z);  q1=z; giris[i].plakaKodu2=q1, giris[i].plakaKodu3=q1;
        sscanf(giris[i].rakim,"%lf",&t);     q2=t;  giris[i].rakim2=q2;


//printf("%lf %lf %d %d\n",giris[i].lat2,giris[i].long2,giris[i].plakaKodu2,giris[i].rakim2);
                }



FILE *dosya2;
dosya2=fopen("komsuluk.txt","r+");
int j;
i=0;
int c;
int e;
char ko[50];
char *ayrac=",";
if(dosya2!=NULL ) {
while(!feof(dosya2) && i<81) {
   // fscanf(dosya2,"%s %s %s %s %s %s %s %s %s %s",sehir[i].plakaKodu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu,sehir[i].komsu);

    fscanf(dosya2,"%s",ko);
    char *kelime=strtok(ko,ayrac);
    j=0;
    int m=0;
    while(kelime!=NULL) {
        if(j==0) {
            strcpy(giris[i].plakaKodu,kelime);
            sscanf(giris[i].plakaKodu,"%lf",&z);
            giris[i].plakaKodu2=z;
        // printf("%d\n",giris[i].plakaKodu2);
        } else {
            strcpy(giris[i].komsu[m],kelime);
            sscanf(giris[i].komsu[m],"%d",&c);
            giris[i].k2[m]=c;
          // printf("%d-",giris[i].k2[m]);
            m++;
        }
        kelime=strtok(NULL,ayrac);
        j++;
    }
//    printf("\n");
            i++;            }
                }

fclose(dosya2);

double yeniEgim[500];
int rakimFark[500];
double latF[500];
double longF[500];
double aa,cc;
double R=6371;
int k=0;
double pi = 3.141592653589793;

double l1[100],l2[100];
double lg1[100],lg2[100];
int r1[100],r2[100];

for(i=0;i<81;i++) {

    l1[i]=giris[i].lat2;
    lg1[i]=giris[i].long2;
    r1[i]=giris[i].rakim2;

    for(j=0;j<9;j++) {
         for(k=0;k<81;k++){
            if(giris[k].plakaKodu2==giris[i].k2[j]) {
                l2[i]=giris[k].lat2;
                lg2[i]=giris[k].long2;
                r2[i]=giris[k].rakim2;

            latF[k]=(pi/180)*(l1[i]-l2[i]);
            longF[k]=(pi/180)*(lg1[i]-lg2[i]);
            rakimFark[k]=(r1[i]-r2[i]);

            double rr=(double)rakimFark[k];

          //  printf("%lf-%lf-%d\n", latF[k],longF[k],rakimFark[k]);

               // *** HAVERSÝNE *** //
        aa=sin(latF[k]/2)*sin(latF[k]/2)+cos((pi/180)*l1[i])*cos((pi/180)*l2[i])*sin(longF[k]/2)*sin(longF[k]/2);
        double aa2=fabs(1-aa);
        double aa3=fabs(aa);
        cc=2*atan2(sqrt(aa3),sqrt(aa2));
        giris[i].distance[j]=R*cc;

        giris[i].hipo[j]=sqrt(pow(giris[i].distance[j],2)+pow((0.001*(rr+50.0)),2)); // rakim farklari km oldu
        giris[i].hipo2[j]=giris[i].hipo[j];

        yeniEgim[k]=atan((rr+50.0)/giris[i].distance[j]);
        giris[i].egimF[j]=yeniEgim[k]*(180/pi);

       // printf("^^%lf^^",giris[i].distance[j]);
        //printf("^^%lf^^",giris[i].hipo[j]);
       printf("%lf***  ",giris[i].egimF[j]);
            }
    }
    }
    printf("\n");
}

/// ***********************
int yolcuSay, ucret;
double kar,egim;
egim=75.0;
printf("zeplinin egimi:%lf\n",egim);

int baslangic,bitis;
printf("baslangýc sehrinin plakasini girin:");
scanf("%d",&baslangic);

printf("bitis sehrinin plakasini girin:");
scanf("%d",&bitis);
int n,b;
int minindex;

int q=0,p=0;

double G[81][81];
double E[81][81];

for(i=0;i<81;i++) {
    for(j=0;j<9;j++) {
        for(k=0;k<81;k++) {
        if(giris[k].plakaKodu2==giris[i].k2[j]) {
            int a=giris[k].plakaKodu2;
            int b=giris[i].plakaKodu2;

            G[b-1][a-1]=giris[i].hipo2[j]; /// hipoların oldugu matris

            E[b-1][a-1]=giris[i].egimF[j]; /// egimlerin oldugu matris
        }
        }
    }
}

for(i=0;i<81;i++) {
        printf("%d\n\n",i+1);
    for(j=0;j<81;j++) {
            printf("%lf-",G[i][j]);
    }
    printf("\n");
        }

dijkstra(G,E,81,baslangic,bitis,egim);


return 0;
}

# define INFINITY 99999999

void dijkstra(int G[][81],int E[][81],int n,int baslangic,int bitis,double egim) {
double cost[n][n];
int i,j,sayac,nextnode;
double mindistance;
 double distance[n];
 double pred[n];
 int visited[n][n]={0};


for(i=0;i<81;i++) {
    for(j=0;j<81;j++) {
            if(G[i][j]==0.0) {
                cost[i][j]=INFINITY;
            } else {
                cost[i][j]=G[i][j];
                }
    }      }

/*
for(i=0;i<n;i++) {
    distance[i]=cost[baslangic][i];
    pred[i]=baslangic;
    visited[i]=0;
}


distance[baslangic]=0.0;
visited[baslangic]=1;   */
sayac=1;

distance[0]=0.0;


while(sayac<n-1) {

for(i=0;i<81;i++) {
    if(baslangic==i+1) {
        mindistance=INFINITY;
        for(i=0;i<81;i++) {
            if( G[i][j] < mindistance && !visited[i][j]) {
                mindistance=G[i][j];
                nextnode=i;
    }
}
    visited[i][nextnode]=1;
    visited[nextnode][i]=1;  /// geri dönmesin diye engellemek icin


for(i=0;i<n;i++) {
            if(!visited[i][nextnode] || !visited[nextnode][i]) {
                if(mindistance + cost[nextnode][i] < G[i][j] ) {
                    G[i][j]=mindistance + cost[nextnode][i];
                }
            printf("%lf\n",G[i][j]);
            }   }

    }          }
        sayac++;
    }

    for(i=0;i<n;i++) {
            if(i!=baslangic) {
                printf("distance %d: %lf \n",i,distance[i]);
                printf("path: %d\n",i);
                j=i;

        do{
            j=pred[j];
            printf("%d---\n",j);
        } while (j!=baslangic) ;

                        }
            }

}

