package prolab_örnek;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Prolab_örnek {
    double l;
    double lg;
    int r;
    int pk;
    
    public static void main(String[] args) throws IOException {
        
        File file = new File("latlong2.txt");
        BufferedReader reader = null;
        
        String dizi[]=new String [82];
        Prolab_örnek d[]=new Prolab_örnek [82];
        
        String lat[]=new String [82];
        String long1[]=new String [82];
        String plakaKodu[]=new String [82];
        String rakim[]=new String [82];
        
     /*   double lat2[]=new double  [82];
        double long2[]=new double  [82];
        double plakaKodu2[]=new double  [82];
        double rakim2[]=new double  [82];
        
        String kelime[]=null;  */
        
        reader = new BufferedReader(new FileReader(file));
        
        String satir = reader.readLine();
        
        int i=0;
            while (satir!=null && i<82 ) {
              // System.out.println(satir);
                satir = reader.readLine();
                dizi[i]=satir;
              
               if(i<9) {
                lat[i]=dizi[i].substring(0,7);
                long1[i]=dizi[i].substring(8,15);
                plakaKodu[i]=dizi[i].substring(16,17);
                rakim[i]=dizi[i].substring(18);
               } else {
                lat[i]=dizi[i].substring(0,7);
                long1[i]=dizi[i].substring(8,15);
                plakaKodu[i]=dizi[i].substring(16,18);
                rakim[i]=dizi[i].substring(19);
               }
                 
                d[i].l=Double.parseDouble(lat[i]); // string double a cevriliyor
                d[i].lg=Double.parseDouble(long1[i]);
                d[i].pk=Integer.parseInt(plakaKodu[i]);
                d[i].r=Integer.parseInt(rakim[i]);
                
                System.out.print(d[i].l+"-");
                System.out.print(d[i].lg+"-");
                System.out.print(d[i].pk+"-");
                System.out.println(d[i].r);
                //System.out.println(dizi[i]);
                i++;
                           }
            
       /*     while ( i>8 && i<81) {
                satir = reader.readLine();
                dizi[i]=satir;
         //       System.out.println(i+"  "+satir);
             lat[i]=dizi[i].substring(0,7);
              lat2[i] = Double.parseDouble(lat[i]);
             long1[i]=dizi[i].substring(8,15);
              long2[i] = Double.parseDouble(long1[i]);
             plakaKodu[i]=dizi[i].substring(16,18);
               plakaKodu2[i] = Double.parseDouble(plakaKodu[i]);
             rakim[i]=dizi[i].substring(19);
              rakim2[i] = Double.parseDouble(rakim[i]);
                i++;
            }   */ 
       
     int yolcuSay, ucret;
     double kar,egim;
     
     Scanner scan=new Scanner(System.in);
     System.out.print("Yolcu Sayısını Giriniz: ");
     yolcuSay=scan.nextInt();
      
       if(yolcuSay<5 || yolcuSay>50){
           System.out.println("Eksik veya Fazla Yolcu Girdiniz!");
           System.exit(0);
       }

      egim=80-yolcuSay;
       int j=0,k=0;
       
       double yeniEgim[]=new double[1000];
       double rakimFark[]=new double[1000];
       double latF[]=new double[1000];
       double longF[]=new double[1000];
       double distance,a,c,R=6371;
      
        File file2 = new File("komsuluk.txt");
        BufferedReader reader2 = null;
        String dizi2[]=new String [82];
        
        reader2 = new BufferedReader(new FileReader(file2));
        
        String satir2 = reader2.readLine();
        
        i=0;
        while (satir2!=null && i<82 ) {
        // System.out.println(satir);
            satir2 = reader2.readLine();
            dizi[i]=satir2;
        }
        
       
    for(i=0; i<82; i++){
        for(j=0; j<82; j++){  
            rakimFark[k]=rakim2[j]-rakim2[i]; 
        /***      HAVERSINE     ***/
        latF[k]=lat2[j]-lat2[i];
        longF[k]=long2[j]-long2[i];
        
        a=Math.sin(latF[k]/2)*Math.sin(latF[k]/2) + Math.cos(lat2[j])*Math.cos(lat2[i])*Math.sin(longF[k]/2)*Math.sin(longF[k]/2);
        
        c=2*Math.atan2(Math.sqrt(a),Math.sqrt(1-a));
        
        distance=R*c;
        
        yeniEgim[k]=Math.atan(rakimFark[k]/distance);
        //  System.out.println(yeniEgim[k]
        k++; 
    }
}
      /* for (int l = 0; l < 81; l++) {
            System.out.println(rakim2[l]);
            
        }*/
   
            
            
            
            
            
            
            
            
            
        }
    
}

    
