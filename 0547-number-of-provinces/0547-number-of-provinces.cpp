class Solution {
public:
    void dfs(int u, const vector<vector<int>>& isConnected, vector<char>& vis) {
        vis[u] = 1;
        int n = isConnected.size();
        for (int v = 0; v < n; ++v) {
            if (!vis[v] && isConnected[u][v]) dfs(v, isConnected, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 0) return 0;
        vector<char> vis(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++provinces;
                dfs(i, isConnected, vis);
            }
        }
        return provinces;
    }
};