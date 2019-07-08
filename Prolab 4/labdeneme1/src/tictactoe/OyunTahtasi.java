package tictactoe;
import java.util.Scanner;

public class OyunTahtasi {
    
   int boyut;
   char table[][]=new char[10][10];
 
   OyunTahtasi(){
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            table[i][j]=' ';
              }             } 
   }
       
   OyunTahtasi(char [][]oynTahtasi,int byt){
      this.boyut=byt;
        System.out.println(byt);
        table=oyunTahtasiniAl(oynTahtasi, byt);    
   }
   
  char [][]oyunTahtasiniAl(char [][]oynTahtasi,int byt) {
   
      for (int i = 0; i < byt; i++) {
        for (int j = 0; j < byt; j++) {
            table[i][j]=oynTahtasi[i][j];  
              }    }
      return table;
  }
  
 char [][] oyunTahtasiniAl(int byt) {
    this.boyut=byt;
    char a[][]=new char[byt][byt];
    for (int i = 0; i <byt; i++) {
        for (int j = 0; j < byt; j++) {
             a[i][j]=' ';
              }         }
       
         table=a.clone();
         return table;
  }
 
    boolean hamleyiYaz(int satir, int sutun, char hrfi){
     
        if(satir>boyut || sutun>boyut || satir<0 || sutun<0 ) {
        System.out.println("koordinatlar hatalı");
        return false;
                        }
        if(table[satir][sutun]=='x' || table[satir][sutun]=='o') {
        System.out.println("hamle yapılacak yer dolu");
        return false;
                            }
                else {
        System.out.println("hamle yapıldı");
        table[satir][sutun]=hrfi;
        return true;
                    }
}
   
    void oyunTahtasiniYazdir() {
        for (int i = 0; i < boyut; i++) {
            for (int j = 0; j < boyut; j++) {
                if(table[i][j]=='x' ) { System.out.print(" x "); }
                 else if (table[i][j]=='o' ) { System.out.print(" o "); }
                 else { System.out.print(" - "); }
              } System.out.println();
                            }
}
    
 void  kazanan(boolean kazanan,char hrf,char[][] table1)  {
   int  sayac=0;
    for (int i = 0; i < boyut; i++) { /// satir satir kontrol işlemi
        for (int j = 0; j < boyut; j++) {
            if(table1[i][j]==hrf)  {
                sayac++; }
              }
        if(sayac==boyut) { if(kazanan==true){ System.out.println("Siz kazandınız! Tebrikler!"); System.exit(0); }
                           else if(kazanan==false){System.out.println("Bilgisayar kazandı!"); System.exit(0);  }    
        } else {sayac=0;}
                    }
    
    sayac=0;
    for (int i = 0; i < boyut; i++) { /// sutun sutun kontrol işlemi
        for (int j = 0; j < boyut; j++) {
            if(table1[j][i]==hrf)  {
                sayac++; }
                }
        if(sayac==boyut) { if(kazanan==true){ System.out.println("Siz kazandınız! Tebrikler!"); System.exit(0); }
                            else if(kazanan==false){System.out.println("Bilgisayar kazandı!"); System.exit(0);   }    
        } else {sayac=0;}
                    }
    
    sayac=0;
     for (int i = 0; i < boyut; i++) { /// kosegen kontrol işlemi
        for (int j = 0; j < boyut; j++) {
            if(i==j) {
            if(table1[i][j]==hrf)  {
                sayac++; }
                    }
           }
        if(sayac==boyut) { if(kazanan==true){ System.out.println("Siz kazandınız! Tebrikler!"); System.exit(0); }
                            else if(kazanan==false){System.out.println("Bilgisayar kazandı!"); System.exit(0);  }    
      } else { }
                   }
     
    sayac=0;
    for (int i = 0; i < boyut; i++) { /// ters kosegen kontrol işlemi
        for (int j = 0; j < boyut; j++) {          
            if(i==boyut-1-j) {
            if(table1[i][j]==hrf)  {
                sayac++; }
                }
           }
        if(sayac==boyut) { if(kazanan==true){ System.out.println("Siz kazandınız! Tebrikler!"); System.exit(0); }
                            else if(kazanan==false){System.out.println("Bilgisayar kazandı!"); System.exit(0);   }    
      } else { }
                   }
   
 }
 
 boolean beraberlikKontrol(char [][] table1) {
    
     for (int i = 0; i < boyut; i++) {
        for (int j=0; j< boyut; j++){
            if(table1 [i][j]==' ')
                return false;
        }}
    return true;
}
 
}