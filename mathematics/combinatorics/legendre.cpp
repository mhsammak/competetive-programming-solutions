#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int ll;

/**
 * Finds the highest power of prime k
 * in factorial of n.
 * */
ll powerOfPrime(ll n, ll k) {
    ll count = 0;
    ll _k = k;
    while (_k <= n) {
        count += (n / _k);
        _k *= k;
    }
    return count;
}

/**
 * Returns prime factors of k along with their occurances.
 * */
vector<pair<ll, int>> factors(ll k) {
    vector<pair<ll, int>> factor;
    for (ll f: {2, 3, 5}) {
        int count = 0;
        while (k % f == 0) {
            k /= f;
            count += 1;
        }
        if (count) {
            factor.push_back(make_pair(f, count));
        }
    }

    static array<int, 8> inc = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;

    for (ll f = 7; f <= sqrt(k); f += inc[i++]) {
        int count = 0;
        while (k % f == 0) {
            k /= f;
            count += 1;
        }
        if (count) {
            factor.push_back(make_pair(f, count));
        }
        if (i == 8) {
            i = 0;
        }
    }

    if (k > 1) {
        factor.push_back(make_pair(k, 1));
    }
    return factor;
}

/**
 * Finds the largest power of composite k
 * in the factorial of n.
 * */
int largestPowerK(ll n, ll k) {
    vector<pair<ll, int>> factor = factors(k);
    ll largest = INTMAX_MAX;
    for (auto f: factor) {
        largest = min(largest, powerOfPrime(n, f.first) / f.second);
    }
    return largest;
}

int main() 
{ 
    cout << largestPowerK(7, 2) << endl; 
    cout << largestPowerK(10, 9) << endl; 
    return 0; 
} 