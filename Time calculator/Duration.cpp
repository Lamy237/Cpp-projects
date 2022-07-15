/*
Duration.cpp
-------------

By Lamy237, for the time calculator

Role : Definition of the methods and functions used to add, subtract, compare, and display time values.

Creation: January 1, 2022 at 4:31 (Indian Time)

Last update: July 15, 2022
*/

#include <iostream>

#include "Duration.hpp"


Duration::Duration(int hours, int minutes, int seconds)
{
    // If the seconds are greater than 60, we increase the minutes and adjust the seconds
    minutes += seconds / 60;
    seconds %= 60;

    m_seconds = seconds; // Setting m_seconds

    // If the minutes are greater than 60, we increase the hours and adjust the minutes
    hours += minutes / 60;
    minutes %= 60;

    // Setting m_minutes and m_hours
    m_minutes = minutes;
    m_hours = hours;
}


/* Logical Operators */

bool operator==(Duration const& a, Duration const& b)
{
    return (a.m_hours == b.m_hours && a.m_minutes == b.m_minutes && a.m_seconds == b.m_seconds);
}


bool operator!=(Duration const& a, Duration const& b)
{
    return !(a == b);
}


bool operator<(Duration const& a, Duration const& b)
{
    if(a.m_hours < b.m_hours)
        return true;
    else if(a.m_hours == b.m_hours && a.m_minutes < b.m_minutes)
        return true;
    else if(a.m_hours == b.m_hours && a.m_minutes == b.m_minutes && a.m_seconds < b.m_seconds)
        return true;
    else
        return false;
}


bool operator>(Duration const& a, Duration const& b)
{
    return !(a == b || a < b);
}


bool operator<=(Duration const& a, Duration const& b)
{
    return !(a > b);
}


bool operator>=(Duration const& a, Duration const& b)
{
    return !(a < b);
}


/* Arithmetic Operators */

Duration& Duration::operator+=(Duration const& a)
{
    // 1. Setting the seconds
    m_seconds += a.m_seconds;

    // If the seconds are greater than 60, we increase the minutes and adjust the seconds
    m_minutes += m_seconds / 60;
    m_seconds %= 60;

    // 2. Setting the minutes
    m_minutes += a.m_minutes;

    // If the minutes are greater than 60, we increase the hours and adjust the minutes
    m_hours += m_minutes / 60;
    m_minutes %= 60;

    // 3. Setting the hours
    m_hours += a.m_hours;

    return *this;
}

Duration operator+(Duration const& a, Duration const& b)
{
    Duration myCopy(a);
    myCopy += b;
    return myCopy;
}

Duration& Duration::operator+=(int seconds)
{
    Duration temp(0, 0, seconds); // Convert the seconds into hours via the constructor

    *this += temp; // Add the converted time to the current object

    return *this;
}

Duration operator+(Duration const& a, int seconds)
{
    Duration myCopy(a);
    myCopy += seconds;
    return myCopy;
}


Duration& Duration::operator-=(Duration const& a)
{
    /* If we do a unit-wise subtraction of both time values, the result of the subtraction will be wrong in case
       hour A is less than hour B (i.e if A < B and we do A - B).

       So the solution is to first find the greatest of both time values and subtract the least one from the greatest one.
       Then if hour A < hour B and we wanted to do A - B, we can just multiply our result by -1. */

    // 1. We find the greatest of both time values
    Duration smallest(*this < a ? *this : a), greatest(*this > a ? *this : a);

    // 2. We subtract the least time value from greatest one
    greatest.m_seconds -= smallest.m_seconds;
    if(greatest.m_seconds < 0)
    {
        greatest.m_minutes--;
        greatest.m_seconds += 60;
    }

    greatest.m_minutes -= smallest.m_minutes;
    if(greatest.m_minutes < 0)
    {
        greatest.m_hours--;
        greatest.m_minutes += 60;
    }

    greatest.m_hours -= smallest.m_hours;

    // 3. We multiply the result by -1 if the current time value is less than the one we want to subtract from it
    if(*this < a)
    {
        greatest.m_hours *= -1;
        greatest.m_minutes *= -1;
        greatest.m_seconds *= -1;
    }

    // 4. Setting the attributes of the current object
    m_seconds = greatest.m_seconds;
    m_minutes = greatest.m_minutes;
    m_hours = greatest.m_hours;

    return *this;
}

Duration operator-(Duration const& a, Duration const& b)
{
    Duration myCopy(a);
    myCopy -= b;
    return myCopy;
}


Duration& Duration::operator-=(int seconds)
{
    Duration temp(0, 0, seconds); // Convert the seconds into hours via the constructor

    *this -= temp; // Subtract the converted time from the current object

    return *this;
}

Duration operator-(Duration const& a, int seconds)
{
    Duration myCopy(a);
    myCopy -= seconds;
    return myCopy;
}


/* stream Operator */

void Duration::show(std::ostream &stream) const
{
    stream << m_hours << "h : " << m_minutes << "m : " << m_seconds << "s";
}

std::ostream& operator<<(std::ostream &stream, Duration const& duration)
{
    duration.show(stream);
    return stream;
}

