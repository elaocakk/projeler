package javaapplication32;
//for the Scanner
import java.util.*;
 
public class JavaApplication32 {
 
    private static boolean first = false;
    private static char[][] board = new char[3][3];
    private static int aiScore = 0;
    private static int playerScore = 0;
 
    public static void main(String[] args){
        intro();
 
    }
 
    public static void intro(){
 
        Scanner console = new Scanner(System.in);
        System.out.println("Would you like to go first?");
        String goFirst = console.nextLine();
 
        if(goFirst.substring(0,1).equalsIgnoreCase("y")){
            first = true;
        }
        initializeBoard();
        getBoard();
        startGame(console);
 
 
    }
 
 
    public static void startGame(Scanner console){
 
        //clears the board to start the game
 
 
        if(first == true){
            userTurn(console);
        }else{
            compTurn(console);
        }
    }
 
    //allows user to play
    public static void userTurn(Scanner console){
        System.out.println("Where would you like to play?");
 
        int r = console.nextInt() - 1;
        int c = console.nextInt() - 1;
 
        if(board[r][c] == ' '){
            board[r][c] = 'X';
 
            if(board[0][0] == 'X'){
                getBoard();
                playerScore += 1;
                checkScoreUser(console);
 
            } else if(board[0][2] == 'X'){
                getBoard();
                playerScore += 3;
                checkScoreUser(console);
 
            } else if(board[2][0] == 'X'){
                getBoard();
                playerScore += 1000;
                checkScoreUser(console);
 
            } else if(board[2][2] == 'X'){
                getBoard();
                playerScore += 3000;
                checkScoreUser(console);
 
            } else if(board[1][1] == 'X'){
                getBoard();
                playerScore += 200;
                checkScoreUser(console);
 
            } else if(board[0][1] == 'X'){
                getBoard();
                playerScore += 2;
                checkScoreUser(console);
 
            } else if(board[1][0] == 'X'){
                getBoard();
                playerScore += 100;
                checkScoreUser(console);
 
            } else if(board[1][2] == 'X'){
                getBoard();
                playerScore += 300;
                checkScoreUser(console);
 
            } else if(board[2][1] == 'X'){
                getBoard();
                playerScore += 2000;
                checkScoreUser(console);
            }
 
        } else if (board[r][c] == 'X' || board[r][c] == 'O'){
            first = true;
            System.out.println("Please choose an empty space");
            startGame(console);
        }
 
        System.out.println("Cat's Game");
 
    }
 
 
    //allows computer to play
    public static void compTurn(Scanner console){
 
        System.out.println("Now it's my turn");
        System.out.println("");
 
        if(board[0][0] == ' '){
            board[0][0] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 1;
 
        } else if(board[0][2] == ' '){
            board[0][2] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 3;
 
        } else if(board[2][0] == ' '){
            board[2][0] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 1000;
 
        } else if(board[2][2] == ' '){
            board[2][2] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 3000;
 
        } else if(board[1][1] == ' '){
            board[1][1] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 200;
 
        } else if(board[0][1] == ' '){
            board[0][1] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 2;
 
        } else if(board[1][0] == ' '){
            board[1][0] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 100;
 
        } else if(board[1][2] == ' '){
            board[1][2] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 300;
 
        } else if(board[2][1] == ' '){
            board[2][1] = 'O';
            getBoard();
            userTurn(console);
            aiScore += 2000;
        }      
 
 
    }
 
    /*public static void checkUser(Scanner console){
 
        if(playerScore == 3){
            board[0][2] = 'O';
        } else if (playerScore ==)
 
    }*/
 
 
 
    //score checkers
    public static void checkScoreUser(Scanner console){
        if(aiScore == 3201 || aiScore == 1203 || aiScore == 6 ||
                aiScore == 600 || aiScore == 6000 || aiScore == 1101 ||
                        aiScore == 2202 || aiScore == 3303){
            System.out.println("I win!!! Hahahahahaha!!!!!!");
            intro();
 
        } else if (playerScore == 3201 || playerScore == 1203 || playerScore == 6 ||
                playerScore == 600 || playerScore == 6000 || playerScore == 1101 ||
                playerScore == 2202 || playerScore == 3303){
            System.out.println("You won!");
            intro();
        } else {
            compTurn(console);
        }
    }
    public static void checkScoreComp(Scanner console){
        if(aiScore == 3201 || aiScore == 1203 || aiScore == 6 ||
                aiScore == 600 || aiScore == 6000 || aiScore == 1101 ||
                        aiScore == 2202 || aiScore == 3303){
            System.out.println("I win!!! Hahahahahaha!!!!!!");
            intro();
 
        } else if (playerScore == 3201 || playerScore == 1203 || playerScore == 6 ||
                playerScore == 600 || playerScore == 6000 || playerScore == 1101 ||
                playerScore == 2202 || playerScore == 3303){
            System.out.println("You won!");
            intro();
        } else {
            userTurn(console);
        }
    }
 
 
 
    //board stuff
 
    //initializes board and fills it with black spaces
    public static void initializeBoard(){
 
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                board[r][c] = ' ';
            }
        }
 
    }
    //prints the actual board out
    public static void getBoard(){
 
        String bar = "  =============";
        System.out.println("    1   2   3");
        System.out.println(bar);
        System.out.println("1   " + board[0][0] + " | " + board[0][1] + " | " + board[0][2]);
        System.out.println(bar);
        System.out.println("2   " + board[1][0] + " | " + board[1][1] + " | " + board[1][2]);
        System.out.println(bar);
        System.out.println("3   " + board[2][0] + " | " + board[2][1] + " | " + board[2][2]);
        System.out.println(bar);
        System.out.println("");
 
 
    }
 
}