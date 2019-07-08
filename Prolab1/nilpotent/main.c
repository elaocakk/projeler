#include <stdio.h>
#include <stdlib.h>


void nilpotent()
{
   int d[200][200],d2[200][200],dsonuc[200][200]={0},i,j,k,n,x=0;

srand(time(NULL));
printf("kare matris boyutu:");
scanf("%d",&n);

for(i=0;i<n;i++) {
    for(j=0;j<n;j++)
    d[i][j]=-15+rand()%30; //-15 ile 15 arasi deger
}

    do {

        for(i=0;i<n;i++) {  //a^2 bulma islemi
           for(j=0;j<n;j++) {
            int top=0;
                for(k=0;k<n;k++) {
                    top+=d[i][k]*d[k][j];
         } dsonuc[i][j]=top;
    }
    }

  /*
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++)
        d2[i][j]=dsonuc[i][j];
        } */


} while (x<1000) {

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(dsonuc[i][j]!=0) {
                    x++;
                } else if(dsonuc[i][j]==0){
                    printf("matris nilpotent matristir\n");
                }
                }
            }
            }


            else {
                printf("matris nilpotent degildir\n");

            }
        son :
        return 0;
}
