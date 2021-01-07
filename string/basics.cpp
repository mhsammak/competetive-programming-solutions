#include <iostream>
#include <fstream>
#include <string>
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
}