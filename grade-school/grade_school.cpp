#include "grade_school.h"

namespace grade_school
{
    bool Roster::empty()
    {
        return true;
    }

    void logHelper(map<int, vector<string>> data)
    {
        cout << "Map: " << endl;
        for (auto elem : data)
        {
            cout << elem.first << ": [";
            for (size_t i = 0; i < elem.second.size() - 1; i++)
            {
                std::cout << elem.second.at(i) << ", ";
            }
            std::cout << elem.second.at(elem.second.size() - 1) << "]" << std::endl;
        }
    }

    void school::add(string name, int grade)
    {
        vector<string> &people = internalRoster.data[grade];
        bool foundPerson = find(people.begin(), people.end(), name) != people.end();
        if (!foundPerson)
        {
            people.push_back(name);
        };
        sort(people.begin(), people.end());
        internalRoster.data.insert(pair<int, vector<string>>(grade, people));
    }
    vector<string> school::grade(int query) const
    {
        if (internalRoster.data.count(query) == 0)
        {
            return vector<string>{};
        }
        return internalRoster.data.at(query);
    }
    map<int, vector<string>> school::roster() const
    {
        logHelper(internalRoster.data);
        return internalRoster.data;
    }
} // namespace grade_school
