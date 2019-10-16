
package pkg6ncıproje;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class UcanGemi extends DenizTasitlari implements Uçakİniş{
      private int hizLimit=0;
      private String ugID=null;
      
        UcanGemi(){
        this.fiyat=1000000000; // 1 milyar tl
        this.hız=500; //km
        this.marka="boeing";
        this.renk="gri";
        this.üretimYılı=2014;
        this.yakıtTürü="likit hidrojen";
        this.yolcuSayısı=1000;
        this.tekerlekSayısı=0;
        int sayı=DosyaSatır();
        this.ugID="ucangemi"+sayı;
    }
    UcanGemi(int f, int h, int üy, String m, String r,int ys){
        setFiyat(f);
        setHız(h);
        setMarka(m);
        setRenk(r);
        setÜretimYılı(üy);
        setYolcuSayısı(ys);
        this.yakıtTürü="likit hidrojen";
        this.tekerlekSayısı=0; 
        int sayı=DosyaSatır();
        this.ugID="ucangemi"+sayı;
    }
    
       int DosyaSatır() {
        int satırS = 0;
         try
         {
         BufferedReader reader = null;
         reader = new BufferedReader(new FileReader("aracKayit.txt"));
         
         String satir = reader.readLine();
             while (satir!=null) {
              if(satir.startsWith(",ucangemi")){
               satırS++;
              // System.out.print("satırs:"+satırS);
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
       
            yaz.print(","+getugID()+",");
            yaz.print(getHız()+",");
            yaz.print(getFiyat()+",");
            yaz.print(getMarka()+",");
            yaz.print(getRenk()+",");
            yaz.print(getTekerlekSayısı()+",");
            yaz.print(getYakıtTürü()+",");
            yaz.print(getYolcuSayısı()+",");
            yaz.println(getÜretimYılı()+",");
           }  }
        
  public int inis(int a) {
       Scanner scan= new Scanner (System.in);
        System.out.println("Hızınız: "+a+"Uçan geminin durabilmesi için önce yavaşlaması gerekir\n!");
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
    String getugID(){
        return this.ugID;
    }
}