
package pkg6ncıproje;

import java.io.IOException;
import java.util.Scanner;

public class DenizTasitlari extends Arac {
    
    void veriOluştur(int secim,java.io.File dosya) throws IOException{
        Scanner scan=new Scanner(System.in);
        if(secim==3){
             System.out.println("Mevcut verileri kullanmak istiyor musunuz?\n1.Hayır\n2.evet ");
            int yanit=scan.nextInt();
            if (yanit==2)
          { Gemi g=new Gemi(); 
            
            System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma \n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
              switch (hızD) {
                  case 1: {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      g.hız=hızlanma(artırma,g.hız); break;
                  }
                  case 2: {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      g.hız=yavaşlama(azaltma,g.hız);  break;
                  }
                  case 3: {
                      g.hız=durma(g.hız);   break;
                  } 
                  default: break; }
              }
           g.DosyaYaz(dosya);
          }  else {
                    System.out.print("marka:");          String m=scan.next(); 
                    System.out.print("hız:");            int h=scan.nextInt();
                    System.out.print("renk:");           String r=scan.next();
                    System.out.print("üretim yılı:");    int üy=scan.nextInt();
                    System.out.print("fiyat:");          int f=scan.nextInt();
                    System.out.print("yolcu sayısı:");   int ys=scan.nextInt();
                    
                Gemi g=new Gemi(f,h,üy,m,r,ys);
                
              System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma \n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
              switch (hızD) {
                  case 1: {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      g.hız=hızlanma(artırma,g.hız); break;
                  }
                  case 2: {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      g.hız=yavaşlama(azaltma,g.hız);  break;
                  }
                  case 3: {
                      g.hız=durma(g.hız);   break;
                  } 
                  default: break; }
              }
         g.DosyaYaz(dosya);
            }
        }
        else if(secim==5){
             System.out.println("Mevcut verileri kullanmak istiyor musunuz?\n1.Hayır\n2.evet ");
            int yanit=scan.nextInt();
            if (yanit==2)
            {
              UcanGemi ug=new UcanGemi();
              System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma \n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
                  if(hızD==1) {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      ug.hız=hızlanma(artırma,ug.hız);
                  }
                  else if(hızD==2) {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      ug.hız=yavaşlama(azaltma,ug.hız); 
                  }
                  else if(hızD==3) { 
                      int t=ug.inis(ug.hız);
                      if(t<=250) {
                System.out.println("Uçan gemi iniş yapabilir."); 
                ug.hız=t;
                durma(ug.hız);
                     }   
                else {System.out.println("Uçan gemi henüz iniş yapamaz."); }       
                  }    
              } 
         ug.DosyaYaz(dosya);}
            else {
                    System.out.print("marka:");          String m=scan.next(); 
                    System.out.print("hız:");            int h=scan.nextInt();
                    System.out.print("renk:");           String r=scan.next();
                    System.out.print("üretim yılı:");    int y=scan.nextInt();
                    System.out.print("fiyat:");          int f=scan.nextInt();
                    System.out.print("yolcu sayısı:");   int ys=scan.nextInt();
                    
                UcanGemi ug=new UcanGemi(f,h,y,m,r,ys);
                
                  System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma \n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
                  if(hızD==1) {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      ug.hız=hızlanma(artırma,ug.hız);
                  }
                  else if(hızD==2) {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      ug.hız=yavaşlama(azaltma,ug.hız); 
                  }
                  else if(hızD==3) { 
                      int t=ug.inis(ug.hız);
                      if(t<=250) {
                System.out.println("Uçan gemi iniş yapabilir."); 
                ug.hız=t;
                durma(ug.hız);
                     }   
                else {System.out.println("Uçan gemi henüz iniş yapamaz."); }       
                  } 
              }
      ug.DosyaYaz(dosya);
            }
        }
    }
    int hızlanma(int a,int b) {
        b=b+a;
        return b;
    }
    int yavaşlama(int a,int b) {
        b=b-a;
        return b;
    }
     int durma (int b) {
         b=0;
        System.out.println("\nDurdu. Hız: "+b);
        return b;
    } 
}