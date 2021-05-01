#include "reverse_string.h"
#include <string>
#include <algorithm>

namespace reverse_string
{
    std::string reverse_string(std::string str)
    {
        std::string copy(str);
        std::reverse(copy.begin(), copy.end());
        return copy;
    }
} // namespace reverse_string
