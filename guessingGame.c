/*Import necessary libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Create main function with input parameters argc and argv
so that we can accept input from command line*/
void main (int argc, char*argv[])
{
    /*Init int programRun to 0*/
    /*Init int guessRun to 0*/
    /*Init int  default max to 10*/
    int programRun = 0;
    int guessRun = 0;
    int maxRun = 0;


    /*Declare int "userInput", "guessNumber", "userGuess", "max"
    Declare time_t "t" char 'q' for quit*/
    int userInput, guessNumber, userGuess, max;
    time_t t; 
    char q;
    

    /*Declare file for later use*/
    FILE *fp;

    /*We will make the max = number in max.txt(will start as 10)*/
    fp = fopen("max.txt","r");
    fscanf(fp,"%d",&max);
    fclose(fp);

    /*Init random number genereator*/
    srand((unsigned) time(&t));

    /*Do while programRun = 0 */
    do
    {
        /*
        /*Print out menu with options*/
        printf("\nPress 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");

        /*Scan user input and set "userInput" equal to it*/
        scanf("%d", &userInput);

        /*Switch statment for 3 options using "userInput"*/
        switch(userInput)
        {
            /*Option 1*/
            case 1: 
                /*Create random number starting from 1 to max and set it equal to guessNumber*/
                guessNumber = (rand() % max)+1;
                /*Set guessRun = 0 in case player wants to play game again*/
                guessRun = 0;
                /*Newline*/
                printf("\n");
                /*Do while guessRun = 0*/
                do{
                    /*Ask for user's guess*/
                    printf("Guess a number(1-%d):", max);
                    /*Scan for the user's input and set "userGuess" or "q" equal to it*/
                    scanf("%d", &userGuess);
                    scanf("%c", &q);


                    /*If user decides to not guess*/
                    if(q == 'q')
                    { 
                        /*Exit from guessing loop*/
                        break;
                    }
                    
                    /*Compare the user's guess*/
                    if(userGuess==guessNumber)
                    {
                        /*change value to exit loop*/
                        guessRun = 1;
                        printf("Congratulations you guessed the right number!\n");
                    }
                    if(userGuess<guessNumber)
                    {
                        printf("Your guess was too low\n");
                    }
                    if(userGuess>guessNumber)
                    {
                        printf("Your guess was too high\n");
                    }

                }while (guessRun == 0);
                break;
                
            /*Option 2*/
            case 2:
                /*Do while maxRun = 0*/
                do{
                    /*Tell them the max number they can set*/
                    printf("\nThe max number you can set is 32767\n");
                    /*Ask what they want to make the max number*/
                    printf("Max number:");
                    /*Change max*/
                    scanf("%d", &max);
                    /*if value is too high*/
                    if(max>32767)
                    {
                        printf("Sorry input number is too high\n");
                    }
                    /*if value is negative*/
                    else if(max<0)
                    {
                        printf("Sorry input number can't be negative\n");
                    }
                    /*Stop the loop*/
                    else
                    {
                        maxRun = 1;
                        fp = fopen("max.txt","w");
                        fprintf(fp,"%d", max);
                        fclose(fp);
                    }
                }while(maxRun==0);
                break;
                
            /*Option 3*/
            case 3:
                /*End the game and let the user know*/
                printf("\nThank you for playing!\n");
                programRun = 1;
                break;
        }

    } while (programRun == 0);
}
                



