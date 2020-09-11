#include <iostream>
#include <list>

using namespace std;

list<char> lists;
string text;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> text) {
        lists.clear();

        list<char>::iterator it = lists.begin();
        for (char c: text) {
            if (c == '[') {
                it = lists.begin();
            } else if (c == ']') {
                it = lists.end();
            } else {
                lists.insert(it, c);
            }
        }

        for (auto it = lists.begin(); it != lists.end(); ++it) {
            cout << *it;
        }
        cout << '\n';
    }
    
    return 0;
}
    