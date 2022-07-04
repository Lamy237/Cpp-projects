/*
functions.hpp
-------------

By Lamy237 for the word guessing game

Role: Prototypes of the functions managing the game

Last update: July, 4 2022.
*/

#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

    #include <string>
    #include <vector>

    std::string mix_letters(std::string word);
    double average_score(std::vector<int> const& table);
    void upper_string(std::string& word);

    void ignore_line();
    int read_int();

#endif // FUNCTIONS_HPP_INCLUDED
