#include <iostream>
#include <map>
#include <stdlib.h>
#include <vector>

#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H

struct listNode {
    char letter;
    int value;
    listNode* right = nullptr;
    listNode* left = nullptr;
public:
    bool operator < (const listNode& right){
        return this->value < right.value;
    }
    listNode operator = (const listNode& newNode){
        this->letter = newNode.letter;
        this->value = newNode.value;
        right = newNode.right;
        left = newNode.left;
    }
};
struct compare {
    bool operator()(const listNode& l, const listNode& r) const
    {
        return l.value >= r.value;
    }
};

extern std::vector<bool> huffmanCode;
extern std::map<char,std::vector<bool>> charTable;

listNode* push(listNode *left, listNode *right);
void getCodes(listNode  *root);
void printTable();

#endif //HUFFMAN_HUFFMANTREE_H
