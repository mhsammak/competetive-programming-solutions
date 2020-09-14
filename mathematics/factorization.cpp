#include <cstdio>
#include <cmath>
#include <vector>
#include <array>

using namespace std;

typedef long long int ll;

vector<ll> getFactors(ll n) {
    vector<ll> factors;
    for (ll i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

vector<ll> factorsOptimized(ll n) {
    vector<ll> factors;
    for (int d: {2, 3, 5}) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> inc = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (ll d = 7; d <= sqrt(n); d += inc[i]) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    vector<ll> factors = factorsOptimized(52);
    for (auto i: factors) {
        printf("%lld\n", i);
    }
}