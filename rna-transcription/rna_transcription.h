#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H
#include <string>
using namespace std;

namespace rna_transcription
{
    char to_rna(char letter);
    string to_rna(string sequence);
} // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H