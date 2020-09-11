#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int i, int j) {
    return i > j;
}

int main() {
    int cases;
    scanf("%d", &cases);
    
    while (cases) {
        int n, m, p;
        deque<pair<int, int>> d;
        vector<int> v;

        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p);
            d.push_back(make_pair(i, p));
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp);

        int minutes = 0;
        int current = 0;
        while (!d.empty()) {
            pair<int, int> item = d.front();
            d.pop_front();

            if (item.second == v[current]) {
                minutes++;
                current++;
                if (item.first == m) {
                    break;
                }
            } else {
                d.push_back(item);
            }
        }
        printf("%d\n", minutes);
        cases--;
    }
}   