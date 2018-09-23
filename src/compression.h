#include "huffmanTree.h"

#ifndef HUFFMAN_COMPRESSION_H
#define HUFFMAN_COMPRESSION_H

extern std::map<char, unsigned long> byteTable;
extern std::vector<bool> bufferVector;

std::vector<bool> binaryEntity(char);
std::vector<bool> binaryEntity(int);
std::vector<bool> binaryEntity(long);
void becomeByte();
void printByte();
char assembleChar();

class compression {
};

#endif //HUFFMAN_COMPRESSION_H
