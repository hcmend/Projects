/**
 * Name: Hailey Mendenhall
 * Date: 12/9/2021
 * Purpose: To show that we can take a set of rules and create a complex program that follows them. 
 * This project also displays that we can make a game and caluclate a win rate of that game.
 */
import java.util.Random;

public class DiceGame {
    public static void main(String[] args) {
    playDiceGame();
    System.out.println();
    calculateWinRate(6);
    }
    
    /**
     * On call, prints play of a dice game that has the following rules:
     * Two six-sided die are rolled each round.
     * On the first round, if the number is a 7 or 11, the player wins.
     * On the first round, if the number is a 2, 3 or 12, the computer wins.
     * If the number on the first round is a 4-6 or a 8-10, then that number is
     * the 'target' for the player.
     * The game continues an indefinite number of rounds until either the target
     * is rolled (in which case the player wins) or a 7 is rolled (in which case
     * the computer wins)
     * The results are printed out after each roll as well as an announcement
     * whether the player wins or loses.
     * A return is also made after the game has concluded.
     * @return true if the player won, false if the computer won
     */
    public static boolean playDiceGame(){
        Random rand = new Random();
        int roll = rand.nextInt(12) + 1;
        System.out.println("The first roll is: " + roll);
        if (roll == 7 || roll == 11){
            System.out.println("You win! :)");
            return true;
        } 
        if (roll == 2 || roll == 3 || roll == 12){
            System.out.println("You lose! :(");
            return false;
        }            
        System.out.println("Your target number is: " + roll);               
        int target = roll;
        roll = rand.nextInt(12) + 1;
        System.out.println("The roll is: " + roll);
        while (roll != target && roll != 7){
            roll = rand.nextInt(12) + 1;
            System.out.println("The roll is: " + roll);
        }
        if (roll == 7){
            System.out.println("You lose! :(");
            return false;
        }
        else {
            System.out.println("You win! :)");
            return true;
        }
      
    }
    /**
     * Calculates the winrate of the dice game by playing the game many times
     * and keeping track of wins and losses. The final value returned represents
     * the percentage of games that have been won.
     * @param gamesPlayed the number of times to play the game.
     * @return A double representing percent of games that were won.
     * Can be calculated with the formula: (wins)/(total games) * 100
     */
    public static double calculateWinRate(int gamesPlayed){
        int gamesWon = 0;
        for (int i = 0; i < gamesPlayed; i++){
            boolean result = playDiceGame(); 
            if (result == true){
                gamesWon += 1;
            }
        }        
        double winRate = (double)gamesWon/gamesPlayed * 100;
        System.out.println("Your win rate is: " + winRate);
        return winRate;
    }
}