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
#include <queue>

#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H

struct listNode {
    char letter;
    int value;
    listNode* right = nullptr;
    listNode* left = nullptr;
public:
    /*bool operator < (const listNode& right){
        return this->value < right.value;
    }*/
    listNode operator = (const listNode& newNode){
        this->letter = newNode.letter;
        this->value = newNode.value;
        right = newNode.right;
        left = newNode.left;
    }
};
struct  treeNode {
    int value;
    char letter;
    treeNode *left;
    treeNode *right;
};
struct compare {
    bool operator()(const listNode& l, const listNode& r) const
    {
        return l.value >= r.value;
    }
};

listNode* push(listNode *left, listNode *right);
void printTree(treeNode **head);
void getCodes(listNode  *root);
void printTable();
class huffmanTree {
};

#endif //HUFFMAN_HUFFMANTREE_H
