#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int ll;

vector<bool> segmetSieve(ll L, ll R) {
    ll sq = sqrt(R);
    vector<bool> mark(sq + 1, false);
    vector<ll> primes;

    for (ll i = 2; i <= sq; i++) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= sq; j += i) {
                mark[j] = true;
            }
        }
    }

    vector<bool> isPrime(L - R + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            isPrime[j - L] = false;
        }

    if (L == 1) {
        isPrime[0] = false;
    }

    return isPrime;
}

int main() {
    
}