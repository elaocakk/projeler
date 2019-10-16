
package pkg6ncıproje;
import java.io.IOException;
import java.util.Scanner;

public class HavaTasitlari extends Arac {
    void veriOluştur(int secim,java.io.File dosya) throws IOException{
        Scanner scan=new Scanner(System.in);
        if(secim==4){
                  System.out.println("Mevcut verileri kullanmak istiyor musunuz?\n1.Hayır\n2.evet ");
            int yanit=scan.nextInt();
            if (yanit==2)
            { Ucak u=new Ucak();
            
              System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma \n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
              switch (hızD) {
                  case 1: {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      u.hız=hızlanma(artırma,u.hız); break;
                  }
                  case 2: {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      u.hız=yavaşlama(azaltma,u.hız);  break;
                  }
                  case 3: {
                  int t=u.inis(u.hız);
                      if(t<=250) {
                System.out.println("Uçak iniş yapabilir."); 
                u.hız=t;
                durma(u.hız);
                     }   
                else {System.out.println("Uçak henüz iniş yapamaz."); }
                       break;
                  } 
                  default: break; }
              }      
         u.DosyaYaz(dosya);
        }   else {
                    System.out.print("marka:");          String m=scan.next(); 
                    System.out.print("hız:");            int h=scan.nextInt();
                    System.out.print("renk:");           String r=scan.next();
                    System.out.print("üretim yılı:");    int y=scan.nextInt();
                    System.out.print("fiyat:");          int f=scan.nextInt();
                    System.out.print("yolcu sayısı:");   int ys=scan.nextInt();
                    
                Ucak u=new Ucak(f,h,y,m,r,ys);
                
                  System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma \n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
                  if(hızD==1) {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      u.hız=hızlanma(artırma,u.hız);
                  }
                  else if(hızD==2) {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      u.hız=yavaşlama(azaltma,u.hız); 
                  }
                  else if(hızD==3) { 
                      int t=u.inis(u.hız);
                      if(t<=250) {
                System.out.println("Uçak iniş yapabilir."); 
                u.hız=t;
                durma(u.hız);
                     }   
                else {System.out.println("Uçak henüz iniş yapamaz."); }   
                  }   
              }
         u.DosyaYaz(dosya);
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

