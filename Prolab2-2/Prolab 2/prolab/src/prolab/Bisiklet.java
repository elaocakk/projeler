
package prolab;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Bisiklet extends KaraTasitlari {
 String bID=null;
 
    Bisiklet(){
        this.fiyat=500;
        this.hız=20;
        this.marka="salcano";
        this.renk="siyah";
        this.üretimYılı=2018;
        this.yakıtTürü="motorsuz";
        this.yolcuSayısı=1;
        this.tekerlekSayısı=2;
        int sayı=DosyaSatır();
        this.bID="bisiklet"+sayı;
    }
    
    Bisiklet(int f, int h, int üy, String m, String r){
        setFiyat(f);
        setHız(h);
        setMarka(m);
        setRenk(r);
        setÜretimYılı(üy);
        this.yakıtTürü="motorsuz";
        this.yolcuSayısı=1;
        this.tekerlekSayısı=2;
        int sayı=DosyaSatır();
        this.bID="bisiklet"+sayı;
    }
    
    int DosyaSatır() {
        int satırS = 0;
         try {
         BufferedReader reader = null;
         reader = new BufferedReader(new FileReader("aracKayit.txt"));
         
         String satir = reader.readLine();
             while (satir!=null) {
              if(satir.startsWith(",bisiklet")){
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
            yaz.print(","+getbID()+",");
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
    String getbID(){
        return this.bID;
    }
}