// Maximum Cardinality Bipartite Matching
// Worst case O(nm)

struct Graph {
    vector<vector<int>> G;
    vector<int> match, vis;

    void init(int n) {
        G = vector<vector<int>>(n);
    }
    bool dfs(int u) {
        for (int v : G[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    int solve() {
        int res = 0;
        fill(match.begin(), match.end(), -1);
        for (int i = 0; i < (int)G.size(); i++) {
            if (match[i] == -1) {
                fill(vis.begin(), vis.end(), 0);
                if (dfs(i)) res++;
            }
        }
        return res;
    }
} graph;
