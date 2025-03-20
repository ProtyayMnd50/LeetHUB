class Solution {
public:
    bool callBFS(int strt,vector<int>&color,vector<int>adj[]){
         queue<int>qu;
        color[strt]=1;
        qu.push(strt);
        while(!qu.empty()){
            int nd=qu.front();
            qu.pop();
            for(auto &x:adj[nd]){//traversing in its neighbours
                if(color[x]==-1){//unvisited
                    color[x]=!color[nd];
                    qu.push(x);
                }else{
                    if(color[x]==color[nd])
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        
        vector<int>color(n+1,-1);//-1 for unvisited, 1->for c1, 0->for c2
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                bool res=callBFS(i,color,adj);
                if(res==false)return false;
            }
        }
        return true;
    }
};