
package pkg6ncıproje;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Gemi extends DenizTasitlari {
   private String gID=null;
 Gemi(){
        this.hız=70;
        this.fiyat=5000000;
        this.marka="armador";
        this.renk="beyaz";
        this.üretimYılı=2017;
        this.yakıtTürü="blend oil";
        this.yolcuSayısı=300;
        this.tekerlekSayısı=0;
        int sayı=DosyaSatır();
        this.gID="gemi"+sayı;
    }
 Gemi(int f, int h, int üy, String m, String r,int ys){
        setFiyat(f);
        setHız(h);
        setMarka(m);
        setRenk(r);
        setÜretimYılı(üy);
        setYolcuSayısı(ys); 
        this.yakıtTürü="blend oil";
        this.tekerlekSayısı=0;
        int sayı=DosyaSatır();
        this.gID="gemi"+sayı;
    }
    int DosyaSatır() {
        int satırS = 0;
         try
         {
         BufferedReader reader = null;
         reader = new BufferedReader(new FileReader("aracKayit.txt"));
         
         String satir = reader.readLine();
             while (satir!=null) {
              if(satir.startsWith(",gemi")){
               satırS++;
              }
              satir = reader.readLine();                
             } 
          }catch(final IOException e){  }
      
      return satırS;
    }
    
   @Override
 void DosyaYaz(File file) throws IOException {
         try (
                 java.io.PrintWriter yaz = new PrintWriter(new FileWriter(file, true))) {
            if (!file.exists()) {
                file.createNewFile();
            }
            yaz.print(","+getgID()+",");
            yaz.print(getHız()+",");
            yaz.print(getFiyat()+",");
            yaz.print(getMarka()+",");
            yaz.print(getRenk()+",");
            yaz.print(getTekerlekSayısı()+",");
            yaz.print(getYakıtTürü()+",");
            yaz.print(getYolcuSayısı()+",");
            yaz.println(getÜretimYılı()+",");
           }  }
    
   String getMarka(){
      return this.marka;
  }
  void setMarka(String m){
      this.marka=m;
  }
   int getFiyat(){
      return this.fiyat;
  }
  void setFiyat(int f){
      this.fiyat=f;
  }
   int getYolcuSayısı(){
      return this.yolcuSayısı;
  }
  void setYolcuSayısı(int ys){
      this.yolcuSayısı=ys;
  }
    int getHız(){
      return this.hız;
  }
  void setHız(int h){
      this.hız=h;
  }
  String getRenk(){
      return this.renk;
  }
  void setRenk(String r){
      this.renk=r;
  }
     int getÜretimYılı(){
      return this.üretimYılı;
  }
  void setÜretimYılı(int üy){
      this.üretimYılı=üy;
  }
    int getTekerlekSayısı(){
      return this.tekerlekSayısı;
  }
    String getYakıtTürü(){
        return this.yakıtTürü;
    }
    String getgID(){
        return this.gID;
    }
}
