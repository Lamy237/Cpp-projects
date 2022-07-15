/*
Duration.hpp
-------------

By Lamy237, for the time calculator

Role : - Creation of the class Duration
       - Prototypes of the methods and functions used to add, subtract, compare, and display time values.

Creation: January 1, 2022 at 4:31 (Indian Time)

Last update: July 15, 2022
*/

#ifndef DURATION_HPP_INCLUDED
#define DURATION_HPP_INCLUDED

    #include <iostream>

    class Duration
    {
    public:

        Duration(int hours = 0, int minutes = 0, int seconds = 0);

        Duration& operator+=(Duration const& a);
        Duration& operator+=(int seconds);
        Duration& operator-=(Duration const& a);
        Duration& operator-=(int seconds);

    private:

        void show(std::ostream &stream) const;

        int m_hours;
        int m_minutes;
        int m_seconds;

        friend bool operator==(Duration const& a, Duration const& b);
        friend bool operator<(Duration const& a, Duration const& b);
        friend std::ostream& operator<<(std::ostream &stream, Duration const& duration);
    };

    bool operator!=(Duration const& a, Duration const& b);
    bool operator>(Duration const& a, Duration const& b);
    bool operator<=(Duration const& a, Duration const& b);
    bool operator>=(Duration const& a, Duration const& b);

    Duration operator+(Duration const& a, Duration const& b);
    Duration operator+(Duration const& a, int seconds);
    Duration operator-(Duration const& a, Duration const& b);
    Duration operator-(Duration const& a, int seconds);

#endif // DURATION_HPP_INCLUDED
