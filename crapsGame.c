#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Rolls two dice and returns sum (each dice is random number 1-6)
int rollDice(void) {
    int sum  = 0;
    int const DiceValue = 6;
    int const LowerLimit = 1;
    
    //Roll dice by generating random numbers between 1-g
    sum = rand() % DiceValue + LowerLimit;
    sum += rand() % DiceValue + LowerLimit;
    
    return sum;
}

//Plays one game of craps
bool playGame(void) {
    int sum = 0;
    int const WinningNum1 = 7, WinningNum2 = 11;
    int const LosingNum1 = 2, LosingNum2 = 3, LosingNum3 = 12;
    
    //First roll of game
    sum = rollDice();
    printf("You rolled: %d\n", sum);
    
    //Determine if player won or lost from roll
    if (sum == WinningNum1 || sum == WinningNum2) {
        printf("You win!\n");
        return true;
    }
    else if (sum == LosingNum1 || sum == LosingNum2 || sum == LosingNum3) {
        printf("You lose!\n");
        return false;
    }
    
    //If player hasn't won or lost, store "point"
    int point = sum;
    printf("Your point is: %d\n", point);
    
    //Continue rolling to continue game
    do {
        int const LosingNum = 7;
        
        //Roll dice
        sum = rollDice();
        printf("You rolled: %d\n", sum);
        
        //Determine if player won or lost
        if (sum == point) {
            printf("You win!\n");
            return true;
        }
        else if (sum == LosingNum) {
            printf("You lose!\n");
            return false;
        }
    } while(true);
}

//Keeps track of the number of wins and losses in one session
void winLoss(void) {
    int wins = 0, losses = 0;
    
    //Start gameplay
    char response;
    do {
        bool result = playGame();
        
        //Add corresponding win/loss to correct total
        if (result) {
            wins++;
        } else {
            losses++;
        }
        
        //Ask user if they would like to play again
        printf("Play again? ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');
    
    //Output results
    printf("\n\n");
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
}
/**
int main(int argc, char **argv) {
    winLoss();
}
*/