

package pkg6ncıproje;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Otomobil extends KaraTasitlari {
    private String oID=null;
    
     Otomobil(){
        this.fiyat=100000;   //yüz bin tl
        this.hız=300; // max (degisebilir)
        this.marka="bmw";
        this.renk="siyah";
        this.üretimYılı=2015;
        this.yakıtTürü="benzin";
        this.yolcuSayısı=5;
        this.tekerlekSayısı=4;
        int sayı=DosyaSatır();
        this.oID="otomobil"+sayı;
    }
    Otomobil(int f, int h, int üy, String m, String r,String yt){
        setFiyat(f);
        setHız(h);
        setMarka(m);
        setRenk(r);
        setÜretimYılı(üy);
        setYakıtTürü(yt);
        this.yolcuSayısı=5;
        this.tekerlekSayısı=4;
        int sayı=DosyaSatır();
        this.oID="otomobil"+sayı;
    }
    int DosyaSatır() {
        int satırS = 0;
         try
         {
         BufferedReader reader = null;
         reader = new BufferedReader(new FileReader("aracKayit.txt"));
         
         String satir = reader.readLine();
             while (satir!=null) {
              if(satir.startsWith(",otomobil")){
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
            yaz.print(","+getoID()+",");
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
  String getYakıtTürü(){
      return this.yakıtTürü;
  }
  void setYakıtTürü(String yt){
      this.yakıtTürü=yt;
  }
    int getYolcuSayısı(){
      return this.yolcuSayısı;
    }
    int getTekerlekSayısı(){
      return this.tekerlekSayısı;
  }
    String getoID(){
        return this.oID;
    }
  
}