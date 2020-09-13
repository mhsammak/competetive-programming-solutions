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
    return a / gcd(a, b) * b;
}

int gcdWithCoef(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return 1;
    }
    int x1, y1;
    int gcd = gcdWithCoef(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}

int main() {
    
}
