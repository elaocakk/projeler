
package pkg6ncıproje;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Ucak extends HavaTasitlari implements Uçakİniş {
   private String uID=null;
    private int hizLimit=0;
 Ucak(){
        this.fiyat=50000000; //elli milyon tl
        this.hız=900;
        this.marka="airbus";
        this.renk="beyaz";
        this.üretimYılı=2016;
        this.yolcuSayısı=500;
        this.yakıtTürü="kerosen";
        this.tekerlekSayısı=10; 
        int sayı=DosyaSatır();
        this.uID="ucak"+sayı;
 }
 Ucak (int f, int h, int üy, String m, String r,int ys){
        setFiyat(f);
        setHız(h);
        setMarka(m);
        setRenk(r);
        setÜretimYılı(üy);
        setYolcuSayısı(ys);
        this.yakıtTürü="kerosen";
        this.tekerlekSayısı=10;
        int sayı=DosyaSatır();
        this.uID="ucak"+sayı;
     
 }
   int DosyaSatır() {
        int satırS = 0;
         try
         {
         BufferedReader reader = null;
         reader = new BufferedReader(new FileReader("aracKayit.txt"));
         
         String satir = reader.readLine();
             while (satir!=null) {
              if(satir.startsWith(",ucak")){
               satırS++;              }
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
            yaz.print(","+getuID()+",");
            yaz.print(getHız()+",");
            yaz.print(getFiyat()+",");
            yaz.print(getMarka()+",");
            yaz.print(getRenk()+",");
            yaz.print(getTekerlekSayısı()+",");
            yaz.print(getYakıtTürü()+",");
            yaz.print(getYolcuSayısı()+",");
            yaz.println(getÜretimYılı()+",");
           }  }
    
   @Override
     public int inis(int a) {
       Scanner scan= new Scanner (System.in);
        System.out.println("Hızınız: "+a+"\nUçağın durabilmesi için önce yavaşlaması gerekir\n!");
        System.out.println("Hızı ne kadar azaltılsın?");
        hizLimit=scan.nextInt();
        a=a-hizLimit;
          return a;
    }
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
    String getuID(){
        return this.uID;
    }
}