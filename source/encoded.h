#ifndef ENCODED_HEADER
#define ENCODED_HEADER

#include "pair.h" // Contains: struct Pair
#include <stdlib.h>

// A structure containing en encoded sequence.
typedef struct Encoded
{
    Pair* pairSequence; // The sequence of pairs that contain the encoded string
    int length; // The length of the encoded sequence
} Encoded;

// Create a new Encoded structure from a string.
Encoded* makeEncoded(const char* string);

// Decode an Encoded sequence to a buffer of bufferSize bytes.
void decodeSequence(char* buffer, size_t bufferSize, Encoded* encodedSequence);

// Get the size of the length of the string encoded in an Encoded sequence.
size_t getDecodedLength(const Encoded* encodedSequence);

// Destroy a previously created Encoded sequence
void deleteEncoded(Encoded* encodedSequence);

#endif // ENCODED_HEADER
