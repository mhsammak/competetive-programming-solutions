#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int ll;

ll binpow(ll b, ll p, ll m) {
    b %= m;
    ll result = 1;
    while (p > 0) {
        if (p % 2) {
            result = result * b % m;
        }
        b = b * b % m;
        p /= 2;
    }
    return result;
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isProbablyPrime(int n, int iter = 5) {
    if (n < 4) {
        return (n == 2) || (n == 3);
    } else {
        for (int i = 0; i < iter; i++) {
            int a = (2 + rand()) % (n - 3);
            if (binpow(a, n - 1, n) != 1) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    if (isProbablyPrime(17)) {
        printf("Prime\n");
    } else {
        printf("Not Prime\n");
    }
}
