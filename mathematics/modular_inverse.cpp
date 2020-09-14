#include "./euclidean_gcd.cpp"

#include <cstdio>
#include <cmath>

int getInverse(int a, int m) {
    int x, y;
    int g = gcdWithCoef(a, m, x, y);
    if (g != 1) {
        return 0;
    } else {
        x = (x % m + m) % m;
        return x;
    }
}

int main() {
    
}