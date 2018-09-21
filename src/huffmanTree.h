//
// Created by Does on 21.09.2018.
//
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <stdlib.h>

#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H

using namespace std;

struct listNode {
    char letter;
    int value;
public:
    bool operator<(const listNode& right){
        return this->value > right.value;
    }
};
struct  treeNode {
    int value;
    char letter;
    treeNode *left;
    treeNode *right;
};
void push(treeNode **head, listNode *element);
void printTree(treeNode **head);
class huffmanTree {
};


#endif //HUFFMAN_HUFFMANTREE_H
