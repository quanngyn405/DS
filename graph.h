#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

const int INF = 999; 

vector<vector<int>> G1 = {
        {0, 4, 9, INF, 12, 2, 12, 2},
        {4, 0, 2, 3, 7, INF},
        {9, 2, 0, 6, 5, INF},
        {INF, 3, 6, 0, 3, 2},
        {12, 7, 5, 3, 0, 5},
        {2, INF, INF, 2, 5, 0}
    };

vector<vector<int>> G2 = {
        {0, 4, 9, INF, 12, 2},
        {4, 0, 2, 3, 7, INF},
        {9, 2, 0, 6, 5, INF},
        {INF, 3, 6, 0, 3, 2},
        {12, 7, 5, 3, 0, 5},
        {2, INF, INF, 2, 5, 0}
    };

vector<vector<int>> G3 = {
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 0, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 0, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, 0, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 0, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 0, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 0, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 0, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, 0, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 0, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 0, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 0, 9, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 0, INF, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, 0, 12, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 0, 2, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 0, INF, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, INF, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, 0, INF},
        {0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, 0, 4, 9, INF, 12, 2, INF, INF, 0},
    };

vector<vector<int>> G4 = {
        {0, 5, INF, 1, INF, 4},
        {INF, 0, -5, INF, INF, INF},
        {INF, INF, 0, 1, INF, 1},
        {INF, INF, INF, 0, 3, INF},
        {INF, 2, INF, INF, 0, INF},
        {INF, INF, INF, INF, 1, 0}
    };

vector<vector<int>> G5 = {
        {0, 5, INF, 1, INF, 3, INF, INF},
        {4, 0, 2, 3, 3, INF, INF, INF},
        {INF, 4, 0, INF, 2, INF, INF, 5},
        {2, 5, INF, 0, 4, INF, INF, INF},
        {INF, 3, 3, 4, 0, 2, 1, INF},
        {1, INF, INF, INF, 2, 0, 3, INF},
        {INF, INF, INF, INF, 1, 1, 0, 2},
        {INF, INF, 1, INF, INF, INF, 4, 0},
    };