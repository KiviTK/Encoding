#include <stdio.h>
#include "encoded.h"


int main() {
    printf("Setting up the environment...\n");
    printf("Initializing the encoder...\n");

    char* str = "assssldkjfo3ijflkdsajfo83j22888888372948yuoknjjjjj";

    printf("Started encoding string '%s'\n", str);

    Encoded* encoded = makeEncoded(str);

    printf("Encoder has finished encoding the string.\n");

    printf("Encoded sequence:\n");
    for (int i = 0; i < encoded->length; i++) {
        printf("(%c, %d) ", encoded->pairSequence[i].c, encoded->pairSequence[i].n);
    }
    printf("\n");

    printf("Started decoding the encoded sequence\n");
    char decodedStr[512];
    decodeSequence(decodedStr, 512, encoded);
    printf("Decoder has finished decoding the sequence.\n");
    printf("Decoded string:\n%s\n", decodedStr);

    return 0;
}

