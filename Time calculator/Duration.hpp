/*
Duration.hpp
-------------

By Lamy237, for the time calculator

Role : - Creation of the class Duration
       - prototypes of the methods and functions used to add, subtract, compare, and display time values.

Creation: January 1, 2022 at 4:31 (Indian Time)

Last update: July 9, 2022
*/

#ifndef DURATION_HPP_INCLUDED
#define DURATION_HPP_INCLUDED

    #include <iostream>

    class Duration
    {
    public:

        Duration(int hours = 0, int minutes = 0, int seconds = 0);

        void show() const;

        bool isEqual(Duration const& b) const;
        bool isSmaller(Duration const& b) const;

        Duration& operator+=(Duration const& a);
        Duration& operator+=(int seconds);
        Duration& operator-=(Duration const& a);
        Duration& operator-=(int seconds);

        void show(std::ostream &stream) const;

    private:

        int m_hours;
        int m_minutes;
        int m_seconds;
    };

    bool operator==(Duration const& a, Duration const& b);
    bool operator!=(Duration const& a, Duration const& b);
    bool operator<(Duration const& a, Duration const& b);
    bool operator>(Duration const& a, Duration const& b);
    bool operator<=(Duration const& a, Duration const& b);
    bool operator>=(Duration const& a, Duration const& b);

    Duration operator+(Duration const& a, Duration const& b);
    Duration operator+(Duration const& a, int seconds);
    Duration operator-(Duration const& a, Duration const& b);
    Duration operator-(Duration const& a, int seconds);

    std::ostream& operator<<(std::ostream &stream, Duration const& duration);

#endif // DURATION_HPP_INCLUDED
