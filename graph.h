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
/* A */        {0, 2, 4, 1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
/* B */        {2, 0, 3, INF, 1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
/* C */        {4, 3, 0, INF, 2, 2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
/* D */        {1, INF, INF, 0, INF, 5, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
/* E */        {INF, 1, 2, INF, 0, INF, INF, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
/* F */        {INF, INF, 2, 5, INF, 0, 3, 3, 2, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
/* G */        {INF, INF, INF, 4, INF, 3, 0, INF, INF, INF, 2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
/* H */        {INF, INF, INF, INF, 3, 3, INF, 0, INF, INF, INF, 1, INF, INF, 8, INF, INF, INF, INF, INF, INF},
/* I */        {INF, INF, INF, INF, INF, 2, INF, INF, 0, 3, INF, 3, 2, INF, INF, INF, INF, INF, INF, INF, INF},
/* J */        {INF, INF, INF, INF, INF, 4, INF, INF, 3, 0, 6, INF, 6, 3, INF, INF, INF, INF, INF, INF, INF},
/* K */        {INF, INF, INF, INF, INF, INF, 2, INF, INF, 6, 0, INF, INF, 4, INF, INF, INF, 2, INF, INF, INF},
/* L */        {INF, INF, INF, INF, INF, INF, INF, 1, 3, INF, INF, 0, 3, INF, 6, INF, INF, INF, INF, INF, INF},
/* M */        {INF, INF, INF, INF, INF, INF, INF, INF, 2, 6, INF, 3, 0, 5, 4, 2, INF, INF, INF, INF, INF},
/* N */        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, 4, INF, 5, 0, INF, INF, 2, 1, INF, INF, INF},
/* O */        {INF, INF, INF, INF, INF, INF, INF, 8, INF, INF, INF, 6, 5, INF, 0, 2, INF, INF, 6, INF, INF},
/* P */        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2, INF, 2, 0, 1, INF, 2, INF, INF},
/* Q */        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2, INF, 1, 0, 8, INF, 3, INF},
/* R */        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2, INF, INF, 1, INF, INF, 8, 0, INF, 5, INF},
/* S */        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 6, 2, INF, INF, 0, INF, 2},
/* T */        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1, 3, 5, INF, 0, 8},
/* Z */        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2, 8, 0},
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