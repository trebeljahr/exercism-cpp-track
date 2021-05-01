#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture
{
    int steps(int num)
    {
        if (num <= 0)
        {
            throw std::domain_error("Number needs to be bigger than 0");
        }
        int steps = 0;
        while (num != 1)
        {
            steps++;
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num = num * 3 + 1;
            }
        }

        return steps;
    }
} // namespace collatz_conjecture
