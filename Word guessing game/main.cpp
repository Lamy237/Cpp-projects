#include <iostream>

#include "functions.hpp"
#include "dictionary.hpp"


int main(int argc, const char *argv[])
{
    std::string secretWord, mixedWord, enteredWord;
    std::vector<int> scores;
    int continueGame(0);

    std::cout << "\n===== WELCOME TO THE WORD GUESSING GAME ! =====\n\n";

    do
    {
        int chances(5);

        // 1 : We store the chosen word in the string secretWord
        secretWord = choose_word();

        // 2 : We mix up the letters of the entered word
        mixedWord = mix_letters(secretWord);

        // 3 : We ask the user to guess the secret word
        do
        {
            std::cout << "\nYou have " << chances << " chance(s) left\n";
            std::cout << "What is the secret word ? " << mixedWord << "\n";
            std::cout << "Enter a word : ";
            std::cin >> enteredWord;
            upper_string(enteredWord);

            if(enteredWord != secretWord)
            {
                chances--;

                if(chances > 0)
                    std::cout << "\nWrong answer !\n\n";
                else
                    std::cout << "\nGAME OVER ! The secret word was : " << secretWord << "\n\n";
            }
            else
            {
                std::cout << "\nCongratulations ! The secret word was : " << secretWord << "\n\n";
            }

        }while(enteredWord != secretWord && chances > 0);

        scores.push_back(chances);

        // 4 : Prompt the user whether to keep playing or not
        do
        {
            std::cout << "\nSelect an option\n1. New game\n2. Quit\n\n";
            std::cout << "Input here : ";
            continueGame = read_int();

            if(continueGame != 1 && continueGame != 2)
                std::cout << "Choice not registered, please enter a valid input\n\n";
        }while(continueGame != 1 && continueGame != 2);

        if(continueGame == 1)
        {
            std::cout << "\n--------------------------------\n";
            std::cout << "            NEW GAME           \n";
            std::cout << "--------------------------------\n";
        }
        else
        {
            std::cout << "\nYour average score is " << average_score(scores) << "/5 \n";
        }

    }while(continueGame == 1);

    return 0;
}

