class Solution {
public:
    void bfs(int source,vector<int>&path,vector<bool>&visited,vector<vector<int>>&adj){

        queue<int>qu;
        qu.push(source);
        path.push_back(source);
        visited[source]=true;

        while(!qu.empty()){
            int nd=qu.front();
            qu.pop();

            for(auto &x:adj[nd]){
                if(!visited[x]){
                    visited[x]=true;
                    qu.push(x);
                    path.push_back(x);
                }
            }
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>path;
        vector<bool>visited(n,false);
        //constructing the adjacency list

        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bfs(source,path,visited,adj);

        auto it=find(path.begin(),path.end(),destination);
        bool fl=true;
        if(it==path.end())
        fl=false;

        return fl;

    }
};