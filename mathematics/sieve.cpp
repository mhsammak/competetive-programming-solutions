#include <cstdio>
#include <vector>

using namespace std;

void makeSieve(vector<char>& sieve) {
    sieve[0] = false;
    sieve[1] = false;
    int size = sieve.size();

    for (int i = 2; i <= size; i++) {
        if (sieve[i] && (long long) i * i <= size) {
            for (int j = i * i; j <= size; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    vector<char> sieve(50, true);
    makeSieve(sieve);
    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i]) {
            printf("%d ", i);
        }
    }
}