#include <iostream>
#include <cstdio>

using namespace std;

int n, r, c, k;
int kingdom[105][105];
int temp[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void fight() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[i][j] = kingdom[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= r || y < 0 || y >= c) {
                    continue;
                }
                if (temp[i][j] && temp[x][y] + 1 == temp[i][j]) {
                    kingdom[i][j] = temp[x][y];
                    break;
                }
                if (!temp[i][j] && temp[x][y] == n - 1) {
                    kingdom[i][j] = n - 1;
                    break;
                }
            }
        }
    }
}

int main() {
    while (scanf("%d %d %d %d", &n, &r, &c, &k)) {
        if (n == 0 && r == 0 && c == 0 & k == 0) {
            break;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> kingdom[i][j];
            }
        }
        while (k--) {
            fight();
        }
        for(int i=0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if (j) {
                    printf(" ");
                }
                printf("%d", kingdom[i][j]);
            }
            printf("\n");
        }
    }
}