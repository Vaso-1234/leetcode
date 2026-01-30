class Solution {
public:
    static constexpr long long INF = 1e18;

    struct Trie {
        int id;
        int next[26];
        Trie() : id(-1) {
            memset(next, -1, sizeof(next));
        }
    };

    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        int n = source.size();
        int m = original.size();

        // Map all strings to ids
        unordered_map<string,int> id;
        int idx = 0;
        for (int i = 0; i < m; i++) {
            if (!id.count(original[i])) id[original[i]] = idx++;
            if (!id.count(changed[i]))  id[changed[i]]  = idx++;
        }

        int K = idx;
        vector<vector<long long>> dist(K, vector<long long>(K, INF));
        for (int i = 0; i < K; i++) dist[i][i] = 0;

        for (int i = 0; i < m; i++) {
            dist[id[original[i]]][id[changed[i]]] =
                min(dist[id[original[i]]][id[changed[i]]],
                    (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < K; k++)
            for (int i = 0; i < K; i++)
                for (int j = 0; j < K; j++)
                    dist[i][j] = min(dist[i][j],
                        dist[i][k] + dist[k][j]);

        // Build trie for original
        vector<Trie> trieO(1);
        for (auto& s : original) {
            int node = 0;
            for (char c : s) {
                int x = c - 'a';
                if (trieO[node].next[x] == -1) {
                    trieO[node].next[x] = trieO.size();
                    trieO.emplace_back();
                }
                node = trieO[node].next[x];
            }
            trieO[node].id = id[s];
        }

        // Build trie for changed
        vector<Trie> trieC(1);
        for (auto& s : changed) {
            int node = 0;
            for (char c : s) {
                int x = c - 'a';
                if (trieC[node].next[x] == -1) {
                    trieC[node].next[x] = trieC.size();
                    trieC.emplace_back();
                }
                node = trieC[node].next[x];
            }
            trieC[node].id = id[s];
        }

        // DP
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            int nodeO = 0, nodeC = 0;
            for (int j = i; j < n; j++) {
                int a = source[j] - 'a';
                int b = target[j] - 'a';

                if (nodeO == -1 || nodeC == -1) break;

                nodeO = trieO[nodeO].next[a];
                nodeC = trieC[nodeC].next[b];

                if (nodeO == -1 || nodeC == -1) break;

                if (trieO[nodeO].id != -1 && trieC[nodeC].id != -1) {
                    long long c =
                        dist[trieO[nodeO].id][trieC[nodeC].id];
                    if (c < INF)
                        dp[i] = min(dp[i], c + dp[j + 1]);
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};
