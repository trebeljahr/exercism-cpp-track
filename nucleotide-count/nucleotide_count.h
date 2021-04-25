#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include <map>
#include <string>

namespace nucleotide_count
{
    class counter
    {
    private:
        std::string sequence;
        std::map<char, int> result;

    public:
        counter(std::string input);
        std::map<char, int> nucleotide_counts() const;
        int count(char letter) const;
    };
} // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H