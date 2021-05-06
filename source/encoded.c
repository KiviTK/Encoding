#include "encoded.h"
#include <stdlib.h>
#include <string.h>

Encoded* makeEncoded(const char* string)
{
    Encoded* encoded = malloc(sizeof (Encoded));
    encoded->length = 0;
    encoded->pairSequence = NULL;

    size_t stringSize = strlen(string);

    if (stringSize != 0)
    {
        encoded->pairSequence = malloc(sizeof (Pair) * stringSize);
        encoded->pairSequence[0].c = string[0];
        encoded->pairSequence[0].n = 1;
        int current = 0;

        for (int i = 1; i < stringSize; i++)
        {
            if (encoded->pairSequence[current].c == string[i])
                encoded->pairSequence[current].n++;
            else
            {
                current++;
                encoded->pairSequence[current].c = string[i];
                encoded->pairSequence[current].n = 1;
            }
        }

        encoded->length = current + 1;
        encoded->pairSequence = realloc(encoded->pairSequence, encoded->length * sizeof (Pair));
    }

    return encoded;
}

void decodeSequence(char* buffer, size_t bufferSize, Encoded* encodedSequence)
{
    size_t bufferIndex = 0;
    for (int i = 0; i < encodedSequence->length; i++)
    {
        for (int j = 0; j < encodedSequence->pairSequence[i].n; j++)
        {
            if (!(bufferIndex < bufferSize - 1))
            {
                buffer[bufferIndex + 1] = '\0';
                return;
            }

            buffer[bufferIndex] = encodedSequence->pairSequence[i].c;
            bufferIndex++;
        }
    }

    buffer[bufferIndex] = '\0';
}

size_t getDecodedLength(const Encoded* encodedSequence)
{
    size_t len = 0;

    for (int i = 0; i < encodedSequence->length; i++)
        len += encodedSequence->pairSequence[i].n;

    return len;
}

void deleteEncoded(Encoded* encodedSequence)
{
    free(encodedSequence->pairSequence);
    free(encodedSequence);
}

