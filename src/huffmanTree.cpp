#include "huffmanTree.h"

using namespace std;
   /* void push(treeNode **head, listNode *element) {
        if (*head == nullptr) {
            auto *list = new treeNode;
            list->value = element->value;
            list->letter = element->letter;
            list->left = nullptr;
            list->right = nullptr;
            *head = list;
        } else {
            if (element->value < (*head)->value) {
                if ((*head)->left == nullptr) {
                    auto *list = new treeNode;
                    list->value = element->value;
                    list->letter = element->letter;
                    list->left = nullptr;
                    list->right = nullptr;
                    (**head).left = list;
                } else {
                    push(&(*head)->left, element);
                }
            } else if (element->value >= (*head)->value) {
                if ((*head)->right == nullptr) {
                    auto *list = new treeNode;
                    list->value = element->value;
                    list->letter = element->letter;
                    list->left = nullptr;
                    list->right = nullptr;
                    (**head).right = list;
                } else {
                    push(&(*head)->right, element);
                }
            }
        }
    }*/
   vector<int> huffmanCode;
   map<char,vector<int>> charTable;

   listNode* push(listNode *left, listNode *right){
       auto *root = new(listNode);
       root->letter = left->letter;
       root->value = left->value + right->value;
       root->left = left;
       root->right = right;
       return root;
    }
    void printTree(treeNode **head) {
        if (*head != nullptr) {
            printTree(&(*head)->left);
            cout << (*head)->letter << " : " << (*head)->value << endl;
            printTree(&(*head)->right);
        } else {
            return;
        }
    }
    void getCodes(listNode  *root){
        if (root->left != nullptr) {
            huffmanCode.push_back(0);
            getCodes(root->left);
        }
        if (root->right != nullptr){
            huffmanCode.push_back(1);
            getCodes(root->right);
        }
        charTable[root->letter] = huffmanCode;
        huffmanCode.pop_back();
   }
    void printTable (){
       for(auto& item : charTable){
           cout << item.first << " : ";
           for(int i : item.second){
               cout << i;
           }
           cout << "\n";

       }
   }