#include "compression.h"
#include "huffmanTree.h"

using namespace std;

char assembleChar(){
    auto mask = new(byte);

    mask->bit.a0 = bufferVector[0] & 1;
    mask->bit.a1 = bufferVector[1] & 1;
    mask->bit.a2 = bufferVector[2] & 1;
    mask->bit.a3 = bufferVector[3] & 1;
    mask->bit.a4 = bufferVector[4] & 1;
    mask->bit.a5 = bufferVector[5] & 1;
    mask->bit.a6 = bufferVector[6] & 1;
    mask->bit.a7 = bufferVector[7] & 1;

    bufferVector.erase(bufferVector.begin(), bufferVector.begin() + 8);
    return mask->letter;
}
