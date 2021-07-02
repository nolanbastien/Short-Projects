import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        boolean playAgain = true;
        String choice;
        int choiceInt = 10;
        int aiChoiceInt;
        String playAgainAnswer;

        while(playAgain){

            // Player Turn

            boolean valid = false;

            while(!valid) {
                System.out.print("\nChoose: rock, paper, scissors? (r/p/s) ");

                choice = in.nextLine();

                switch (choice) {
                    case "r" : choiceInt = 0; valid = true; break;
                    case "p" : choiceInt = 1; valid = true; break;
                    case "s" : choiceInt = 2; valid = true; break;
                    default : System.out.println("Try again."); break;
                }
            }
            // Opponent turn

            aiChoiceInt = (int) (Math.random()*3 % 10); // Math.random() is from (0,1(

            if (aiChoiceInt == 0) System.out.println("Opponent chose rock!");
            if (aiChoiceInt == 1) System.out.println("Opponent chose paper!");
            if (aiChoiceInt == 2) System.out.println("Opponent chose scissors!");

            // Result

            // Player and Opponent chose the same

            if (choiceInt == aiChoiceInt) System.out.println("Tie!");

            // Player chose rock

            if (choiceInt == 0 && aiChoiceInt == 1) System.out.println("You lost...");
            if (choiceInt == 0 && aiChoiceInt == 2) System.out.println("You win!");

            // Player chose paper

            if (choiceInt == 1 && aiChoiceInt == 0) System.out.println("You win!");
            if(choiceInt == 1 && aiChoiceInt == 2) System.out.println("You lost...");

            // Player chose scissors

            if (choiceInt == 2 && aiChoiceInt == 0) System.out.println("You lost...");
            if (choiceInt == 2 && aiChoiceInt == 1) System.out.println("You win!");

            // Play again ?
          
            valid = false;

            while(!valid) {

                System.out.print("Would you like to play again? (y/n) ");

                playAgainAnswer = in.nextLine();

                if (playAgainAnswer.equals("y")) { playAgain = true; valid = true; }
                else if (playAgainAnswer.equals("n")) { playAgain = false; valid = true; }
                else System.out.println("Try again.");

            }

        }

        System.out.println("Thank you for playing!");
        in.close();
    }
