#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    // to make sure the rand() called different value each execution
    srand(time(NULL));

    // create random number from 0 to 2
    int pointer {};
    pointer = rand() % 3;
    
    // make an array of three items
    std::string choices[3];
    choices[0] = "Rock";
    choices[1] = "Paper";
    choices[2] = "Scissor";

    // take player input
    std::cout << "Input your choices here: (0. Rock, 1. Paper, 2. Scissor)" << std::endl;

    // store player input
    int playerChoice;
    std::cin >> playerChoice;

    if(playerChoice > 2)
        std::cout << "Invalid number, can only be from zero to two" << std::endl;
    else
        // make a case from player choice, and print something depending on what the player type
        switch(playerChoice)
        {
            case 0:
                std::cout << "You choose Rock" << std::endl;
                break;
            case 1:
                std::cout << "You choose Paper" << std::endl;
                break;
            case 2:
                std::cout << "You choose Scissor" <<std::endl;
                break;
        }

        // show what computer choose
        std::cout << "Computer choose: " << choices[pointer] << std::endl;

        // Simple logic of rock papper scissor
        if(choices[playerChoice] == choices[pointer])
            std::cout << "Draw" << std::endl;
        else if(choices[playerChoice] == "Rock" && choices[pointer] == "Paper")
            std::cout << "Lose" << std::endl;
        else if(choices[playerChoice] == "Rock" && choices[pointer] == "Scissors")
            std::cout << "Win" << std::endl;
        else if(choices[playerChoice] == "Paper" && choices[pointer] == "Scissors")
            std::cout << "Lose" << std::endl;
        else if(choices[playerChoice] == "Paper" && choices[pointer] == "Rock")
            std::cout << "Win" << std::endl;
        else if(choices[playerChoice] == "Scissor" && choices[pointer] == "Rock")
            std::cout << "Lose" << std::endl;
        else if(choices[playerChoice] == "Scissor" && choices[pointer] == "Paper")
            std::cout << "Win" << std::endl;
        else
            std::cout << "Undecided" << std::endl;

    return 0;
}
