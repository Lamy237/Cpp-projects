/*
functions.cpp
-------------

By Lamy237 for the word guessing game

Role: Definition of the functions managing the game

Last update: July, 4 2022.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <limits>

#include "functions.hpp"


std::string mix_letters(std::string word)
{
    std::string mixedWord;
    int position(0);

    srand(time(NULL));

    while(word.size() != 0)
    {
        position = rand() % word.size();

        mixedWord += word[position];
        word.erase(position, 1);
    }

    return mixedWord;
}


double average_score(std::vector<int> const& table)
{
    double mean(0);

    for(unsigned int i(0); i<table.size(); i++)
    {
        mean += table[i];
    }

    mean /= table.size();

    return mean;
}


void upper_string(std::string& word)
{
    for(unsigned int i(0); i<word.size(); i++)
    {
        word[i] = toupper(word[i]);
    }
}


/* Functions to handle invalid inputs */

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int read_int()
{
    int number(0);

    std::cin >> number;

    if(!std::cin)
    {
        std::cin.clear();
        ignore_line();
        return 0;
    }
    else
    {
        ignore_line();
        return number;
    }
}

