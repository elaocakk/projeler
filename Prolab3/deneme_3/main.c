#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>

void labirent_coz();
void giris_eleman(int ,int );
void cikis_eleman(int ,int );
void push(int );
void pop();

///******* MATRİS STACK İ *******///
struct node {
    int data;
    struct node* next;
    struct node* prev;
    struct node* up;
    struct node* down;
    struct node* giris;
    struct node* cikis;
};

struct node* giris=NULL;
struct node* cikis=NULL;
struct node* start = NULL;///Baþlangýç düðümü bizim için çok önemli, global deðiþken olarak tanýmladýk ve baþlangýçta NULL atadýk.
struct node* temp=NULL;
struct node* maze=NULL;

///******* DUGUM OLUSTURMA *******///
struct node* dugum_olustur(int veri)
{
    struct node* yeni_dugum = (struct node*)malloc(sizeof(struct node));
    yeni_dugum->data = veri;
    yeni_dugum->next = NULL;
    yeni_dugum->prev = NULL;
    yeni_dugum->up = NULL;
    yeni_dugum->down = NULL;

    return yeni_dugum;
}

///******* YİGİN STACK İ *******///
struct stack{
    int dataa;
    struct stack* sonraki;
};

struct stack *top=NULL;

///******* MATRİSE ELEMAN EKLEME *******///
int say=0;
void ekle(int veri,int satir,int sutun)
{   int i=0;
    struct node* eklenecek = dugum_olustur(veri);

    if (start == NULL){ //Eger listede hiç eleman yoksa yeni eleman ekliyoruz
        start = eklenecek;
        say++;
    }
    else{
       struct node* temp = start; // start degiskenini kaybetmemek icin

        while (temp->next != NULL){
            temp = temp->next; // temp son dugum oluyor
        }

        eklenecek->prev = temp; //  en son elemandan övce temp gelecek
        temp->next = eklenecek; // en son eklenen eleman temp den sonra gelecek



        while(i<sutun) {
            temp=temp->prev; // yukariyi bulabilmek icin

            if(temp->prev==NULL) {
                eklenecek->up=NULL;
                break;
            }
            i++;
        }
        eklenecek->up=temp;

         i=0;
       while(i<sutun*2) {
            temp=temp->next;// asagiyi bulabilmek icin

            if(temp->next==NULL) {
                eklenecek->down==NULL;
                break;
            }
            i++;
        }
        eklenecek->down=temp;

            say++;

}  //eklenecek->next=NULL; //  en son eklenenin sonu NULL olacak

    printf("%3d",eklenecek->data);
    if((sutun*satir)==say){
            if( eklenecek->prev!=NULL){
                printf("\n((%d))\n",eklenecek->prev->data );
                printf("[[%d]]",eklenecek->prev->prev->data);
                                    }
                        }
            }

///******* LABİRENTİ CÖZME *******///
void labirent_coz(int satir, int sutun) {

maze=giris; // girisi kaybetmemek icin yaptık
int i,j;

int sayiS=0;
while(sayiS<satir*sutun){

if(maze->next->data==1) { ///sag
    push(maze->data);
    maze->data=2;
    maze=maze->next;
}   else if (maze->next->data==0 || maze->next->data==2) { // saga gidis yok ise
       if(maze->prev->data==1) { ///sol
            push(maze->data);
            maze->data=2;
            maze=maze->prev;
      }  else if (maze->prev->data==0 || maze->prev->data==2) { // sola gidis yok ise

        push(maze->data);
        maze->data=2;

    /*    /// bu arada maze i bir seye esitle ve onu ilerlet veya gerilet sonra onu up veya down a esitle
        i=0;
        while(i<sutun){
            maze=maze->next;
              i++;
        } */


            if(maze->down->data==1) {

                push(maze->data);
                maze->data=2;
                printf("\n%d asagidaki\n",maze->data);
                maze=maze->down;
          }  else   {
           /* i=0;
               while(i<sutun)
                 {
                  maze=maze->prev;
                  i++;
                 }
                 push(maze->data);
                 j=0;
                 while(j<sutun)
                 {
                     maze=maze->prev;
                     j++;
                 } */

                 if(maze->up->data==1)  {
                    push(maze->data);
                    maze->data=2;

                    maze=maze->up;
                    printf("\n%d yukaridaki\n",maze->data);
                }  else if (maze->data==0 || maze->data==2 ||maze->data==NULL) {
                        printf("\nyol yok");
                        exit(0);
                            }
                    }
    }
    else {
        continue;
            }                                }
                sayiS++;
                            }

    printf("\nLabirent cozuldu\n");
}

void pop()
{
    if(top->dataa==NULL) {
            printf("bos");
    }  else  {
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


void giris_eleman(int satir,int sutun){

giris=start;
int gir,sayac;

tek:
girr:
printf("Labirente nereden baslansin?...: \n");
scanf("%d",&gir); fflush(stdin);

if(gir>satir*sutun) {
    printf("Matris elemanlarindan giris yapınız:\n");
    goto girr;
    }

if(gir%sutun==0) { // sol taraf
        sayac=0;
} else if(gir%sutun==sutun-1) { // sag taraf
        sayac=0;
} else if(gir/sutun==0) { // yukari
        sayac=0;
} else if(gir/sutun==satir-1) { //asagi
        sayac=0;
} else {
    printf("Labirentin icinden giris yapilamaz\n\n");
    goto tek;
}
//sayac=0;
  while(sayac<gir){ // giris elemanini buluyoruz
        giris=giris->next;
        sayac++;
    }

    if(giris->data==0) {
        printf("\nBuradan giris yoktur.\n");
    exit(0);
    }

    printf("\n||%d||\n", giris->data);

}

void cikis_eleman(int satir,int sutun){

cikis=start;
int cik,sayac;

tek:
cikk:
printf("Labirentin neresinden cikilsin?...:\n");
scanf("%d",&cik); fflush(stdin);

if(cik>satir*sutun) {
        printf("Matris elemanlarindan giris yapınız:\n");
    goto cikk;}

if(cik%sutun==0){ // sol taraf
        sayac=0;
} else if (cik%sutun==sutun-1) { // sag taraf
        sayac=0;
} else if(cik/sutun==0) {
     sayac=0;
} else if(cik/sutun==satir-1) {
    sayac=0;
} else {
    printf("labirentin icinden cikis yapilamaz\n\n");
    goto tek;
}

//sayac=0;
  while(sayac<cik){ // cikis elemani bulunur
        cikis=cikis->next;
        sayac++;
    }

    if(cikis->data==0) {
        printf("\nBuradan cikis yoktur.\n");
        exit(0);}

    printf("\n||%d||\n", cikis->data);

}

int main(){
    int satir,sutun,i,j;
    int g_satir,g_sutun,c_satir,c_sutun;

printf("Satir sayisini gir "); scanf("%d",&satir);
printf("sutun sayisini gir"); scanf("%d",&sutun);

srand(time(NULL));

for(i=0; i<satir; i++){
    for(j=0; j<sutun; j++){
      int x=rand()%2;
        ekle(x,satir,sutun);
    }
    printf("\n");
}


giris_eleman(satir,sutun);
cikis_eleman(satir,sutun);
labirent_coz(satir,sutun);

return 0;
}


