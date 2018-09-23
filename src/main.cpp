#include "huffmanTree.h"

using namespace std;

int main() {
    list<listNode> frequencyList;
    priority_queue<listNode,vector<listNode>, compare> huffmanTreeQueue;
    listNode tempNode;
    ifstream file("C:\\Users\\Does\\CLionProjects\\First Task\\input.txt");

    if (!file.is_open()) {
        cout << "File has not been opened!" << endl;
        return -1;
    }

    char buffer;
    bool done = false;

    while (file.get(buffer)) {
        tempNode.letter = buffer;
        for(auto& item : frequencyList) {
            if (item.letter == buffer) {
                item.value++;
                done = true;
                break;
            }
        }
        if (!done) {
            tempNode.letter = buffer;
            tempNode.value = 1;
            frequencyList.push_back(tempNode);
        }
        done = false;
    }

    for(auto& item : frequencyList){
        huffmanTreeQueue.push(item);
    }

    while (huffmanTreeQueue.size() != 1){
        auto lessNode = new(listNode);
        *lessNode = huffmanTreeQueue.top();
        huffmanTreeQueue.pop();
        auto greaterNode = new(listNode);
        *greaterNode = huffmanTreeQueue.top();
        huffmanTreeQueue.pop();
        listNode temp = *push(lessNode, greaterNode);
        huffmanTreeQueue.push(temp);
    }

    listNode temp;
    temp = huffmanTreeQueue.top();
    huffmanTreeQueue.pop();
    getCodes(&temp);
    printTable();
}
