#include <iostream>

#include "Duration.hpp"


int main(int argc, const char *argv[])
{
    Duration time1(2, 65, 75), time2(4, 80, 23), diff;

    std::cout << "Time 1 = " << time1 << "\n\n";
    std::cout << "Time 2 = " << time2 << "\n\n";

    std::cout << "Time1 - Time2 = " << time1 - time2 << "\n\n";

    diff = time2 - 3600;
    std::cout << "Time2 - 3600s = " << diff << "\n\n";

    if(time1 == time2)
        std::cout << "Time1 and Time2 are equal\n";
    else if(time1 < time2)
        std::cout << "Time1 is less than Time2\n";
    else
        std::cout << "Time1 is greater than Time2\n";

    return 0;
}
