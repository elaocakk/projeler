#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
    //struct node* giris;
   // struct node* cikis;
};
struct node* giris=NULL;
//struct node* maze=NULL;
//struct node* cikis=NULL;
struct node* start = NULL;
struct node* temp=NULL;

struct node* dugum_olustur(int veri)
{
    struct node* yeni_dugum = (struct node*)malloc(sizeof(struct node));
    yeni_dugum->data = veri;
    yeni_dugum->next = NULL;
    yeni_dugum->prev = NULL;

    return yeni_dugum;
}
struct stack{
    int veri;
    struct stack* sonraki;
};
struct stack *top=NULL;

int say=0;
///******************************************D U G U M E  E K L E M E *************************************///

void ekle(int veri,int satir , int sutun)  ///Çift yönlü bagli listede sona dügüm ekleyen fonksiyon
{
    struct node* eklenecek = dugum_olustur(veri);

    if (start == NULL){
        start = eklenecek;
        say++;
    }
    else{
       struct node* temp = start;
        while (temp->next != NULL){
            temp = temp->next;
        }
        eklenecek->prev = temp;
        temp->next = eklenecek;
say++;
    }
    eklenecek->next=NULL;
}

///********************************************* L A B I R E N T  C O Z M E **********************************************///
void labirentcoz(int satir,int  sutun, int x1,int  y1, int x2 ,int y2) {
int i;

if(giris->next->data==1 && y1!=(sutun-1) )  ///sag icin
{
push(&top,giris->data);
giris->data=2;
giris=giris->next;
y1++;
labirentcoz(satir, sutun, x1, y1, x2 ,y2);
}
else if (giris->next->data==0  || (y1==sutun-1) ) {    /// asagi icin
      push(&top,giris->data);
      giris->data=2;
      i=0;
      while(i<sutun)
      {
       giris=giris->next;
        i++;
      }
       if(giris->data==1){
            x1++;
            labirentcoz(satir, sutun, x1, y1, x2 ,y2);
        }
        else if(giris->data==0 ) ///asagisi olmuyorsa
            {
             i=0;
             while(i<sutun)
                  {
                   giris=giris->prev;
                    i++;
                }
                giris->data=1;
                pop(&top);
                goto sol;
           }
}
else if(giris->prev->data==1 && y1!=0 /* giris->prev->data!=NULL*/)  ///sol icin
{
    sol:
      if (giris->prev->data==1 && y1!=0 /*giris->prev->data!=NULL*/)
      {
         push(&top,giris->data);
         giris->data=2;
         giris=giris->prev;
         y1--;
         labirentcoz(satir, sutun, x1, y1, x2 ,y2);
          }
      else if (giris->prev->data==0  || y1==0 ) { /// yukari icin
           push(&top,giris->data);
           giris->data=2;
           i=0;
            while (i<sutun)
             {
              giris=giris->prev;
                  i++;
             }
            if(giris->data==1){
            x1--;
            labirentcoz(satir, sutun, x1, y1, x2 ,y2);
            }
            else if(giris->data==0)
            {
            i=0;
            while (i<sutun)
             {
              giris=giris->next;
                  i++;
             }
             giris->data=2;
             pop(&top);
             goto bitir;
            }
            }
}
else  {
        bitir:
        printf("aaaaaaaaa");

        if(x1==0) { // koþede olup olmadigim kontrol ediliyor
              if(x1==x2 && y1==y2){printf ("\nyol bulundu");}
               else { goto t;} }
        else if(y1==0) {
               if(x1==x2 && y1==y2){printf ("\nyol bulundu");}
               else { goto t; }}
        else if(x1==satir-1) {
               if(x1==x2 && y1==y2){printf ("\nyol bulundu");}
               else { goto t; }}
        else if(y1==sutun-1) {
              if(x1==x2 && y1==y2){printf ("\nyol bulundu");}
               else {goto t; }}
        else {
        t:
        printf("bbbbbbb");

        if(giris->next->data==2 || giris->data==3) /*&& y1!=sutun-1 ) */           ///sag
        {
           if(y1==(sutun-1)) {goto tekrarr;}

            //giris->data=3;
             if(giris->data==3) {goto s ;}

            if(giris->next->data==2 ) {
                    giris->data==4;
                    giris=giris->next;
                    y1++;
            }
            else if(giris->next->data!=2 || giris->data==3) /*&& x1!=satir-1 ) */     ///asagi
              {     tekrarr :
                  if(x1==(satir-1)) { goto tekrarr2 ; }

           // giris->data=3;
           if(giris->data==3) { goto s; }

             i=0;
             while(i<sutun)  { giris=giris->next; i++;}

             if(giris->data==2 )
                        { i=0;  while(i<sutun)  { giris=giris->prev ; i++;}
                            giris->data==4 ;

                            i=0;  while(i<sutun)  { giris=giris->next ; i++;}
                            x1++;
        } else if (giris->data!=2){
            i=0;  while(i<sutun)  { giris=giris->prev ; i++;}
            goto sool;
                        }
            }
        else if(giris->prev->data==2 || giris->data==3) /*&& y1!=0 ) */     ///sol
         {  sool:
            if(giris->prev->data==2 || giris->data==3) {

             tekrarr2:
            if(y1==0) {goto tekrarr3;}

             //giris->data=3;
             if(giris->data==3) {goto s ;}

             if(giris->prev->data==2 ) {
                    giris->data==4 ;
                    giris=giris->prev;
                    y1--;
              }
            else if(giris->prev->data!=2 || giris->data==3) /*&& x1!=0 )*/ ///yukari
        {
           tekrarr3:
            if(x1==0) { goto tekrarr4 ; }

            //giris->data=3;
            if(giris->data==3) { goto s; }

             i=0;
             while(i<sutun)  { giris=giris->prev; i++;}

               if(giris->data==2) { i=0;  while(i<sutun)  { giris=giris->next ; i++;}
                                        giris->data==4 ;

                                    i=0;  while(i<sutun)  { giris=giris->prev ; i++;}
                                    x1--;
            } else if(giris->data!=2) {
                i=0;  while(i<sutun)  { giris=giris->next ; i++;}
                goto tekrarr4;
            }
        }
        } }
       else {
                tekrarr4:

        if(giris->next->data==4) {  /// sag
            giris->data=3;
            y1++;
            giris=giris->next;
            goto q1;
        }else if(giris->next->data!=4) { /// asagi
                i=0;
                while(i<sutun) {giris=giris->next; i++;}

                if(giris->data==4) {
                i=0;
                while(i<sutun) {giris=giris->prev; i++;}
                giris->data=3;

                i=0; while(i<sutun) {giris=giris->next; i++;}
                 x1++;
                } else {
                    i=0;
                    while(i<sutun) {giris=giris->prev; i++;}
                    goto q;}

        } q:
         if(giris->prev->data==4) {  /// sol
                giris->data=3;
                giris=giris->prev;
                y1--;}
        else if(giris->prev->data!=4) {  /// yukari
                i=0;
                while(i<sutun) {giris=giris->prev; i++;}

                if(giris->data==4) {
                i=0; while(i<sutun) {giris=giris->next; i++;}
                giris->data=3;
                x1--;
                i=0; while(i<sutun) {giris=giris->prev; i++;}
                } else {
                  i=0;
                    while(i<sutun) {giris=giris->next; i++;}
                    goto q1;}
                  }
        }
       }

       q1:
        pop(&top);
        labirentcoz(satir, sutun, x1, y1, x2 ,y2);
        }

}

s :
yazdir(satir,sutun);


         exit(0);
}



  ///********************************* P O P ****************************************///
int pop(struct stack** top) {
        if (bosmu(*top))
           {  }
struct stack* eklenecek = *top;
  *top = (*top)->sonraki;
int alinan = eklenecek->veri;
      free(eklenecek);
        return alinan;
}

///********************************* B O S M U ***************************************///
int bosmu(struct stack *top)
{    return !top; }

///*********************************** P U S H **************************************///
void push(struct stack**top, int veri) {
     struct stack* node = dugum_olustur(veri);
   node->sonraki = *top;
    *top = node;
   }

///********************************************* Y A Z D I R **************************///
int yazdir(int satir, int sutun)
{
    printf("\n");
   int i,j;
    printf("\n");

   for(i=0; i<satir; i++)
   {
       for(j=0; j<sutun; j++)
       {
           if(start->data==0 || start->data==1 /*|| start->data==3*/)
            {start->data=0; }

        printf(" %d ",start->data);
        start=start->next;

       }printf("\n");
   }
}

///********************************* M A I N **************///
int main()
{
  int i,j,satir,sutun;
  int x1,x2,y1,y2;
  printf("matrisin satirini giriniz:"); scanf("%d",&satir);
  printf("matrisin sutununu giriniz:"); scanf("%d",&sutun);
  int matris[satir][sutun];

  srand(time(NULL));
for(i=0; i<=satir; i++){
    for(j=0; j<sutun; j++){
        matris[i][j]=rand()%2;

        printf(" %d ", matris[i][j]);

        ekle (matris[i][j],satir ,sutun);
        } printf("\n");
    }

bir:
printf("\ngiris koordinatlarini giriniz:");
printf("\nx1: ");  scanf("%d",&x1); fflush(stdin);
printf("y1: ")  ;  scanf("%d",&y1);  fflush(stdin);
if(x1>=satir || y1>=sutun) { printf("daha kucuk bir koordinat giriniz:"); goto bir; }
else {};
if (matris[x1][y1]==1)
{
    if(x1!=0 && x1!=(satir-1) )
    {
        if(y1!=0 && y1!=(sutun-1) )
              {printf("iceriden giris yapilmaz"); goto bir;} }
    else if (x1==0 || x1==satir-1)
    { if(y1==0 || y1==sutun-1)
        { goto iki; }}

}
else if(matris[x1][y1]==0) { printf("\nburadan giremezsiniz."); goto bir; }

iki:
printf("cikis koordinatlarini giriniz:");
printf("\nx2: "); scanf("%d",&x2); fflush(stdin);
printf("y2: "); scanf("%d",&y2); fflush(stdin);

if(x2>=satir || y2>=sutun) { printf("daha kucuk bir koordinat giriniz:"); goto iki; }
else {};
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
int sayac=0;

if(sayac==sutun*x1+y1) {}
  else {
    while(sayac<(sutun*x1+y1)){
        giris=giris->next;
        sayac++;
    }
  }
  giris->data=2;
labirentcoz(satir, sutun, x1, y1, x2 ,y2);

}








