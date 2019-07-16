#include <stdio.h>
#include <stdlib.h>
//#include <file.h>
#include <math.h>
#include <limits.h>
#include <string.h>

#define notV 1
#define wairting 2
#define visited 3

/*
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
*/

struct node{
    int plaka;
    int counter;
    int state;

    struct node *komsular[100];
    struct node *next;
    struct node *prev;
};
struct node *start=NULL;
struct node *last=NULL;
struct node *temp;

void ekle(int plakaKodu) {
    struct node *yeni=(struct node*)malloc(sizeof(struct node));
    yeni->plaka=plakaKodu;
    yeni->counter=0;
    yeni->state=notV;
    yeni->next=NULL;

    if(start==NULL) {
        start = yeni;
        last=yeni;
    } else {
        last->next=yeni;
        last=yeni;
    }
}

void yazdir(){
temp=start;
while(temp->next!=NULL) {
    printf("%d",temp->plaka);
    temp=temp->next;
}
}

///********************************
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

struct path {
    int gidilenYol;
    double mesafe;
} path[81];

int varmi(int deger,struct path *p) {
int i;
for(i=0;i<81;i++){
    if(p[i].gidilenYol==deger) {
       // printf("daha önce gidilmiþ\n");
        return 1;
}
        }
return 0;
}

int main()
{
FILE *dosya=fopen("latlong.txt","r");
int i;
i=0;
if(fopen("latlong.txt","r")){
printf("dosya acildi\n");
}
int a=0;

 if(dosya!=NULL){
       for(i=0;i=!feof(dosya);i++){
        fscanf(dosya,"%s %s %s %s",giris[a].lat,giris[a].long1,giris[a].plakaKodu,giris[a].rakim);
        a++;    }

 }
 fclose(dosya);
for(i=0;i<82;i++){
    //   printf("%s %s %s %s\n",giris[i].lat,giris[i].long1,giris[i].plakaKodu,giris[i].rakim);
         }
int q1,q2;
double x,y,z,t;

for(i=0; i<81; i++){
        sscanf(giris[i].lat,"%lf",&x);         giris[i].lat2=x;
        sscanf(giris[i].long1,"%lf",&y);       giris[i].long2=y;
        sscanf(giris[i].plakaKodu,"%lf",&z);  q1=z; giris[i].plakaKodu2=q1, giris[i].plakaKodu3=q1;
        sscanf(giris[i].rakim,"%lf",&t);     q2=t;  giris[i].rakim2=q2;

//printf("%lf %lf %d %d\n",lat2[i],long2[i],plakaKodu2[i],rakim2[i]);
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
i++;

}
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

        //printf("d:^^%lf^^---",giris[i].distance[j]);
        //printf("^^%lf^^",giris[i].hipo[j]);
          // printf("e:^^%lf^^",giris[i].egimF[j]);printf("\n");
            }
    }
    }

}

/// ***********************
int yolcuSay, ucret;
double kar,egim;

tekrar:
printf("Yolcu Sayýsýný Giriniz: ");
scanf("%d",&yolcuSay);

if(yolcuSay<5 || yolcuSay>50){
    printf("Eksik veya Fazla Yolcu Girdiniz!");
    goto tekrar;
}

egim=80.0-(double)yolcuSay;
printf("zeplinin egimi:%lf\n",egim);

int baslangic,bitis;
int start[20];

printf("baslangýc sehrinin plakasini girin:");
scanf("%d",&baslangic);
//start[0]=baslangic;

printf("bitis sehrinin plakasini girin:");
scanf("%d",&bitis);

int n,b,d;
int minindex;
int p=0,q=0;

bastan:
for(i=0;i<81;i++) {
        //printf("i:%d-",i);

       if(baslangic==bitis) {
        path[q].gidilenYol=giris[i].plakaKodu3;
        printf("istenilen yere ulasildi\n");
        break;
       }
       else if(giris[i].plakaKodu3==baslangic) {
        //     ekle(giris[i].plakaKodu2);
            path[q].gidilenYol=giris[i].plakaKodu3;  //baslangic ilk elemana esitlendi
            path[p].mesafe=0; // ilkinde mesafe yok sonucta


            for(j=0;j<9;j++) { // komsulari arasinda yol ariyoruz egimi kontrol ederek
                if(giris[i].egimF[j]<=egim && giris[i].egimF[j]!=0) {

                    double min=giris[i].hipo2[j];

                   // path[p+1].mesafe=giris[i].hipo2[j];
                    minindex=j;
                    geri:
                    for(n=0;n<9;n++) {  //egimleri uygun olanlar arasindan en kucuk mesafeyi bulmaya calýsýyoruz
                        if (min>giris[i].hipo2[n] && giris[i].hipo2[n]!=0 ) {
                            min=giris[i].hipo2[n];

                            //path[p+1].mesafe=giris[i].hipo2[n];
                            minindex=n;

                           /* for(b=0;b<20;b++) {
                                for(d=0;d<20;d++) {
                                    if(start[b]==path[q].gidilenYol){
                                        printf("aynilar");
                                        giris[i].k2[minindex];
                                    }
                                   }
                                } */

                            //bas2: printf("aaa\n");
                                }    }
                  //  printf("<%lf>\n",min);
                baslangic=giris[i].k2[minindex]; // gidilen en kýsa yoldaki sehir yine baslangic yapildi
                /*if(varmi(baslangic,&path)==1) { // yani daha önce gidilmis
                   giris[i].egimF[minindex]=0;
                   giris[i].hipo2[minindex]=0;
                    goto geri;
                }else if(varmi(baslangic,&path)==0) {
                path[p+1].mesafe=giris[i].hipo2[minindex];
                                } */       }



                    //ekle(giris[i].k2[n]);
                   // printf("-*%d*-*",giris[i].k2[n]);
                }

               // printf("komsu:%d\n",path[q].gidilenYol);
                printf("komsu olacak sehir:%d--\n",giris[i].k2[minindex]);
                path[p+1].mesafe=giris[i].hipo2[minindex];
                baslangic=giris[i].k2[minindex]; // gidilen en kýsa yoldaki sehir yine baslangic yapildi


                //giris[i].plakaKodu3=10000; giris[i].hipo2[minindex]=10000;
                q++;p++;
                goto bastan;
                }
    }

for(i=0;i<81;i++) {
    printf("****komsu:%d\n",path[i].gidilenYol);
}


 return 0;
}





