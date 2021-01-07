#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    string T = "";
    bool firstLine = true;
    
    ifstream file("input.txt");

    while (getline(file, line)) {
        if (line.size() >= 7 && line.substr(0, 7) == ".......") {
            break;
        }

        if (firstLine) {
            T += line;
            firstLine = false;
        } else {
            T = T + " " + line;
        }
    }

    string P = "Some substring";
    vector<int> pos;
    int start = 0;
    int idx;
    while ((idx = T.find(P, start)) != -1) {
        pos.push_back(idx);
        start = idx;
    }

    const char *cstr = T.data();
    
    char *vwl = "aeiou";
    char *cnt = "bcdfghjklmnpqrstvwxyz";
    int digits = 0;
    int vowels = 0;
    int consnents = 0;

    for (int i = 0; i < T.size(); i++) {
        if (isdigit(T.at(i))) {
            digits++;
        } else if (strchr(vwl, T.at(i)) != NULL) {
            vowels++;
        } else if (strchr(cnt, T.at(i)) != NULL) {
            consnents++;
        }
    }

    vector<string> tokens;
    map<string, int> tokenFreq;
    char *t = new char[T.size() + 1];
    strcpy(t, T.c_str());
    for (p = strtok(t, " ."); p; p = strtok(NULL, " .")) {
        tokens.push_back(p);
        tokenFreq[p]++;
    }

}