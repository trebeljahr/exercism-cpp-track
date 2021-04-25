#include "nucleotide_count.h"
#include <map>
#include <string>

namespace nucleotide_count
{
    counter::counter(std::string input)
    {
        result = {{'A', 0},
                  {'T', 0},
                  {'C', 0},
                  {'G', 0}};
        if (input.find_first_not_of("ATCG") != std::string::npos)
        {
            throw std::invalid_argument("DNA string can only contain letters ATCG");
        }
        sequence = input;
        for (auto elem : input)
        {
            result[elem]++;
        }
    }
    std::map<char, int> counter::nucleotide_counts() const
    {
        return result;
    }
    int counter::count(char letter) const
    {
        std::string letterAsString(1, letter);
        if (letterAsString.find_first_not_of("ATCG") != std::string::npos)
        {
            throw std::invalid_argument("DNA string can only contain letters ATCG");
        }
        return result.at(letter);
    }
} // namespace nucleotide_count
