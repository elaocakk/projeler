package prolab;
import java.util.Scanner;
import java.io.IOException;
public class KaraTasitlari extends Arac {
    
    void veriOluştur (int secim,java.io.File dosya) throws IOException {
        Scanner scan=new Scanner(System.in);
        if(secim==1){
            
            System.out.println("Mevcut verileri kullanmak istiyor musunuz?\n1.Hayır\n2.evet ");
            int yanit=scan.nextInt();
            if (yanit==2)
            { Otomobil o=new Otomobil(); 
               
              System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma \n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
              switch (hızD) {
                  case 1: {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      o.hız=hızlanma(artırma,o.hız); break;
                  }
                  case 2: {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      o.hız=yavaşlama(azaltma,o.hız);  break;
                  }
                  case 3: {
                      o.hız=durma(o.hız);   break;
                  } 
                  default: break; }
              }
            o.DosyaYaz(dosya);
            }
            else {
                    System.out.print("marka:");     String m=scan.next(); 
                    System.out.print("hız:");       int h=scan.nextInt();
                    System.out.print("renk:");      String r=scan.next();
                    System.out.print("üretim yılı:");  int y=scan.nextInt();
                    System.out.print("fiyat:");   int f=scan.nextInt();
                    System.out.print("yakıt türü:");   String yt=scan.next();
                    
                Otomobil o=new Otomobil(f,h,y,m,r,yt);
                
              System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma \n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
              switch (hızD) {
                  case 1: {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      o.hız=hızlanma(artırma,o.hız); break;
                  }
                  case 2: {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      o.hız=yavaşlama(azaltma,o.hız);  break;
                  }
                  case 3: {
                      o.hız=durma(o.hız);   break;
                  } 
                  default: break;  }
              } 
            o.DosyaYaz(dosya); 
            }
        }
        else if(secim==2){
              System.out.println("Mevcut verileri kullanmak istiyor musunuz?\n1.Hayır\n2.evet ");
            int yanit=scan.nextInt();
            if (yanit==2)
            { Bisiklet b=new Bisiklet();
            
            System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma\n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
              switch (hızD) {
                  case 1: {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      b.hız=hızlanma(artırma,b.hız); break;
                  }
                  case 2: {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      b.hız=yavaşlama(azaltma,b.hız);  break;
                  }
                  case 3: {
                      b.hız=durma(b.hız);   break;
                  } 
                  default: break;       }
              }    
           b.DosyaYaz(dosya); 
            }  else {
                    System.out.print("marka:");     String m=scan.next(); 
                    System.out.print("hız:");       int h=scan.nextInt();
                    System.out.print("renk:");      String r=scan.next();
                    System.out.print("üretim yılı:");  int y=scan.nextInt();
                    System.out.print("fiyat:");   int f=scan.nextInt();
                    
                Bisiklet b=new Bisiklet(f,h,y,m,r);
                
                System.out.println("Hızın değerini değiştirmek için:1");
              int a=scan.nextInt();
              if(a==1){  
              System.out.println("1.Hızı artırma\n2.Hızı azaltma\n3.Durdurma ");
              int hızD=scan.nextInt();
              switch (hızD) {
                  case 1: {
                      System.out.println("Ne kadar hızı artırılsın?");
                      int artırma=scan.nextInt();
                      b.hız=hızlanma(artırma,b.hız); break;
                  }
                  case 2: {
                      System.out.println("Ne kadar hızı azaltılsın?");
                      int azaltma=scan.nextInt();
                      b.hız=yavaşlama(azaltma,b.hız);  break;
                  }
                  case 3: {
                      b.hız=durma(b.hız);   break;
                  } 
                  default: break;  }
              }
         b.DosyaYaz(dosya);
            }   }      
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