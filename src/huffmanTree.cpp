#include "huffmanTree.h"

using namespace std;
   vector<bool> huffmanCode;
   map<char,vector<bool>> charTable;

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
            huffmanCode.push_back(true);
            getCodes(root->left);
        }
        if (root->right != nullptr){
            huffmanCode.push_back(false);
            getCodes(root->right);
        }
        if(root->right == nullptr && root->left == nullptr)charTable[root->letter] = huffmanCode;
        huffmanCode.pop_back();
   }
    void printTable (){
       for(auto& item : charTable){
           int letter2 = int(item.first);
           int k = 128;
           while(k > 0) {
               cout << bool(letter2&k);
               k = k>>1;
           }
           cout << " : " << int(item.first) << " : ";
           for(int i : item.second){
               cout << i;
           }
           cout << "\n";

       }
   }