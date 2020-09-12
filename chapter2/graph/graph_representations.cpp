#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Adjacency Matrix
// n x n matrix

typedef vector<vector<int>> adjMatrix;

// Adjancency List
// Vertex 1: {(to Vertex, Weight), ...}
// Vertex 2: {(to Vertex, Weight), ...}
// ...

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjList;

// Edge Lists
// (vertex, (to vertex, weight))
// (vertex, (to vertex, weight))
// ...

typedef vector<pair<int, ii>> edgeList;


adjList adjMatrixToAdjList(adjMatrix matrix) {
    adjList list(matrix.size());
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j]) {
                list[i].push_back(make_pair(j, 0));
            }
        }
    }
    return list;
}

adjMatrix adjListToAdjMatrix(adjList list) {
    adjMatrix matrix(list.size(), vector<int>(list.size(), 0));
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list[i].size(); j++) {
            matrix[i][list[i][j].first] = list[i][j].second;
        }
    }
    return matrix;
}

edgeList adjMatrixToEdgeList(adjMatrix matrix) {
    edgeList edges;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j]) {
                edges.push_back(make_pair(i, make_pair(j, matrix[i][j])));
            }
        }
    }
    return edges;
}

adjMatrix edgeListToAdjMatrix(edgeList edges, int V) {
    adjMatrix matrix(V, vector<int>(V, 0));
    for (auto edge: edges) {
        matrix[edge.first][edge.second.first] = edge.second.second;
    }
    return matrix;
}

adjList edgeListToAdjList(edgeList edges, int V) {
    adjList list(V);
    for (auto edge: edges) {
        list[edge.first].push_back(make_pair(edge.second.first, edge.second.second));
    }
    return list;
}

edgeList adjListToEdgeList(adjList list) {
    edgeList edges;
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list[i].size(); j++) {
            edges.push_back(make_pair(i, make_pair(list[i][j].first, list[i][j].second)));
        }
    }
    return edges;
}

int main() {
    
}
