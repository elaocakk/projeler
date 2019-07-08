#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
void labirentcoz(int, int);
void ekle(int , int ,int );

struct node {
    int data;
    struct node* next;
    struct node* prev;
    struct node* giris;
    struct node* cikis;
};
struct node* giris=NULL;
struct node* maze=NULL;
struct node* cikis=NULL;
struct node* start = NULL;
struct node* temp=NULL;

struct node* dugum_olustur(int veri)///Dü?üm olusturup return eden fonksiyon
{
    struct node* yeni_dugum = (struct node*)malloc(sizeof(struct node));
    yeni_dugum->data = veri;
    yeni_dugum->next = NULL;
    yeni_dugum->prev = NULL;

    return yeni_dugum;
}

struct stack{
    int dataa;
    struct stack* sonraki;
};

struct stack *top=NULL;
int x1,x2,y1,y2;
int say=0;

void ekle(int veri,int satir , int sutun)  ///Çift yönlü ba?ly listede sona dü?üm ekleyen fonksiyon
{
    struct node* eklenecek = dugum_olustur(veri);

    if (start == NULL){ ///E?er listede hiç eleman yoksa yeni eleman ekliyoruz
        start = eklenecek;
        say++;
    }
    else{///traverse etmek için temp de?i?kenine start de?i?kenini atadyk, maksat start de?i?kenini bozmamak.
         ///A?a?ydaki döngü traverse yapyyor ve temp dü?ümü döngü sonunda son dü?üm oluyor.
       struct node* temp = start;
        while (temp->next != NULL){
            temp = temp->next;
        }
        ///temp elemany (eski son) oldu?u için sonaEklenecek (yeni son) dü?ümünün prev i?aretçisi tempi gösterecek.
        eklenecek->prev = temp;
        ///temp de?i?keninin next i?aretçisi ise artyk yeni son elemanymyz olan sonaEklenecek dü?ümünü i?aret edecek.
        temp->next = eklenecek;
say++;
    }
    eklenecek->next=NULL; //  en son eklenenin sonu NULL olacak

    if((sutun*satir)==say){
    if( eklenecek->prev!=NULL){

}}

}

void labirentcoz(int satir, int sutun) {
//giris=start;
int i;
int sayiS=0;
printf("aa");

   if(giris->next->data==1 || giris->next->data!=NULL )  ///sag icin
{
 push(giris->data);
 giris->prev->data=2;
 giris=giris->next;
 labirentcoz(satir,sutun);
}
 else if (giris->next->data==0 || giris->next->data==NULL) { /// asagi icin
    i=0;
    push(giris->data);
  while(i<sutun)
{
    giris=giris->next;
    i++;
}
    if(giris->data==0) {
        //pop();
    }
    else { labirentcoz(satir,sutun); }

}

 else if(giris->prev->data==1) ///sol icin
{
  push(giris->data);
  giris->prev->data=2;
  giris=giris->prev;
  labirentcoz(satir,sutun);
}
 else if (giris->prev->data==0 || giris->prev->data==NULL) { /// yukari icin

    push(giris->data);
 i=0;
    while (i<sutun)
        {
    giris=giris->prev;
    i++;
        }
        if(giris->data==0 || giris->data==NULL)
        { // pop();
        }
        else {labirentcoz(satir,sutun);}

        }
else {printf("yol yok"); exit(0);}
}


void pop()
{
    if(top->dataa==NULL) {printf("bos");}
    else
    {
        struct node* temp;
        temp=top;
        top=top->sonraki;
        free(temp);
    }

}
void push(int veri){
    struct stack* eklenecek=(struct stack*)malloc(sizeof(struct stack));
    eklenecek->dataa=veri;
    eklenecek->sonraki=NULL;
    if(top!=NULL){
        eklenecek->sonraki=top;
        top=eklenecek;
    }
printf(" ((%d))", eklenecek->dataa);
return 0;
}
int main()
{
  int i,j,satir,sutun;
  printf("matrisin satirini giriniz:"); scanf("%d",&satir);
  printf("matrisin sutununu giriniz:"); scanf("%d",&sutun);
  int matris[satir][sutun];

  srand(time(NULL));
 for(i=0; i<satir; i++){
    for(j=0; j<sutun; j++){
        matris[i][j]=rand()%2;
        printf(" %d ", matris[i][j]);
        ekle (matris[i][j],satir ,sutun);
    }
     printf("\n");
    }

bir:
printf("\ngiris koordinatlarini giriniz:");
printf("\nx1: "); scanf("%d",&x1);
printf("y1: "); scanf("%d",&y1);

if (matris[x1][y1]==1)
{
    if(x1!=0 && x1!=satir-1)
    { if(y1!=0 && y1!=sutun-1)
           {printf("iceriden giris yapilmaz"); goto bir;} }
    else if(x1==0 || x1==satir-1)
    { if(y1==0 || y1==sutun-1)
        { }}

}
else if(matris[x1][y1]==0) { printf("\nburadan giremezsiniz."); goto bir; }
iki:
printf("cikis koordinatlarini giriniz:");
printf("\nx2: "); scanf("%d",&x2);
printf("y2: "); scanf("%d",&y2);
if (matris[x2][y2]==1)
{
    if(x2!=0 && x2!=satir-1)
    { if(y2!=0 && y2!=sutun-1)
           {printf("iceriden cikis yapilmaz"); goto iki;} }
    else if(x2==0 || x2==satir-1)
    {  if(y2==0 || y2==sutun-1)
         { }
    }
}
else if(matris[x2][y2]==0) { printf("\nburadan cikamazsiniz."); goto iki; }

printf("\n");
giris=start;
int sayac=-1;
   while(sayac<(sutun*x1+y1)){
        giris=giris->next;
        sayac++;
    }
giris=giris->prev;

labirentcoz(satir, sutun);
    }
