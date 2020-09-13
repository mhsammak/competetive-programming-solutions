#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> array;
    int n;
    
    int left(int node) {
        return node << 1;
    }

    int right(int node) {
        return (node << 1) + 1;
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > j) {
            return INFINITY;
        }
        if (L == i && R == j) {
            return tree[p];
        }  
        int mid = (L + R) / 2;
        int p1 = rmq(left(p), L, mid, i, min(mid, j));
        int p2 = rmq(right(p), mid + 1, R, max(mid + 1, i), j);

        if (p1 == INFINITY) return p2;
        if (p2 == INFINITY) return p1;
        return (array[p1] <= array[p2]) ? p1 : p2; 
    }

    int rsq(int p, int L, int R, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (L == i || R == j) {
            return tree[p];
        }
        int mid = (L + R) / 2;
        int p1 = rsq(left(p), L, mid, i, min(mid, j));
        int p2 = rsq(right(p), mid + 1, R, max(mid + 1, i), j);
        return array[p1] + array[p2];
    }

    void update(int root, int L, int R, int index, int val) {
        if (L == R) {
            tree[root] = val;
        } else {
            int mid = (L + R) / 2;
            if (index <= mid) {
                update(left(root), L, mid, index, val);
            } else {
                update(right(root), mid + 1, R, index, val);
            }
            tree[root] = tree[left(root)] + tree[right(root)];
        }
    }
public:
    SegmentTree(const vector<int> &a) {
        array = a;
        n = a.size();
        tree.assign(4 * n, 0);
    }

    void build_min(int root, int L, int R) {
        if (L == R) {
            tree[root] = L;
        } else {
            build_min(left(root), L, (L + R) / 2);
            build_min(right(root), ((L + R) / 2) + 1, R);

            int p1 = tree[left(root)]; 
            int p2 = tree[right(root)];
            tree[root] = (array[p1] <= array[p2]) ? p1 : p2;
        }
    }

    void build_sum(int root, int L, int R) {
        if (L == R) {
            tree[root] = L;
        } else {
            build_sum(left(root), L, (L + R) / 2);
            build_sum(right(root), ((L + R) / 2) + 1, R);

            int p1 = tree[left(root)]; 
            int p2 = tree[right(root)];
            tree[root] = array[p1] + array[p2];
        }
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j);
    }

    int rsq(int i, int j) {
        return rsq(1, 0, n - 1, i, j);
    }

    void update(int index, int val) {
        update(1, 0, n - 1, index, val);
    }
};

int main() {

}