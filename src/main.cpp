#include "main.h"

using namespace std;

int main() {
    list<listNode> frequencyList;
    list<listNode>::iterator it;
    listNode tempNode;
    ifstream file("C:\\Users\\Does\\CLionProjects\\First Task\\input.txt");
    map<char,int> rangeFrequency;

    if (!file.is_open()) {
        cout << "File has not been opened!" << endl;
        return -1;
    }

    int count = 0;
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
        count++;
    }
    frequencyList.sort();

    treeNode *rootPtr = nullptr;

    for(auto& item : frequencyList) {
        cout << item.letter << " : " << item.value << endl;
        push(&rootPtr, &item);
    }
    cout << count << " " << frequencyList.size() <<endl;
}
