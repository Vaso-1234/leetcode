class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        unordered_set<int> knows;
        knows.insert(0);
        knows.insert(firstPerson);

        int i = 0;
        int m = meetings.size();

        while (i < m) {
            int time = meetings[i][2];

            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;

            while (i < m && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }

            queue<int> q;
            unordered_set<int> visited;

            for (int p : people) {
                if (knows.count(p)) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }

            for (int p : visited) {
                knows.insert(p);
            }
        }

        return vector<int>(knows.begin(), knows.end());
    }
};
