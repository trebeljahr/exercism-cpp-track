#include "hamming.h"
#include <stdexcept>

namespace hamming
{
    int compute(std::string a, std::string b)
    {
        int result = 0;
        if (a.size() != b.size())
        {
            throw std::domain_error("Strings have to be same size");
        }

        for (size_t i = 0; i < a.size(); i++)
        {
            if (a.at(i) != b.at(i))
            {
                result++;
            }
        }
        return result;
    }

} // namespace hamming
