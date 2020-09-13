#include <cstdio>
using namespace std;

typedef long long int ll;

int main() {
    ll b, p, m;
    while(scanf("%lld %lld %lld", &b, &p, &m) != EOF) {
        b = b % m;
        ll result = 1;
        
        while (p > 0) {
            if (p & 1) {
                result = result * b % m;
            }
            b = b * b % m;
            p >>= 1;
        }
        printf("%lld\n", result);
    } 
}
