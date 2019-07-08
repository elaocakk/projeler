package tictactoe;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.Math.sqrt;
import java.util.Scanner;
 
public class tictactoe {
   public static boolean first=false;
   public static boolean beraber=false;
   
    public static void main(String[] args) throws IOException, ClassNotFoundException {
     
        Scanner giris=new Scanner(System.in);
        int kayit,boyut,basla;
        String isim;
        String harf;
        String []kayitliD=new String [50];
        String kayitli = new String() ;
        char kayitliH=0 ;
        String []gecici = new String[50] ;
        char [][] son=new char[10][10];
       
        System.out.print("Kaydedilen oyuna devam etmek istiyor musunuz? (1:evet/0:hayır) :");
        kayit=giris.nextInt();
        
        if(kayit!=1) {
        
        System.out.print("Boyut giriniz: (3/5/7)");
        boyut=giris.nextInt();
        if(boyut!=3 && boyut!=5 && boyut!=7) { System.out.print("Yanlış boyut girdiniz!");  System.exit(0); } 
        System.out.print("İsminizi giriniz:");
        isim=giris.next();
        System.out.print("(bilgisayar:1) Kim başlayacak? :");
        basla=giris.nextInt();
//***//        
        if(basla!=1) {
          first=true;
          System.out.println("(1:evet) Harf seçmek istiyor musunuz?:");
          int secim=giris.nextInt();
          
          if(secim!=1){
              
            Oyuncu o1=new Oyuncu();
            o1.kullaniciAd=isim;
            OyunTahtasi g1=new OyunTahtasi();
            g1.oyunTahtasiniAl(boyut);
             
            while(first==true || first==false) 
            {  o1.oyuncununHamlesiniAl(first,boyut);
              while(g1.hamleyiYaz(o1.satir,o1.sutun,o1.harf)==false) { 
                  o1.oyuncununHamlesiniAl(first,boyut); }
              
              System.out.println("Hamle:"+g1.table[o1.satir][o1.sutun]);
              g1.oyunTahtasiniYazdir();
            
               g1.kazanan(first,o1.harf, g1.table) ;
              
               beraber=g1.beraberlikKontrol(g1.table);
               if(beraber==true) {System.out.println("Oyun Berabere!"); System.exit(0); }
                    
               //o1.bosMuKontrol(g1.table);
             
             if(first==true){
                System.out.println("(çıkış:1) Çıkmak istiyor musunuz? :");
                int cikis=giris.nextInt();
                if(cikis==1) {
                 System.out.println("(kayıt:1) Oyunu kaydetmek istiyor musunuz? :");
                 int k=giris.nextInt();
                 if(k==1) { 
                    DosyaYaz(o1.kullaniciAd,o1.harf,g1.table);
                    System.exit(0);
                }           } 
                            }
             
                first=o1.oyuncuTurunuAl(first);
              o1.harf=o1.karakteriAl(o1.harf);
                        }
} else if(secim==1)
          {   System.out.print("Harf seçin: (X/O)");
              harf=giris.next();
              char a = harf.charAt(0);
  
              Oyuncu o2=new Oyuncu(first,a);
              o2.kullaniciAd=isim;
             
              OyunTahtasi g2=new OyunTahtasi();
              g2.oyunTahtasiniAl(boyut);
             
            while(first==true || first==false)
          {  o2.oyuncununHamlesiniAl(first,boyut);
             while(g2.hamleyiYaz(o2.satir,o2.sutun,o2.harf)==false) { o2.oyuncununHamlesiniAl(first,boyut); }
              System.out.println("Hamle:"+g2.table[o2.satir][o2.sutun]);
              g2.oyunTahtasiniYazdir();
             
                g2.kazanan(first,o2.harf, g2.table) ;
               
               beraber=g2.beraberlikKontrol(g2.table);
               if(beraber==true) {System.out.println("Oyun Berabere!"); System.exit(0); }
            
              first=o2.oyuncuTurunuAl(first);
              o2.harf=o2.karakteriAl(o2.harf);
             
             o2.bosMuKontrol(g2.table);
             
             if(first==true){
                System.out.println("(çıkış:1) Çıkmak istiyor musunuz? :");
                int cikis=giris.nextInt();
                if(cikis==1) {
                    System.out.println("(kayıt:1) Oyunu kaydetmek istiyor musunuz? :");
                 int k=giris.nextInt();
                 if(k==1) { 
                    DosyaYaz(o2.kullaniciAd,o2.harf,g2.table);
                    
                    System.exit(0);
                }          }    }
             
                            }
          }
} else if(basla==1) /**bilgisayar oyuncu***/
      {   first=false;
          Oyuncu o3=new Oyuncu(first);
          o3.kullaniciAd=isim;
         
          OyunTahtasi g3=new OyunTahtasi();
            
            g3.oyunTahtasiniAl(boyut);
           
            while(first==true || first==false)
         {   o3.oyuncununHamlesiniAl(first,boyut);
              while(g3.hamleyiYaz(o3.satir,o3.sutun,o3.harf)==false) { o3.oyuncununHamlesiniAl(first,boyut); }
             
              System.out.println("Hamle:"+g3.table[o3.satir][o3.sutun]);
              g3.oyunTahtasiniYazdir();
             
               g3.kazanan(first,o3.harf, g3.table) ;
                  beraber=g3.beraberlikKontrol(g3.table);
               if(beraber==true) {System.out.println("Oyun Berabere!"); System.exit(0); }
            
              first=o3.oyuncuTurunuAl(first);
              o3.harf=o3.karakteriAl(o3.harf);
            
             o3.bosMuKontrol(g3.table);
             
              if(first==true){
                System.out.println("(çıkış:1) Çıkmak istiyor musunuz? :");
                int cikis=giris.nextInt();
                if(cikis==1) {
                 System.out.println("(kayıt:1) Oyunu kaydetmek istiyor musunuz? :");
                 int k=giris.nextInt();
                 if(k==1) { 
                    DosyaYaz(o3.kullaniciAd,o3.harf,g3.table);
                    System.exit(0);
                }           }     }
                           }
}
}  else if(kayit==1){   /************************************************/      
        kayitliD=DosyaOku(); 
        int j=0;
            for (int i = 0; kayitliD[i]!=null; i++) {
                if(i==0) {
                    kayitli=kayitliD[i];
                } else if(i==1) {
                    kayitliH=kayitliD[i].charAt(0);
                } else {
                    gecici[j]=kayitliD[i];
                    j++;
                }
            } 
            int i=0,k=0;
        while(gecici[i]!=null) {k++; i++;}
        int boyut2=(int) sqrt(k);
            
        k=0;
            for ( i = 0; i < boyut2; i++) {
             for ( j = 0; j < boyut2; j++) {
                son[i][j]=gecici[k].charAt(0);
                if(son[i][j]=='-') {son[i][j]=' ';}
                k++;
                System.out.print(" "+son[i][j]);
            } System.out.println();
           }  
        
        System.out.print("(bilgisayar:1) Kim başlayacak?:");
        basla=giris.nextInt();
/****/  if(basla!=1) {
           first=true;
          } else {
          first=false;
            }

          Oyuncu o=new Oyuncu();
          o.kullaniciAd=kayitli;
          o.harf=kayitliH;
         
          OyunTahtasi g=new OyunTahtasi(son,boyut2);
          g.oyunTahtasiniAl(g.table,boyut2);
          
             for (int l = 0; l < boyut2; l++) {
                for (int m = 0; m < boyut2; m++) {
                    System.out.print(" "+g.table[l][m]);
                }
                System.out.println();
            }
           
            while(first==true || first==false)
         {   o.oyuncununHamlesiniAl(first,boyut2);
              while(g.hamleyiYaz(o.satir,o.sutun,o.harf)==false) { o.oyuncununHamlesiniAl(first,boyut2); }
             
              System.out.println("Hamle:"+g.table[o.satir][o.sutun]);
              g.oyunTahtasiniYazdir();
             
               g.kazanan(first,o.harf, g.table) ;
                beraber=g.beraberlikKontrol(g.table);
               if(beraber==true) {System.out.println("Oyun Berabere!"); System.exit(0); }
            
              first=o.oyuncuTurunuAl(first);
              o.harf=o.karakteriAl(o.harf);
            
             //o.bosMuKontrol(g.table);
             
              if(first==true){
                System.out.println("(çıkış:1) Çıkmak istiyor musunuz?");
                int cikis=giris.nextInt();
                if(cikis==1) {
                  System.out.println("(kayıt:1) Oyunu kaydetmek istiyor musunuz? :");
                 int kay=giris.nextInt();
                 if(kay==1) { 
                    DosyaYaz(o.kullaniciAd,o.harf,g.table);
                    System.exit(0);
                }     }    }      
         }  
}  
    }        
          
    private  static String[] DosyaOku() throws FileNotFoundException, IOException  {
         FileReader fileReader = new FileReader("oyun.txt");
         BufferedReader oku = new BufferedReader(fileReader);
         
        String yazi=oku.readLine();
        char d;
       
        String []dizi=new String[50];
        int i=0,j=0;
            while (yazi!=null) {
               dizi[i]=yazi;
                yazi = oku.readLine(); 
                i++; 
            }
            
    oku.close();
    return dizi;
    }
 
     private static void DosyaYaz(String isim,char harf,char [][]dizi) {
            try{
                  File dosya = new File("oyun.txt");
                  FileWriter yazici = new FileWriter(dosya);
                  PrintWriter yaz = new PrintWriter(yazici);
                  yaz.println(isim);
                  yaz.println(harf);
                  
                  for (int i = 0; i < dizi.length; i++) {
                      for (int j = 0; j < dizi.length; j++) {
                          if(dizi[i][j]!='x' && dizi[i][j]!='o' ) {
                              dizi[i][j]='-';
                          }
                          yaz.println(dizi[i][j]);
                   }        }                  
                  yaz.close();
                  System.out.println("Yazma İşlemi Başarılı");
            }
            catch(Exception hata){
                  hata.printStackTrace();
            }  
          
      }
          
     
}