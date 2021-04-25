#include "difference_of_squares.h"
#include <cmath>

namespace difference_of_squares
{
    int square_of_sum(int input)
    {
        int result = pow(((input + 1) * input / 2), 2);
        return result;
    }
    int sum_of_squares(int input)
    {
        int result = 0;
        for (int i = 1; i <= input; i++)
        {
            result += pow(i, 2);
        }
        return result;
    }
    int difference(int input)
    {
        return square_of_sum(input) - sum_of_squares(input);
    }
} // namespace difference_of_squares
