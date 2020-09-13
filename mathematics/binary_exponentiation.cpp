#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int ll;

ll power_recursive(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll res = power_recursive(a, b / 2);
    res = res * res;
    if (b % 2) {
        res = res * a;
    }
    return res;
}

ll power_iterative(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b % 2) {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}

int main() {
    cout << power_recursive(2, 4) << endl;    
}
