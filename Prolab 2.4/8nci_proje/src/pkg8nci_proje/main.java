
package pkg8nci_proje;

import java.sql.*;

public class main {


public static void main(String [] args)
{
    String q="benzin";
    switch(q) {
    case "benzin" : System.out.println("oldu");
    case "dizel" : System.out.println("olmadı");
    default : System.out.println("aq");
}
    
  /*  
try
{
Connection conn=DriverManager.getConnection("jdbc:mysql://localhost/new", "root", "elaocak");
//System.out.println(“Bağlantı Sağlandı”);
String query="Select * From kisiler";
Statement stmt=conn.createStatement();
ResultSet rs=stmt.executeQuery(query);
while(rs.next())
{
System.out.println("ID:"+rs.getString("id") +"ad"+rs.getString("Ad") +"soyad"+rs.getString("Soyad") 
        +"yas"+rs.getString("Yas") +"cinsiyet"+rs.getString("Cinsiyet"));
}

}catch(Exception e)
{
System.err.println(e);
}*/ 
}

}