#include <iostream>
#include <string>
#include <vector>
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

vector<int> getLps(const string *p) {
    vector<int> lps(p->length());
    int idx = 0;

    for (int i = 1; i < p->length(); ) {
        if (p->at(idx) == p->at(i)) {
            lps[i] = idx + 1;
            idx++;
            i++;
        } else {
            if (idx != 0) {
                idx = lps[idx - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(string t, string p) {
    int table[p.size()];
    kmpProcess(table, &p);
    
    int n = t.size();
    int m = p.size();
    int i = 0;
    int j = 0;

    while (i < n) {
        while (j >= 0 && t[i] != p[j]) {
            j = table[j];
        }
        i++;
        j++;
        if (j == m) {
            cout << "Found pattern at index " << i - j << endl;
            j = table[j];
        }
    }
}

int main() {

}