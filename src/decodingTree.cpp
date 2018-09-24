#include "compression.h"
#include "huffmanTree.h"
#include "decodingTree.h"

using namespace std;

ofstream decodedOut(R"(C:\Users\Does\CLionProjects\First Task\decodedOut.txt)");
vector<bool>  inputBuffVector;

void decode(){
    ifstream fileDecoding (R"(C:\Users\Does\CLionProjects\First Task\output.txt)");
    byte decodeBuff;

    if (!fileDecoding.is_open()) {
        cout << "File has not been opened!" << endl;
    }

    while (fileDecoding.get(decodeBuff.letter)) {
        inputBuffVector.push_back(bool(decodeBuff.bit.a0));
        inputBuffVector.push_back(bool(decodeBuff.bit.a1));
        inputBuffVector.push_back(bool(decodeBuff.bit.a2));
        inputBuffVector.push_back(bool(decodeBuff.bit.a3));
        inputBuffVector.push_back(bool(decodeBuff.bit.a4));
        inputBuffVector.push_back(bool(decodeBuff.bit.a5));
        inputBuffVector.push_back(bool(decodeBuff.bit.a6));
        inputBuffVector.push_back(bool(decodeBuff.bit.a7));

        matchBuff();
    }

    while (!inputBuffVector.empty()){
        matchBuff();
    }

    fileDecoding.close();
    decodedOut.close();
}
void matchBuff(){
    bool fit = true;
    int el = 0;

    for (auto item : charTable){
            while (fit && el < item.second.size()) {
                if (item.second[el] != inputBuffVector[el]) {
                    fit = !fit;
                }
                el++;
            }
            if (fit && el == item.second.size()) {
                printMatched(item.first);
                inputBuffVector.erase(inputBuffVector.begin(), inputBuffVector.begin() + el);
                return;
            }
            el = 0;
            fit = true;
    }
}
void printMatched(char item){
    decodedOut << item;
}

