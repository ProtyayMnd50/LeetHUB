class Solution {
public:
    void bfs(int source,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&path) {
        queue<int> qu;
        visited[source] = true;
        qu.push(source);
        path.push_back(source);

        while (!qu.empty()) {
            int nd = qu.front();
            qu.pop();

            for (auto& x : adj[nd]) { // going in adjacent nodes for traversal
                if (visited[x] == false) {
                    visited[x] = true;
                    qu.push(x);
                    path.push_back(x);
                }
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n); // vector of empty vectors

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> path;
        vector<bool> visited(n, false); // initially all are unvisited

        bfs(source,adj,visited,path);

        auto it=find(path.begin(),path.end(),destination);

        return (it==path.end())?false:true;
    }
};