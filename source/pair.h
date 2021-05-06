#ifndef PAIR_H
#define PAIR_H

/*
 * @brief   A Pair represents an element of an encoded string in the Encoded struct.
 *          This is a pair containing a character and an integer.
 * @field c The character that is encoded.
 * @field n The count of the character.
 */
typedef struct {
    char c;
    int n;
} Pair;

#endif