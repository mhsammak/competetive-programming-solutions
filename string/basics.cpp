#include <iostream>
#include <fstream>
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
}