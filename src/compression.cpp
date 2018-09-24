#include "compression.h"
#include "huffmanTree.h"

using namespace std;

map<char, unsigned long> byteTable;
union mask {
    char letter;
    struct {
        unsigned a0 : 1;
        unsigned a1 : 1;
        unsigned a2 : 1;
        unsigned a3 : 1;
        unsigned a4 : 1;
        unsigned a5 : 1;
        unsigned a6 : 1;
        unsigned a7 : 1;
    } byte;
};

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
    //char buff = 0;
    //char mask = -128;
    mask mask;

    mask.byte.a0 = bufferVector[0] & 1;
    mask.byte.a1 = bufferVector[1] & 1;
    mask.byte.a2 = bufferVector[2] & 1;
    mask.byte.a3 = bufferVector[3] & 1;
    mask.byte.a4 = bufferVector[4] & 1;
    mask.byte.a5 = bufferVector[5] & 1;
    mask.byte.a6 = bufferVector[6] & 1;
    mask.byte.a7 = bufferVector[7] & 1;

    bufferVector.erase(bufferVector.begin(), bufferVector.begin() + 8);
    return mask.letter;

   /* if (bufferVector.size() == 8){
        for (int i = 0; i < 8; i++){
            if (bufferVector[i]){
                buff = buff | mask;
            }
            mask = mask >> 1;
        }
        bufferVector.clear();
        return buff;
    }
    else if (bufferVector.size() > 8){
        for (int i = 0; i < 8; i++){
            if (bufferVector[i]){
                buff = buff | mask;
            }
            mask = mask >> 1;
        }
        bufferVector.erase(bufferVector.begin(), bufferVector.begin() + 8);
        return buff;
    }*/
}
