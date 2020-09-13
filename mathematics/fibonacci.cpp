#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> fib(int n) {
    if (n == 0) {
        return {0, 1};
    }
    
    pair<int, int> f = fib(n >> 1);
    
    int c = f.first * (2 * f.second - f.first);
    int d = f.first * f.first + f.second * f.second;

    if (n & 1) {
        return {d, c + d};
    } else {
        return {c, d};
    }
}

int main() {
    printf("%d\n", fib(11));
}