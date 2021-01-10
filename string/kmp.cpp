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
    return lps;
}

void kmpSearch(string t, string p) {
    vector<int> lps = getLps(&p);
    
    int n = t.size();
    int m = p.size();
    int i = 0;
    int j = 0;
    bool found = false;

    while (i < n) {
        if (t[i] == p[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if (j == m) {
            found = true;
            cout << "Found match at " << i - m << endl;
            j = lps[j - 1];
        }
    }

    if (!found) {
        cout << "No match found!" << endl;
    }
}

int main() {

}