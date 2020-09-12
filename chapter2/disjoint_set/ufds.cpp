#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int parent(vi parents, int node) {
    if (parents[node] == node) {
        return node;
    } else {
        return parents[node] = parent(parents, parents[node]);
    }
}

bool isConnected(vi parents, int node1, int node2) {
    return parent(parents, node1) == parent(parents, node2);
}

void connect(vi parents, vi ranks, int node1, int node2) {
    if (isConnected(parents, node1, node2)) {
        return;
    }

    int parent1 = parent(parents, node1);
    int parent2 = parent(parents, node2);

    if (ranks[parent1] > ranks[parent2]) {
        parents[parent2] = parent1;
        ranks[parent1] += ranks[parent2];
    } else {
        parents[parent1] = parent2;
        ranks[parent2] += ranks[parent1];
    }
}

int main() {

}