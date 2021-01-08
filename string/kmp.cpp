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

void kmpProcess(int *table, string *p) {
    int m = p->size();
    int i = 0;
    int j = -1;
    table[0] = -1;

    while (i < m) {
        while (j >= 0 && p[i] != p[j]) {
            j = table[j];
        }
        i++;
        j++;
        table[i] = j;
    }
}

void kmpSearch(string t, string p) {
    int table[p.size()];
    kmpProcess(table, &p);

}

int main() {

}