#include "huffmanTree.h"
#include "compression.h"

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

    file.close();

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
    becomeByte();
    printByte();

    ofstream fileOutput("C:\\Users\\Does\\CLionProjects\\First Task\\output.txt", ios::out | ios::binary);
    ifstream fileInput("C:\\Users\\Does\\CLionProjects\\First Task\\input.txt");

    //int uniqueLetter = charTable.size();
    vector<bool> temp1;

    /*int k = 128;
    while(k > 0) {
        unsigned char temp2 = bool(uniqueLetter&k);
        fileOutput.write(&temp2, sizeof(usigned char));
        k = k>>1;
    }*/
/*
    for (auto item : charTable) {
        vector<bool> tempVector = binaryEntity(item.first);
        int temple = 0;
        int count = 32768;
        for (bool item1 : tempVector) {
            fileOutput << item1;
        }

        int length = item.second.size();
        tempVector = binaryEntity(length);

        for (bool item1 : tempVector) {
            fileOutput << item1;
        }

        tempVector = item.second;

        for (bool item1 : tempVector) {
            fileOutput << item1;
        }
    }

    while (fileInput.get(buffer)) {
        vector<bool> tempVector = charTable[buffer];

    }
*/
}
