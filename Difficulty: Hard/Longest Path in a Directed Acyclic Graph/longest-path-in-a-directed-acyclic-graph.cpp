class Solution {
  private:
    void topoSort(int node, vector<pair<int, int>> adj[], vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        for (auto& edge : adj[node]) {
            int v = edge.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> maxDistance(int V, int src, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list
        vector<pair<int, int>> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Step 2: Perform Topological Sort
        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Step 3: Initialize distances
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        // Step 4: Relax edges in topological order
        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (dist[u] != INT_MIN) {
                for (auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;

                    if (dist[u] + weight > dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        return dist;
    }
};