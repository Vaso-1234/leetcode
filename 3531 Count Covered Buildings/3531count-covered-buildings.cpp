#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> row, col;
        row.reserve(buildings.size()*2);
        col.reserve(buildings.size()*2);

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            row[x].insert(y);
            col[y].insert(x);
        }

        int covered = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            auto &rset = row[x];
            auto &cset = col[y];
            bool left  = (!rset.empty() && *rset.begin() < y);
            bool right = (!rset.empty() && *rset.rbegin() > y);
            bool above = (!cset.empty() && *cset.begin() < x);
            bool below = (!cset.empty() && *cset.rbegin() > x);

            if (left && right && above && below) covered++;
        }

        return covered;
    }
};
