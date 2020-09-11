#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int cases = 0;
    char containers[1500];
    
    while (gets(containers) && strcmp(containers, "end") != 0) {
        vector<stack<char>> stacks;
        cases++;
        
        int n = strlen(containers);
        int ways = 0;
        
        for (int i = 0; i < n; i++) {
            bool loaded = false;
            for (int j = 0; j < stacks.size(); j++) {
                if (containers[i] <= stacks[j].top()) {
                    stacks[j].push(containers[i]);
                    loaded = true;
                    break;
                }
            }

            if (!loaded) {
                stack<char> nex_stack;
                stacks.push_back(nex_stack);
                stacks[stacks.size() - 1].push(containers[i]);
                ways++;
            }
        }
        printf("Case %d: %d\n", cases, ways);
    }
}