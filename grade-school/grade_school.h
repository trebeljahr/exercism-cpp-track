#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

namespace grade_school
{

    class Roster
    {
    public:
        map<int, vector<string>> data;
        bool empty();
    };

    class school
    {
    public:
        Roster internalRoster = Roster{};
        void add(string name, int grade);
        vector<string> grade(int query) const;
        map<int, vector<string>> roster() const;
    };
} // namespace grade_school

#endif // GRADE_SCHOOL_H