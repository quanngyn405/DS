#include "graph.h"

using namespace std;
using namespace std::chrono;

void floydWarshall(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;
    vector<vector<int>> next(V, vector<int>(V, -1));

    // Initialize the next matrix for path reconstruction
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] != INF && i != j) {
                next[i][j] = j;
            }
        }
    }

    //? Start timing: O(n^3)
    auto start = high_resolution_clock::now();

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
        //! For report
        //! cout << "\nA^"<< k + 1 << endl;
        //! for (int i = 0; i < V; ++i) {
        //!     for (int j = 0; j < V; ++j) {
        //!         cout << dist[i][j] << " ";
        //!     }
        //!     cout << endl;
        //! }
    }

    //? Stop timing
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            cout << "Graph contains a negative cycle" << endl;
            return;
        }
    }

    // Print shortest distances and paths starting from A (index 0)
    int startVertex = 0; //& start from A
    cout << "Shortest distances from vertex A:\n";
    for (int j = 0; j < V; ++j) {
        if (dist[startVertex][j] == INF)
            cout << "A -> " << char('A' + j) << ": INF\n";
        else
            cout << "A -> " << char('A' + j) << ": " << dist[startVertex][j] << "\n";
    }

    /* cout << "\n";
    for(int i = 0; i < V; ++i) {
        for(int j = 0 ; j < V; ++j) {
            cout << next[i][j] << " ";
        }
        cout << "\n";
    } */

    cout << "\nPaths from vertex A:\n";
    for (int j = 0; j < V; ++j) {
        if (startVertex != j) {
            if (next[startVertex][j] == -1) { 
                cout << "No path from A to " << char('A' + j) << endl;
            } else {
                cout << "Path from A to " << char('A' + j) << ": ";
                int u = startVertex;
                while (u != j) {
                    cout << char('A' + u) << " -> ";
                    u = next[u][j];
                }
                cout << char('A' + j) << endl;
            }
        }
    }

    cout << "\nTime taken by Floyd-Warshall algorithm: " << duration.count() << " microseconds" << endl;
}

int main() {
    floydWarshall(G2);
    return 0;
}
