#include <iostream>
#include <string>
using namespace std;

void naiveSearch(string t, string p) {
    int n = t.size();
    int m = p.size();
    
    for (int i = 0; i < n - m + 1; i++) {
        bool found = true;
        for (int j = 0; j < m && found; j++) {
            if (t[i + j] != p[j]) {
                found = false;
            }
        }
        if (found) {
            cout << "Found pattern at index " << i << endl;
        }
    }
}

int main() {

}