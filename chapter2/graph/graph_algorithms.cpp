#include "./graph_representations.cpp"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int totalVertices(adjMatrix matrix) {
    return matrix.size();
}

int totalVertices(adjList list) {
    return list.size();
}

int totalVertices(edgeList edges) {
    return edges.size();
}

int main() {

}