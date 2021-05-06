#define CATCH_CONFIG_MAIN
#include "catch.hpp"

extern "C" {
    #include "encoded.h"
};


static bool pairEquals(Pair p1, Pair p2) {
    return p1.c == p2.c && p1.n == p2.n;
}

TEST_CASE( "encoding and decoding works as intended", "[encode-decode]" ) {
    SECTION("length of the string is 0") {
        const char* str = "";
        Encoded* encoded = makeEncoded(str);
        REQUIRE(encoded->length == 0);

        char decoded[10];
        decodeSequence(decoded, 10, encoded);
        REQUIRE(strcmp(decoded, str) == 0);

        deleteEncoded(encoded);
    }

    SECTION("length of the string is 0") {
        auto str = "a";
        Encoded* encoded = makeEncoded(str);
        REQUIRE((encoded->length == 1 && pairEquals(encoded->pairSequence[0], Pair {'a', 1})));

        char decoded[10];
        decodeSequence(decoded, 10, encoded);
        REQUIRE(strcmp(decoded, str) == 0);

        deleteEncoded(encoded);
    }

    SECTION("same characters next to each other") {
        auto str = "aaa";
        Encoded* encoded = makeEncoded(str);
        REQUIRE((encoded->length == 1 && pairEquals(encoded->pairSequence[0], Pair {'a', 3})));

        char decoded[10];
        decodeSequence(decoded, 10, encoded);
        REQUIRE(strcmp(decoded, str) == 0);

        deleteEncoded(encoded);
    }

    SECTION("different characters next to each other") {
        auto str = "abc";
        Encoded* encoded = makeEncoded(str);
        REQUIRE((encoded->length == 3 &&
                pairEquals(encoded->pairSequence[0], Pair {'a', 1}) &&
                pairEquals(encoded->pairSequence[1], Pair {'b', 1}) &&
                pairEquals(encoded->pairSequence[2], Pair {'c', 1})));

        char decoded[10];
        decodeSequence(decoded, 10, encoded);
        REQUIRE(strcmp(decoded, str) == 0);

        deleteEncoded(encoded);
    }
}


