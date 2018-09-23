#include "compression.h"
#include "huffmanTree.h"

using namespace std;

map<char, unsigned long> byteTable;

vector<bool> binaryEntity(int number){
    vector<bool> tempVector;
    int k =8;
    while(k > 0) {
        tempVector.push_back(bool(number&k));
        k = k>>1;
    }
    return tempVector;
}
vector<bool> binaryEntity(long number){
    vector<bool> tempVector;
    int temp = int(number);
    int k =128;
    while(k > 0) {
        tempVector.push_back(bool(number&k));
        k = k>>1;
    }
    return tempVector;
}
vector<bool> binaryEntity(char letter){
    vector<bool> tempVector;
    int k = 8;
    int number = int(letter);
    while(k > 0) {
        tempVector.push_back(bool(number&k));
        k = k>>1;
    }
    return tempVector;
}
void becomeByte(){
    for (auto item : charTable){
       unsigned long mask = 2147483648;
        for (auto item2 : item.second){
            if (item2){
                byteTable[item.first] = byteTable[item.first] | mask;
            }
            mask = mask / 2;
        }
    }
}
void printByte(){
    for (auto item : byteTable){
        cout << int(item.first) << " " <<item.first << " : " << item.second << "\n";
    }
}
char assembleChar(){
    vector<bool> tempV;
    char buff = 0;
    char mask = -128;

    if (bufferVector.size() == 8){
        tempV = bufferVector;
        bufferVector.clear();
        for (auto item : tempV){
            if (item){
                buff = buff | mask;
            }
            mask = mask >> 1;
        }
        cout <<(int)buff << "\n";
        return buff;
    }
    else if (bufferVector.size() > 8){
        for (int i = 0; i < 8; i++){
            tempV[i] = bufferVector[i];
        }
        bufferVector.erase(bufferVector.begin(), bufferVector.begin() + 8);
        for (auto item : tempV){
            if (item){
                buff = buff | mask;
            }
            mask = mask >> 1;
        }
        cout << (int)buff << "\n";
        return buff;
    }
}
