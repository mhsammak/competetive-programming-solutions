#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    // Equation: (a.b) / gcd(a, b)
    // This divides a by gcd first to
    // avoid integer overflow.
    return a / gcd(a, b) * b;
}

int main() {
    
}