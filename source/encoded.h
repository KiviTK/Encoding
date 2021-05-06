#ifndef ENCODED_HEADER
#define ENCODED_HEADER

#include "pair.h" // Contains: struct Pair

// A structure containing en encoded sequence.
typedef struct Encoded
{
    int length; // The length of the encoded sequence
} Encoded;

// Create a new Encoded structure from a string.
Encoded* makeEncoded(const char* string);

// Destroy a previously created Encoded sequence
void deleteEncoded(Encoded* encodedSequence);

#endif // ENCODED_HEADER
