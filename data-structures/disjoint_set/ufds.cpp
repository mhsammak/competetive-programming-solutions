#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
    vi parents;
    vi ranks;
    int components;
public:
    UnionFind(int n) {
        parents.assign(n, 0);
        for (int i = 0; i < parents.size(); i++) {
            parents[i] = i;
        }
        ranks.assign(n, 1);
        components = n;
    }

    int parent(int node) {
        if (parents[node] == node) {
            return node;
        } else {
            return parents[node] = parent(parents[node]);
        }
    }

    bool isConnected(int node1, int node2) {
        return parent(node1) == parent(node2);
    }

    void connect(int node1, int node2) {
        if (isConnected(node1, node2)) {
            return;
        }

        int parent1 = parent(node1);
        int parent2 = parent(node2);

        if (ranks[parent1] > ranks[parent2]) {
            parents[parent2] = parent1;
            ranks[parent1] += ranks[parent2];
        } else {
            parents[parent1] = parent2;
            ranks[parent2] += ranks[parent1];
        }
        components--;
    }

    int totalComponents() {
        return components;
    }

    int sizeOfComponent(int node) {
        return ranks[parent(node)];
    }
};

int main() {

}