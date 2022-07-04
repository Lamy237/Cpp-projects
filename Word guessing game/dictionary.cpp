/*
dictionary.cpp
--------------

By Lamy237 for the word guessing game

Role: Definition of the functions used to randomly choose a word from the dictionary

Last update: July, 4 2022.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "dictionary.hpp"


std::string choose_word()
{
    std::string const FILE_PATH("dictionary.txt");

    std::ifstream file(FILE_PATH.c_str());
    if(!file)
    {
        std::cout << "Unable to open the file\n";
        exit(EXIT_FAILURE);
    }

    // Counting the number of words in the dictionary
    char letter;
    int numberOfWords(0);

    while(file.get(letter))
    {
        if(letter == '\n')
            numberOfWords++;
    }

    // Randomly choosing a word from the dictionary
    int chosenWordNumber(0);
    chosenWordNumber = random(numberOfWords);

    // Setting the cursor back at the beginning of the file
    file.clear();
    file.seekg(0);

    // Placing the cursor in front of the chosen word to read it
    while(chosenWordNumber > 0)
    {
        file.get(letter);

        if(letter == '\n')
            chosenWordNumber--;
    }

    // Storing the chosen word into a string
    std::string chosenWord;
    file >> chosenWord;

    return chosenWord;
}


int random(int maximum)
{
    int number(0);

    srand(time(NULL));
    number = rand() % maximum;

    return number;
}

