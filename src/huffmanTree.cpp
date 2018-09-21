#include "huffmanTree.h"

using namespace std;
    void push(treeNode **head, listNode *element) {
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
    }
    void push()
    void printTree(treeNode **head) {
        if (*head != nullptr) {
            printTree(&(*head)->left);
            cout << (*head)->letter << " : " << (*head)->value << endl;
            printTree(&(*head)->right);
        } else {
            return;
        }
    }
    treeNode *downTopPush(treeNode *node1, treeNode *node2) {
        treeNode *head;
        if (node1->value < node2->value) {
            head->left = node1;
            head->right = node2;
            head->value = node1->value + node2->value;
        } else {
            head->left = node2;
            head->right = node1;
            head->value = node1->value + node2->value;
        }
        return head;
    }
