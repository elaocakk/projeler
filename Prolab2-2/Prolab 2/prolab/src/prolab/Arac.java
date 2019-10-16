package prolab;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Arac implements AracYonetimi{
    
    String marka;
    String yakıtTürü;
    int hız;
    int yolcuSayısı;
    int tekerlekSayısı;
    int fiyat;
    int üretimYılı;
    String renk;
 
    ///***************override
    public void veriGirisi(File dosya) {
    Scanner giris=new Scanner(System.in);
    
    System.out.println("Veri girişinde bulunacağınız aracı seçiniz:");
    System.out.println("1.Otomobil \n2.Bisiklet \n3.Gemi \n4.Ucak \n5.UcanGemi");
    System.out.println("6.Bir önceki menüye geri dön");
    System.out.println("Çıkış");
    int secim2=giris.nextInt();
  switch (secim2) {
       case 1: { 
          try {
            KaraTasitlari kara=new KaraTasitlari();
            kara.veriOluştur(secim2,dosya);
            menu(dosya); }
          catch (IOException ex) {
            Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
        } break;
        }
       case 2: {
          try {
            KaraTasitlari kara=new KaraTasitlari();
            kara.veriOluştur(secim2,dosya);
            menu(dosya);     }
          catch (IOException ex) {
            Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
        } break;
        }
        case 3: {
          try { 
            DenizTasitlari deniz=new DenizTasitlari();
            deniz.veriOluştur(secim2,dosya);
            menu(dosya);  } 
          catch (IOException ex) {
            Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
        }
            break;
        }
        case 4: {
          try { 
            HavaTasitlari hava=new HavaTasitlari();
            hava.veriOluştur(secim2,dosya);
            menu(dosya);}
          catch (IOException ex) {
            Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
        } 
          break;
        }
        case 5: {
           try { 
            DenizTasitlari deniz=new DenizTasitlari();
            deniz.veriOluştur(secim2,dosya);
            menu(dosya);} 
           catch (IOException ex) {
            Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
        }
            break;
        }
        case 6: menu(dosya);      break;
        default : System.exit(0); break;
    }
    
    }    
    /////****************************************
    @Override
    public void veriListeleme(File dosya) {
        Scanner liste=new Scanner(System.in);
        System.out.println("Listelemek İstediğiniz Veri Tipini Seçiniz\n");
        System.out.println("1.Kara Taşıtları\n2.Deniz Taşıtları\n3.Hava Taşıtları");
        System.out.println("Bir Önceki Menüye Dön\n Çıkış");
       int vL=liste.nextInt();
       
        switch (vL) {
            case 1: {   
                try {
                  DosyaOku(dosya,vL); } 
                catch (FileNotFoundException ex) {
                 Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex); } 
                catch (IOException ex) {
                Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
                    }
                break;  }
            case 2: {
                try {
                 DosyaOku(dosya,vL); }
                catch (FileNotFoundException ex) {
                Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex); }  
                catch (IOException ex) {
                Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
                    }
                break;
                    }
            case 3: { 
                try {
                DosyaOku(dosya,vL); } 
                catch (FileNotFoundException ex) {
                Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex); }   
                catch (IOException ex) {
                Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
                    }
                break;      
                    } 
            case 4:  menu(dosya);     break; 
            default: System.exit(0);  break;      
        }  
    }
    
    ///******************************************************
public void veriGüncelleme(File dosya)  {
  Scanner güncelle=new Scanner(System.in); 
  String str,hızz = null,ID,fiyatt = null,markaa = null,renkk = null,tekerlekSayısıı = null,yakıtTürüü= null,yolcuSayısıı= null,üretimYılıı= null;
 // int hızF;
        System.out.println("Güncellemek istediğiniz ID yi giriniz: ");
        String newID=güncelle.next();
       // String newContent = null;
           System.out.println("Verinin hangi özelliği değiştirilecek?");
           System.out.println("1.Fiyat\n2.Hız\n3.Marka\n4.Renk");
           System.out.println("5.Tekerlek sayısı\n6.Yolcu sayısı\n7.Yakıt türü\n8.Üretim yılı");
          
           String a=null;
           int secim=güncelle.nextInt();
           switch(secim) {
               case 1: System.out.println("Yeni fiyat girin:"); a=güncelle.next();
                          break;
               case 2: System.out.println("Yeni hız girin:"); a=güncelle.next();
                          break;
               case 3:   System.out.println("Yeni marka girin:"); a=güncelle.next();
                          break;
               case 4: System.out.println("Yeni renk girin:");  a=güncelle.next();
                          break;
               case 5: System.out.println("Yeni tekerlek sayısı girin:"); a=güncelle.next();
                          break;
               case 6: System.out.println("Yeni yolcu sayısı girin:");  a=güncelle.next();
                          break;
               case 7: System.out.println("Yeni yakıt türü girin:");  a=güncelle.next();
                          break;
               case 8: System.out.println("Yeni üretim yılını girin:"); a=güncelle.next();
                          break;        
           }     
  File fileToBeModified = new File("aracKayit.txt");
   String oldContent = "";
  BufferedReader reader = null;
  FileWriter writer = null;
   Scanner read;
   String c=null;
        try {
            read = new Scanner (dosya); read.useDelimiter(",");
         try
        { reader = new BufferedReader(new FileReader(fileToBeModified));  
       
      while(read.hasNextLine())    
{   
     ID=read.next(); 
    if(ID.equals(newID)){
        if (secim==1) { 
                            hızz = read.next(); 
                            fiyatt = "ww"+read.next(); c=fiyatt;  
                            markaa = read.next();
                            renkk = read.next(); 
                            tekerlekSayısıı = read.next(); 
                            yakıtTürüü = read.next();
                            yolcuSayısıı = read.next(); 
                            üretimYılıı = read.next();                  
                         }
        else if(secim==2){  hızz = "ww"+read.next();  c=hızz; 
                            fiyatt = read.next(); 
                            markaa = read.next();
                            renkk = read.next(); 
                            tekerlekSayısıı = read.next(); 
                            yakıtTürüü = read.next();
                            yolcuSayısıı = read.next(); 
                            üretimYılıı = read.next();}
        else if(secim==3) { hızz = read.next(); 
                            fiyatt = read.next(); 
                            markaa ="ww"+ read.next(); c=markaa;
                            renkk = read.next(); 
                            tekerlekSayısıı = read.next(); 
                            yakıtTürüü = read.next();
                            yolcuSayısıı = read.next(); 
                            üretimYılıı = read.next();}
        else if(secim==4) { 
                            hızz = read.next(); 
                            fiyatt = read.next(); 
                            markaa = read.next();
                            renkk="ww"+read.next(); c=renkk;
                            tekerlekSayısıı = read.next(); 
                            yakıtTürüü = read.next();
                            yolcuSayısıı = read.next(); 
                            üretimYılıı = read.next();}
        else if(secim==5) { 
                            hızz = read.next(); 
                            fiyatt = read.next(); 
                            markaa = read.next();
                            renkk = read.next(); 
                            tekerlekSayısıı="ww"+read.next(); c=tekerlekSayısıı;
                            yakıtTürüü = read.next();
                            yolcuSayısıı = read.next(); 
                            üretimYılıı = read.next();}
        else if(secim==6) { 
                            hızz = read.next(); 
                            fiyatt = read.next(); 
                            markaa = read.next();
                            renkk = read.next(); 
                            tekerlekSayısıı = read.next(); 
                            yakıtTürüü = read.next();
                            yolcuSayısıı="ww"+read.next();  c=yolcuSayısıı;
                            üretimYılıı = read.next();}
        else if(secim==7) { 
                            hızz = read.next(); 
                            fiyatt = read.next(); 
                            markaa = read.next();
                            renkk = read.next(); 
                            tekerlekSayısıı = read.next(); 
                           yakıtTürüü="ww"+read.next();  c=yakıtTürüü;
                            yolcuSayısıı = read.next(); 
                            üretimYılıı = read.next();}
        else if(secim==8) { 
                            hızz = read.next(); 
                            fiyatt = read.next(); 
                            markaa = read.next();
                            renkk = read.next(); 
                            tekerlekSayısıı = read.next(); 
                            yakıtTürüü = read.next();
                            yolcuSayısıı = read.next(); 
                            üretimYılıı="ww"+read.next();  c=üretimYılıı;   }
    } 
    else {
                            hızz = read.next(); 
                            fiyatt = read.next(); 
                            markaa = read.next();
                            renkk = read.next(); 
                            tekerlekSayısıı = read.next(); 
                            yakıtTürüü = read.next();
                            yolcuSayısıı = read.next(); 
                            üretimYılıı = read.next(); 
         }         
 oldContent=oldContent+","+ID+","+hızz+","+fiyatt+","+markaa+","+renkk+","+tekerlekSayısıı+","+yakıtTürüü+","+yolcuSayısıı+","+üretimYılıı+","+System.lineSeparator();
   str=read.nextLine(); 
}     
  String newContent = oldContent.replaceAll(c,a);
  writer = new FileWriter(fileToBeModified);  
            writer.write(newContent);
                reader.close();      
                writer.close();
   } catch (FileNotFoundException ex) {
            Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
        }
  } catch (FileNotFoundException ex) {
            Logger.getLogger(Arac.class.getName()).log(Level.SEVERE, null, ex);
        }
  }       
  
///************************************
void DosyaOku (File dosya,int secim) throws FileNotFoundException{
    
   Scanner read = new Scanner (dosya);
   read.useDelimiter(",");
   String str,hızz,ID,fiyatt,markaa,renkk,tekerlekSayısıı,yakıtTürüü,yolcuSayısıı,üretimYılıı;
   
     switch (secim) {
        case 1: 
           {  System.out.println("Kara Taşıtları:");
              while(read.hasNextLine())
              {  ID=read.next();  hızz = read.next(); fiyatt = read.next(); markaa = read.next();
                 renkk = read.next(); tekerlekSayısıı = read.next(); yakıtTürüü = read.next();
                 yolcuSayısıı = read.next(); üretimYılıı = read.next(); str=read.nextLine(); 
             if( ID.startsWith("otomobil") || ID.startsWith("bisiklet")) { 
                System.out.print(ID+" "+hızz+" "+fiyatt+" "+markaa+" "+renkk+" "+tekerlekSayısıı+" "+yakıtTürüü+" "+yolcuSayısıı+" "+üretimYılıı+"\n"); //just for debugging
              }      
               }read.close();  break; }
        case 2:
          {  System.out.println("Deniz Taşıtları:");
             while(read.hasNextLine())
             {  ID=read.next();  hızz = read.next(); fiyatt = read.next(); markaa = read.next();
                renkk = read.next(); tekerlekSayısıı = read.next(); yakıtTürüü = read.next();
                yolcuSayısıı = read.next(); üretimYılıı = read.next(); str=read.nextLine(); 
            if( ID.startsWith("gemi") || ID.startsWith("ucangemi")) { 
                System.out.print(ID+" "+hızz+" "+fiyatt+" "+markaa+" "+renkk+" "+tekerlekSayısıı+" "+yakıtTürüü+" "+yolcuSayısıı+" "+üretimYılıı+"\n"); //just for debugging
                }      
                }read.close();  break; }
        case 3: 
           {  System.out.println("Hava Taşıtları:");
              while(read.hasNextLine())
              {  ID=read.next();  hızz = read.next(); fiyatt = read.next(); markaa = read.next();
                 renkk = read.next(); tekerlekSayısıı = read.next(); yakıtTürüü = read.next();
                 yolcuSayısıı = read.next(); üretimYılıı = read.next(); str=read.nextLine(); 
             if( ID.startsWith("ucak")|| ID.startsWith("ucangemi")) { 
                 System.out.print(ID+" "+hızz+" "+fiyatt+" "+markaa+" "+renkk+" "+tekerlekSayısıı+" "+yakıtTürüü+" "+yolcuSayısıı+" "+üretimYılıı+"\n"); //just for debugging
                 }      
                 }read.close();  break; }
        default  :     break;
        
  }    
}
   ///////////////////////////************//////////////////////////
void menu (File dosya){
        Scanner giris=new Scanner (System.in);
        System.out.println();
        System.out.println("Yapmak İstediğiniz İşlemi Seçiniz:");  
        System.out.println("1.Veri Girişinde Bulun");
        System.out.println("2.Veri Listele");
        System.out.println("3.Veri Güncelle");
        System.out.println("Çıkış");
        
        int secim=giris.nextInt();
        if(secim==1)      { veriGirisi(dosya); } 
        else if(secim==2) { veriListeleme(dosya); menu(dosya); }
        else if(secim==3) { veriGüncelleme(dosya); menu(dosya);} 
        else {   System.exit(0); }
}

///////////////***************************
void DosyaYaz(File file) throws IOException
{   try (
               java.io.PrintWriter yaz = new PrintWriter(new FileWriter(file, true))) {
            if (!file.exists()) {
                file.createNewFile();
            }  }
}

//////////
  public static void main(String[] args) throws IOException {
        Arac a=new Arac();
        File dosya=new File("aracKayit.txt");
        a.menu(dosya);        
} 

} 

///***************************************************************************


