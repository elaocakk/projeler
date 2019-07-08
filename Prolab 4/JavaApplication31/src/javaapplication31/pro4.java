
package javaapplication31;

import java.util.Scanner;

public class pro4 {

    
 public static void main(String[] args) {
            char player='o';
        int row,column;
        Scanner k =  new Scanner (System.in);
        Game g = new Game ();
 
        g.initializeGame();
        System.out.println("Game ready !\n");
 
while(true)
{  
player=g.changePlayer(player);
System.out.print("\n"+player +" ,choose your location (row, column):");
row=k.nextInt();
column=k.nextInt();
 
    while (g.checkIfLegal(row,column))
    {
    System.out.println("That slot is already taken or out of bounds, please try again (row, column).");
    g.displayBoard();
    row=k.nextInt();
    column=k.nextInt();
    }
g.changeBoard(player,row,column );
g.displayBoard();
 
if(g.checkIfWinner())
    {
    System.out.println("\nThe winner is "+ player+" !");
    break;
 
    }
if(g.checkIfTie())
    {
        System.out.println("\nThe game is a tie !");
        break;
    }
}
 
 
    }
 
    }