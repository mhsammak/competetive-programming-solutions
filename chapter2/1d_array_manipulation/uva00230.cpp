#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<string, string>> books;
map<string, bool> borrowed;
map<string, bool> returned;

int main() {
    char author[80];
    char title[80];

    while (scanf("\"%[^\"]\" by %[^\n]\n", title, author)) {
        books.push_back(make_pair(author, title));
        borrowed[title] = 0;
        returned[title] = 0;
    }
    scanf("%s", title);
    sort(books.begin(), books.end());

    while (scanf("%s ", title)) {
        string task(title);
        if (task == "END") {
            break;
        } else if (task == "SHELVE") {
            string current_book = "";
            for (auto book: books) {
                if (!borrowed[book.second]) {
                    current_book = book.second;
                } else if (returned[book.second]) {
                    if (current_book.length()) {
                        printf("Put \"%s\" after \"%s\"\n", book.second.c_str(), current_book.c_str());
                    } else {
                        printf("Put \"%s\" first\n", book.second.c_str());
                    }
                    borrowed[book.second] = 0;
                    current_book = book.second;
                }
            }
            printf("END\n");
            returned.clear();
            continue;
        } else {
            scanf("\"%[^\"]\"\n", title);
            if (task == "BORROW") {
                borrowed[title] = 1;
            } else if (task == "RETURN") {
                returned[title] == 1;
            }
        }
    }
    return 0;
}