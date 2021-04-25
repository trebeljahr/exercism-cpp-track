#include "rna_transcription.h"
#include <string>
#include <algorithm>
#include <iostream>

char convert_single_rna_letter(char letter)
{
    if (letter == 'A')
        return 'U';
    if (letter == 'G')
        return 'C';
    if (letter == 'T')
        return 'A';
    if (letter == 'C')
        return 'G';
    return '.';
}

namespace rna_transcription
{
    char to_rna(char letter)
    {
        return convert_single_rna_letter(letter);
    }
    string to_rna(string sequence)
    {
        string mappedSequence(sequence.size(), ' ');
        int counter = 0;
        for (auto it = sequence.begin(); it != sequence.end(); ++it, ++counter)
        {
            const char letter = sequence[counter];
            mappedSequence[counter] = convert_single_rna_letter(letter);
        }
        return mappedSequence;
    }
} // namespace rna_transcription
