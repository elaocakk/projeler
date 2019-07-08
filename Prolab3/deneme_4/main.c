#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>

void labirentcoz(int satir, int sutun, int x1, int y1, int x2,int y2, int matris[satir][sutun] );
struct stack {
        int veri;
        struct stack* sonraki;
        };

struct stack* YeniDugum(int veri) {
      struct stack* node = (struct stack*) malloc(sizeof(struct stack));
    node->veri = veri;
    node->sonraki = NULL;
      return node; }

struct stack* start = NULL;

///********************************* P U S H *****************************************///
void push(struct stack** start, int veri) {
     struct stack* node = YeniDugum(veri);
   node->sonraki = *start;
    *start = node;
   }

  ///********************************* P O P ****************************************///
int pop(struct stack** start) {
        if (bosmu(*start))
           {  }
struct stack* eklenecek = *start;
  *start = (*start)->sonraki;
int alinan = eklenecek->veri;
      free(eklenecek);
        return alinan; }

///********************************* B O S M U ***************************************///
int bosmu(struct stack *start)
{    return !start; }

///********************************* Y A Z D I R *************************************///
void yazdir(int satir, int sutun, int matris[satir][sutun])
{
   int i,j;
    printf("\n\n");

   for(i=0; i<satir; i++)
   {
       for(j=0; j<sutun; j++)
       {
           if(matris[i][j]==0 || matris[i][j]==1 )
       {matris[i][j]=0; }
       else if(matris[i][j]==2 || matris[i][j]==4)
       {
           matris[i][j]=2;
       }
        printf(" %d ", matris[i][j]);
       }printf("\n");
   } }
///*************************************** L A B I R E N T C O Z *****************************************///

void labirentcoz(int satir, int sutun, int x1, int y1, int x2,int y2, int matris[satir][sutun] ){
//matris[x1][y1]=2;
if(matris[x1][y1+1]==1 && y1!=(sutun-1))    ///sag
{
    push(&start,matris[x1][y1]);y1++;
    matris[x1][y1]=2;
    labirentcoz(satir,sutun,x1,y1,x2,y2,matris);
}
else if(matris[x1+1][y1]==1)                ///asagi
{
    push(&start,matris[x1][y1]);x1++;
    matris[x1][y1]=2;
    labirentcoz(satir,sutun,x1,y1,x2,y2,matris);
}
else if(matris[x1][y1-1]==1 && y1!=0)        ///sol
{
    push(&start,matris[x1][y1]);y1--;
    matris[x1][y1]=2;
    labirentcoz(satir,sutun,x1,y1,x2,y2,matris);
}
else if(matris[x1-1][y1]==1)                ///yukari
{
    push(&start,matris[x1][y1]);x1--;
    matris[x1][y1]=2;
    labirentcoz(satir,sutun,x1,y1,x2,y2,matris);
}
else  {
        if(x1==0) {
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
    if(matris[x1][y1+1]==2 || matris[x1][y1]==3)       ///sag
{
    matris[x1][y1]=5;
    if(matris[x1][y1+1]==2 ){matris[x1][y1]=4;}  if(matris[x1][y1]==5) { goto s;}
     y1++;
}
     else if(matris[x1+1][y1]==2 || matris[x1][y1]==3 )   ///asagi
{
    matris[x1][y1]=5;
     if(matris[x1+1][y1]==2 ) {matris[x1][y1]=4;}if(matris[x1][y1]==5 ) {goto s;} x1++;
}
    else if(matris[x1][y1-1]==2 || matris[x1][y1]==3 )      ///sol
{
      matris[x1][y1]=5;
       if(matris[x1][y1-1]==2 ) {matris[x1][y1]=4;} if(matris[x1][y1]==5) {goto s;}y1--;
}
   else if(matris[x1-1][y1]==2 || matris[x1][y1]==3 )      ///yukari
{
      matris[x1][y1]=5;
     if(matris[x1-1][y1]==2 ) {matris[x1][y1]=4;}if(matris[x1][y1]==5) { goto s;}x1--;
}
    else {

    if(matris[x1][y1+1]==4) {matris[x1][y1]=3; y1++;}     ///sag
      else if(matris[x1+1][y1]==4) {matris[x1][y1]=3; x1++;}
       else if(matris[x1][y1-1]==4) {matris[x1][y1]=3; y1--;}
      else if(matris[x1-1][y1]==4) {  matris[x1][y1]=3; x1--; } }
  pop(&start);
  labirentcoz(satir,sutun,x1,y1,x2,y2,matris);
    }
  }s :
yazdir(satir, sutun, matris);
exit(0);
}
///******************************************************************
int main()
{
    int i,j,satir,sutun;
    int x1,x2,y1,y2;
  printf("matrisin satirini giriniz:"); scanf("%d",&satir);
  printf("matrisin sutununu giriniz:"); scanf("%d",&sutun);
  int matris[satir][sutun];

  srand(time(NULL));
for(i=0; i<satir; i++){
    for(j=0; j<sutun; j++){
        matris[i][j]=rand()%2;
  printf(" %d ", matris[i][j]);
        } printf("\n");
    }

bir:
printf("\ngiris koordinatlarini giriniz:");
printf("\nx1: ");  scanf("%d",&x1); fflush(stdin);
printf("y1: ")  ;  scanf("%d",&y1);  fflush(stdin);
if(x1>=satir || y1 >=sutun) {printf("daha kucuk bir koordinat giriniz."); goto bir;}
else {};
if (matris[x1][y1]==1)
{
  if(x1!=0 && x1!=(satir-1))
    {
        if(y1!=0 && y1!=(sutun-1))
              {printf("iceriden giris yapilmaz"); goto bir;} }
    else if (x1==0 || x1==satir-1)
    { if(y1==0 || y1==sutun-1)
        { goto iki; }}

}
  else if(matris[x1][y1]==0) { printf("\nburadan giremezsiniz."); goto bir; }
  iki:
printf("\ncikis koordinatlarini giriniz:");
printf("\nx2: "); scanf("%d",&x2); fflush(stdin);
printf("y2: "); scanf("%d",&y2); fflush(stdin);
if(x2>=satir || y2 >=sutun) {printf("daha kucuk bir koordinat giriniz."); goto iki;}
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
matris[x1][y1]=2;
labirentcoz(satir,sutun,x1,y1,x2,y2,matris);
}
