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

int totalEdges(adjMatrix matrix) {
    int total = 0;
    for (auto row: matrix) {
        for (auto col: row) {
            if (col) {
                total++;
            }
        }
    }
    return total;
}

int totalEdges(adjList list) {
    int total = 0;
    for (auto vertex: list) {
        total += vertex.size();
    }
    return total;
}

int totalEdges(edgeList edges) {
    return edges.size();
}

int inDegree(adjMatrix matrix, int u) {
    int degrees = 0;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][u]) {
            degrees += 1;
        }
    }
    return degrees;
}

int inDegree(adjList list, int u) {
    int degrees = 0;
    for (auto vertex: list) {
        for (auto edge: vertex) {
            if (edge.first == u) {
                degrees++;
            }
        }
    }
    return degrees;
}

int inDegree(edgeList edges, int u) {
    int degrees = 0;
    for (auto edge: edges) {
        if (edge.second.first == u) {
            degrees++;
        }
    }
    return degrees;
}

int outDegree(adjMatrix matrix, int u) {
    int degrees = 0;
    for (int edge: matrix[u]) {
        if (edge) {
            degrees++;
        }
    }
    return degrees;
}

int outDegree(adjList list, int u) {
    int degrees = 0;
    for (auto vertex: list) {
        degrees += vertex.size();
    }
    return degrees;
}

int outDegree(edgeList edges, int u) {
    int degrees = 0;
    for (auto edge: edges) {
        if (edge.first == u) {
            degrees++;
        }
    }
    return degrees;
}

adjMatrix transpose(adjMatrix matrix) {
    adjMatrix transposed(matrix.size(), vector<int>(matrix.size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

adjList transpose(adjList list) {
    adjList transposed(list.size());
    for (int i = 0; i < list.size(); i++) {
        for (auto edge: list[i]) {
            transposed[edge.first].push_back(make_pair(i, edge.second));
        }
    }
    return transposed;
}

edgeList transpose(edgeList edges) {
    edgeList transposed;
    for (auto edge: edges) {
        transposed.push_back(make_pair(edge.second.first, make_pair(edge.first, edge.second.second)));
    }
    return transposed;
}

bool isComplete(edgeList edges) {
    int _edges = totalEdges(edges);
    int vertices = totalVertices(edges);
    return _edges == (vertices * (vertices - 1)) / 2;
}

bool isComplete(adjMatrix matrix) {
    int edges = totalEdges(matrix);
    int vertices = totalVertices(matrix);
    return edges == (vertices * (vertices - 1)) / 2;
}

bool isComplete(adjList list) {
    int edges = totalEdges(list);
    int vertices = totalVertices(list);
    return edges == (vertices * (vertices - 1)) / 2;
}

bool _hasCycle(adjList list, int root, vector<bool> visited) {
   visited[root] = true;
   for (auto edge: list[root]) {
       if (visited[edge.first]) {
           return true;
       } else {
           _hasCycle(list, edge.first, visited);
       }
   }
   return false;
}

bool hasCycle(adjList list) {
    vector<bool> visited(list.size(), false);
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            return _hasCycle(list, i, visited);
        }
    }
}

void dfs(adjList list, int root, vector<bool> visited) {
    visited[root] = true;
    for (auto edge: list[root]) {
        if (!visited[edge.first]) {
            dfs(list, edge.first, visited);
        }
    }
}

bool isConnected(adjList list) {
    vector<bool> visited(list.size());
    int components = 0;
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            components++;
            dfs(list, i, visited);
        }
    }
    return components == 1;
}

bool isTree(adjList list) {
    if (hasCycle(list)) {
        return false;
    }
    if (!isConnected(list)) {
        return false;
    }
    return true;
}

bool isStarGraph(adjList list) {
    int vertices = list.size();
    int edges = totalEdges(list);
    if (edges / 2 != vertices - 1) {
        return false;
    }
    for (auto vertex: list) {
        if (vertex.size() > 1 && vertex.size() != vertices - 1) {
            return false;
        }
    }
    return true;
}

int main() {

}