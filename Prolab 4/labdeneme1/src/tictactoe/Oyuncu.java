package tictactoe;
import java.util.Scanner;
import java.util.Random;
public class Oyuncu extends OyunTahtasi { 
    
char harf;
String kullaniciAd;
char kullaniciTuru;
int satir,sutun;
 
Oyuncu() {
     harf='x';
     kullaniciTuru='i'; 
}
        
Oyuncu(boolean insanmiKontrolu){
     if(insanmiKontrolu=true){
     harf='x';
     kullaniciTuru='i';
     } else {
        harf='o';
        kullaniciTuru='b';
     }  
 }

Oyuncu(boolean insanmiKontrolu, char kr)
{   if(insanmiKontrolu=true) {
      harf=kr;
      kullaniciTuru='i';
     } else {
        harf=kr;
        kullaniciTuru='b';
     }
}

 void oyuncununHamlesiniAl(boolean kontrol, int boyut){
     this.boyut=boyut;
     if(kontrol==true) {
     insanOyuncuHamlesiniKontrol(kontrol);
     }  else if(kontrol==false) {
      bilgisayarHamlesiUret(kontrol);
                }
}
 
void insanOyuncuHamlesiniKontrol(boolean kontrol){
     Scanner scan=new Scanner(System.in);
     System.out.println("koordinatları giriniz: ");
      satir=scan.nextInt();
      sutun=scan.nextInt(); 
}
 
void bilgisayarHamlesiUret(boolean kontrol) {
       Random rnd=new Random(System.currentTimeMillis());
       satir=rnd.nextInt(boyut); 
       sutun=rnd.nextInt(boyut); 
       System.out.println("pc hamle:"+satir+" "+sutun);
}
 
boolean oyuncuTurunuAl(boolean kontrol){
    if(kontrol==true) {
       kontrol=false;
    }else if(kontrol==false) {
        kontrol=true;
    }
    return kontrol;
}

 char karakteriAl(char hrf)
{  if(hrf=='x'){
     hrf='o';
 }  else if(hrf=='o') {
     hrf='x'; }
    return hrf;
}
 
 void bosMuKontrol(char [][]dizi){
     int c=0;
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if(dizi[i][j]=='x' || dizi[i][j]=='o')
             { c++; }   }
                  }
 
     if(c==boyut*boyut) {
         System.out.println("bos yer yok");
         System.out.println("oyun bitti");
     }
}
 
}