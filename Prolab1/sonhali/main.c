#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int cark();
int detAl(int mBoyut,int matris[mBoyut][mBoyut]);
void schur(int mBoyut, int matris[mBoyut][mBoyut]) ;
float *ozdegerbul(int mBoyut, int matris[mBoyut][mBoyut]);
int **matrOlustur(int n );


/* ### MATRİS OLUSTURMA ### */
int **matrOlustur(int n) { //boyut disaridan aliniyor
    int i,j;
    int **matris;

    matris=(int**)malloc(n*sizeof(int*)); //ilk boyut icin alan ayirma
    i=0;
    while(i<n) {
        matris[i]=malloc(n*sizeof(int)); //ikinci boyut icin alan ayirma
        i++;
    }

    printf("Matris Elemanlarini Girin:\n");

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("[%d][%d]. eleman:",i,j);
            scanf("%d",&matris[i][j]);
        } printf("\n");
    }

    return matris;
}

int main()
{
    int donmeSay,donmeSonuc;
    printf("Cark kac kez donecek : ");
    scanf("%d",&donmeSay);

    donmeSonuc=cark(donmeSay);

    donmeSonuc=0;

    printf("Carkin Yapacagi Islemler:\n1.Ozdeger Bulmak\n2.Schur Teoremi\n3.Ozvektor Bulmak\n4.Nilpotent\n\n");

     if (donmeSonuc%4==0) {
        printf("Isleminiz Oz Deger Bulmak\n");

        int mBoyut;
        printf("Matrisin Boyutunu Girin:");
        scanf("%d",&mBoyut);

        int **matris;
        matris=matrOlustur(mBoyut);

        ozdegerbul(mBoyut,matris);

        }
        else if (donmeSonuc%4==1)
        { printf("Isleminiz schur\n");

        int mBoyut;
        printf("Matrisin Boyutunu Girin:");
        scanf("%d",&mBoyut);

        int **matris;
        matris=matrOlustur(mBoyut);

        schur(mBoyut,matris);
        }

}
/*     ###### SCHUR İSLEMİ ######  */
    void schur(int mBoyut, int matris)
{
    // int mBoyut;
    int i=0;
    int j;
    float ozDegKareTop=0.0;

    for(i=0;i<mBoyut;i++) {
        for(j=0;j<mBoyut;j++)
            printf("%d",matris[i][j]);
        printf("\n");
    }

  /*  printf("Matrisin Boyutunu Girin:");
    scanf("%d",&mBoyut);

    int **matris;
    matris=matrOlustur(mBoyut); */

    float *koklericin=ozdegerbul(mBoyut,matris);
    float *schurkok=koklericin;

    /* while(i<mBoyut) {
         schurkok[i]=*(koklericin+i);
         i++;
            } */

    //kokleri bir kere daha yazdiriyor
    while(i<mBoyut) {
         printf("%d.ozdeger = %f\n",i+1,schurkok[i]);
         i++;  }

    printf("\nSchur Teoremi:\n");

    while(i<mBoyut) {
        ozDegKareTop+=pow(schurkok[i],2);
        i++;
    }

    float elemanKareTop=0.0;

    for(i=0;i<mBoyut;i++){
        for(j=0;j<mBoyut;j++){
            elemanKareTop+=(matris[i][j]*matris[i][j]);
        }
    }

    printf("Sinir degerleri\n");
    printf("%f < %f",(ozDegKareTop),(elemanKareTop));
}

/* ##### ÇARK İSLEMİ ##### */
  int cark(int donmedegeri)
{
    srand(time(NULL));
    int degerBul,i=0;

    for( i=0; i<donmedegeri; i++)
    {   degerBul=rand()%241;
        printf("%d\n",degerBul);
    }

    return degerBul;
}


/* ##### DET ALMA İSLEMİ ##### */
int detAl(int mBoyut,int matris[mBoyut][mBoyut])
{
    int i,j,det;

    if (mBoyut==2) {

        det=matris[1][1]*matris[0][0]-matris[0][1]*matris[1][0];
    }
    else if (mBoyut==3) {
        det=(matris[0][0]*matris[1][1]*matris[2][2]+matris[0][1]*matris[1][2]*matris[2][0]+matris[0][2]*matris[1][0]*matris[2][1] )-
        (matris[0][2]*matris[1][1]*matris[2][0]+matris[0][1]*matris[1][0]*matris[2][2]+matris[0][0]*matris[1][2]*matris[2][1]);
    }


// 4. DERECEDENY YNTERNETTEN AL

    return det;
}


/* ##### OZDEGER BULMA ##### */
   float *ozdegerbul(int mBoyut,int matris)
{   int i,j;

 /*   printf("Matrisin Boyutunu Girin:");
    scanf("%d",&mBoyut);

    int **matris;
    matris=matrOlustur(mBoyut); */


/*    int skaretop=0;
    for(i=0;i<mBoyut;i++){
        for(j=0;j<mBoyut;j++){
            skaretop+= pow(matris[i][j],2);
        }
    return skaretop;
*/

    if(mBoyut==2)//Ikilik Matrisin Ozdegerleri Baslangici
    {
        int a=1,b,c;
        c=detAl(mBoyut,matris);

        if(matris[0][0]>0 && matris[1][1]>0) //Iki elemanin da pozitif olma durumu
        {
               b=-(matris[0][0]+matris[1][1]);
        }
        else if(matris[0][0]<0 && matris[1][1]<0) //Iki elemanin da negatif olma durumu
        {
               b=-(matris[0][0]+matris[1][1]);
        }
        else if (matris[0][0]<0 && matris[1][1]>0 && -matris[0][0]>matris[1][1]) //Negatif olan elemanin buyuk olma durumu
        {
               b=matris[0][0]+matris[1][1];
        }
        else if (matris[0][0]<0 && matris[1][1]>0 && -matris[0][0]<matris[1][1]) //Negatif olan elemanin kucuk olma durumu
        {
              b=-(matris[0][0]+matris[1][1]);
        }
        else if (matris[0][0]>0 && matris[1][1]<0 && matris[0][0]<-matris[1][1])
        {
              b=-(matris[0][0]+matris[1][1]);
        }
        else if (matris[0][0]>0 && matris[1][1]<0 && matris[0][0]>-matris[1][1])
        {
              b=matris[0][0]+matris[1][1];
        }

    for(i=0; i<mBoyut; i++) {
        for(j=0; j<mBoyut; j++) {
            printf("%d ",matris[i][j]);
        }   printf("\n");
    }

    printf("\nDeterminant Denklemi: x^2 + (%d)x + (%d)",b,c);

        int D; // diskriminant
        D = b*b- 4*a*c;

        if(D<0) {
            printf("\n\nDenklemin Reel Koku Yoktur\n");
            return 0;
        }
        else if (D>0) {
            float DKok= sqrt(D);
            float *ozDegeri = malloc(2*sizeof(float));

            ozDegeri[0]=(-b-DKok)/2*a;
            ozDegeri[1]=(-b+DKok)/2*a;

            for(i=0; i<2; i++) {
                printf("\n%d. Oz Deger=%.2f",i+1,ozDegeri[i]);
            }
            return ozDegeri;
        }
        else if(D==0) {
            float DKok = sqrt(D);
            float *ozDegeri=malloc(sizeof(float));

            ozDegeri[0]=(-b-DKok)/2*a;

            printf("Oz Degeri = %f",ozDegeri[0]);
            return ozDegeri;
        }
    }

     if(mBoyut==3){
        int toplam1=0, toplam2=0, carpim1[3][3], i,j,k;

        for( i=0;i<mBoyut;i++){  //matrisin karesi alinir
            for(j=0; j<mBoyut; j++){
                toplam1=0;
                for(k=0; k<mBoyut; k++){
                toplam1=toplam1+matris[i][k]*matris[k][j];
                }
                carpim1[i][j]=toplam1;
                printf("%3d",carpim1[i][j]);
            }
            printf("\n");
    }

       for(i=0; i<mBoyut; i++){  //c icin kare matrisin kosegenleri toplanir
           for(j=0; j<mBoyut; j++){
              if(i==j)
                {
                toplam2=toplam2+carpim1[i][j];
                }
        }
    }

     int a = -1;
     int b=(matris[0][0]+matris[1][1]+matris[2][2]);
     int c=(toplam2-pow(b,2))/2;
     int d=detAl(3,matris);

     int x1, x2, x3, delta, q, r, s, t;

    printf("\nDeterminant Denklemi: %dx^3+%dx^2+%dx+%d ",a,b,c,d);

 q=(double)(((3*a*c)-(b*b))/(9*a*a)); // bu kismi degistir
 r=(double)(((9*a*b*c)-(27*a*a*d)-(2*b*b*b))/(54*a*a*a));
 s=(double)(pow((r+pow((q*q*q)+(r*r),1/2)),1/3));
 t=(double) (pow((r-pow((q*q*q)+(r*r),1/2)),1/3));
 x1=(double)((s+t)-(b/(3*a)));
 x2=(double)((-(s+t)/2)-(b/3*a)+((pow(-1,1/2)*pow(3,1/2))*(s-t))/2);
 x3=(double)((-(s+t)/2)-(b/3*a)-((pow(-1,1/2)*pow(3,1/2))*(s-t))/2);
 delta=(double)((pow(c,2)*pow(b,2))-(4*d*pow(b,3))-(4*a*pow(c,3))+(18*d*c*b*a)-(27*pow(d,2)*pow(a,2)));

if (delta<0)
 {
 printf("\n (delta<0) kok yok.");
 }
 else
 {
  float *ozDegeri = malloc(3*sizeof(float));
                    ozDegeri[0]=s+t-b/3*a;
                    ozDegeri[1]=((-(s+t)/2)-(b/3*a))+(((pow(-1,1/2)*pow(3,1/2))*(s-t))/2);
                    ozDegeri[2]=((-(s+t)/2)-(b/3*a))-(((pow(-1,1/2)*pow(3,1/2))*(s-t))/2);
                     for( i=0;i<3;i++){

                printf(" \n%lf", *(ozDegeri+i));
                    return ozDegeri;

 }
 }

} }




