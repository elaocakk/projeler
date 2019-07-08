#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
    double lat[83];
    double long1[83];
    int plaka[83];
    int rakim[83];
    int i,j;
    double R=6.371;
    int rakimF[83];
    double egimAci[83];
    double a,c,latF,long1F;

    for(i=0;i<83;i++) {   // bu sýnýrlar sonradan komþuluklara göre deðiþecek
        for(j=0;j<83;j++) {
        rakimF[i]=rakim[i]-rakim[j];

        latF=lat[i]-lat[j];
        long1F=long1[i]-long1[j];

        a=pow(sin(latF/2),2) +
        cos(lat[i]) * cos(lat[j]) * pow(sin(long1F/2),2);

        c=2 * atan2(sqrt(a),sqrt(1-a));

        double distance=R * c;

        egimAci[i]=arctan(rakimF[i]/distance); // kütüphanesi eksik


    }
    }


    return 0;
}
