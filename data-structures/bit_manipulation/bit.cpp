#include <iostream>
using namespace std;

int setBit(int bits, int j) {
    return bits & (1 << j);
}

bool bitIsSet(int bits, int j) {
    return bits & (1 << j) != 0;
}

int clearBit(int bits, int j) {
    return bits & ~(1 << j);
}

int toggleBit(int bits, int j) {
    return bits ^ (1 << j);
}

int createSetBits(int n) {
    return (1 << n) - 1;
}

int main() {

}