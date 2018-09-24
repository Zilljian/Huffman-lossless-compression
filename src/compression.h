#include "huffmanTree.h"

#ifndef HUFFMAN_COMPRESSION_H
#define HUFFMAN_COMPRESSION_H

extern std::vector<bool> bufferVector;

union byte {
    char letter;
    struct {
        unsigned a0 : 1;
        unsigned a1 : 1;
        unsigned a2 : 1;
        unsigned a3 : 1;
        unsigned a4 : 1;
        unsigned a5 : 1;
        unsigned a6 : 1;
        unsigned a7 : 1;
    } bit;
};

char assembleChar();

#endif //HUFFMAN_COMPRESSION_H
