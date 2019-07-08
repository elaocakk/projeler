#include<stdio.h>
#include<conio.h>
int s[3],i,j;
float anj[3],m[3][3],d1[3][3],d2[3][3],d3[3][3];
float dk0,dk1,dk2,dk3;

katsayiiste3(){

              for(i=0;i<3;i++){
                               printf("%d. denklem katsayilari giriniz\n",i);
                       for(j=0;j<3;j++){
                                        printf("d[%d][%d]=",i,j);
                                        scanf("%f",&m[i][j]);

                                        }
                        printf(" \n");
                       }

              }






float determinant3(float d[3][3] , float det){
anj[0]=((d[1][1]*d[2][2])-(d[1][2]*d[2][1]));
anj[1]=((d[1][2]*d[2][0])-(d[1][0]*d[2][2]));
anj[2]=((d[1][0]*d[2][1])-(d[1][1]*d[2][0]));
det=anj[0]*d[0][0]+anj[1]*d[0][1]+anj[2]*d[0][2];
return det;
}



sonucal(){
              for(j=0;j<3;j++)         {
                                        printf("d[%d]=",j);
                                        scanf("%d",&s[j]);

                                        }

}

float D1()
{
d1[0][0]=s[0]; d1[1][0]=s[1]; d1[2][0]=s[2];
d1[0][1]=m[0][1]; d1[1][1]=m[1][1]; d1[2][1]=m[2][1];
d1[0][2]=m[0][2]; d1[1][2]=m[1][2]; d1[2][2]=m[2][2];
}
float D2()
{
d2[0][0]=m[0][0]; d2[1][0]=m[1][0]; d2[2][0]=m[2][0];
d2[0][1]=s[0]; d2[1][1]=s[1]; d2[2][1]=s[2];
d2[0][2]=m[0][2]; d2[1][2]=m[1][2]; d2[2][2]=m[2][2];
}
float D3()
{
d3[0][0]=m[0][0]; d3[1][0]=m[1][0]; d3[2][0]=m[2][0];
d3[0][1]=m[0][1]; d3[1][1]=m[1][1]; d3[2][1]=m[2][1];
d3[0][2]=s[0]; d3[1][2]=s[1]; d3[2][2]=s[2];
}
float matris_yaz(float y[3][3])
      {
      for(i=0;i<3;i++){
                       for(j=0;j<3;j++){
                                        printf("%f",y[i][j]);
                                        }
                        printf(" \n");
                        }
      }


main(){
printf("3 bilinmeyenli 3 denlem cozumu(cramer metodu)");

katsayiiste3();
dk0=determinant3(m,dk0);
if (dk0==0){printf("Katsayilar determinanti sifir\nBu denklem cramer metodu ile cozulemez."); goto son;}

printf("\ndeterminat=%f\n",dk0);
printf("Sirasi ile denkelemlerin sonuclarýný giriniz.\n");
sonucal(); // sonuc dizisi
D1(); // D1 olultur
printf("D1 matrisinin elemanlari\n");
matris_yaz(d1);

printf(" \n");D2();
printf("D2 matrisinin elemanlari\n");
matris_yaz(d2);

printf(" \n");D3();
printf("D3 matrisinin elemanlari\n");
matris_yaz(d3);

dk1=determinant3(d1,dk1);
dk2=determinant3(d2,dk2);
dk3=determinant3(d3,dk3);
printf("\ndeterminat1=%f determinat2=%f determinat3=%f\n",dk1,dk2,dk3);

printf("X1=%f\n",dk1/dk0);
printf("X2=%f\n",dk2/dk0);
printf("X3=%f\n",dk3/dk0);
son:

return 0,
}
