#include "say.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;
namespace say
{
    string Join(vector<string> strings)
    {
        string result = strings[0];
        for (size_t i = 1; i <= strings.size() - 1; i++)
        {
            result += " " + strings[i];
        }
        return result;
    }

    const map<int, string> counterToSyllable = {
        {0, ""},
        {1, ""},
        {2, " thousand"},
        {3, " million"},
        {4, " billion"},
        {5, " trillion"},
    };
    const map<int, string>
        digitToSound = {
            {0, "zero"},
            {1, "one"},
            {2, "two"},
            {3, "three"},
            {4, "four"},
            {5, "five"},
            {6, "six"},
            {7, "seven"},
            {8, "eight"},
            {9, "nine"},
            {10, "ten"},
            {11, "eleven"},
            {12, "twelve"},
            {13, "thirteen"},
            {14, "fourteen"},
            {15, "fifteen"},
            {16, "sixteen"},
            {17, "seventeen"},
            {18, "eighteen"},
            {19, "nineteen"},
            {20, "twenty"},
            {30, "thirty"},
            {40, "forty"},
            {50, "fifty"},
            {60, "sixty"},
            {70, "seventy"},
            {80, "eighty"},
            {90, "ninety"}};

    string convert_to_padded_string(unsigned long long number)
    {
        string numberAsString = to_string(number);
        if (numberAsString.size() % 3 == 1)
        {
            numberAsString = "--" + numberAsString;
        }
        if (numberAsString.size() % 3 == 2)
        {
            numberAsString = "-" + numberAsString;
        }
        return numberAsString;
    }

    int getDigit(int n, int number)
    {
        auto a = fmod((float)number / (float)pow(10, n - 1), 10);
        return floor(a);
    }

    string in_english(unsigned long long number)
    {
        if (number >= 1000ULL * 1000ULL * 1000ULL * 1000ULL)
            throw domain_error("Number has to be bigger than or equal to 0 and smaller than one trillion (100.000.000.000)");

        if (number < 20)
            return say::digitToSound.at(number);

        string numberAsString = say::convert_to_padded_string(number);
        vector<string> substrings;
        int counter = floor(numberAsString.size() / 3);
        for (size_t i = 0; i <= numberAsString.size() - 3; i += 3)
        {
            string s = numberAsString.substr(i, 3);
            s.erase(std::remove(s.begin(), s.end(), '-'), s.end());
            int num = stoi(s);
            int hundreds = getDigit(3, num);
            int tens = getDigit(2, num) * 10;
            int ones = getDigit(1, num);

            string tensString = tens != 0 ? say::digitToSound.at(tens) + "-" : "";
            string onesString = ones != 0 ? say::digitToSound.at(ones) : "";
            string twoDigitString = (num <= 20) ? say::digitToSound.at(num) : tensString + onesString;
            string hundredsString = hundreds != 0 ? say::digitToSound.at(hundreds) + " hundred" + (twoDigitString == "" ? "" : " ") : "";

            string completeString = hundredsString + twoDigitString + say::counterToSyllable.at(counter);

            counter -= 1;
            if (num != 0)
                substrings.push_back(completeString);
        }

        return say::Join(substrings);
    }

} // namespace say
