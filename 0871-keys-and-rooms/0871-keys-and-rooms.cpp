class Solution {
public:
    void bfs(int start,vector<bool>&vis,vector<vector<int>>& rooms){
        vis[start]=true;
        queue<int>qu;
        qu.push(start);
        while(!qu.empty()){
            int fr=qu.front();
            qu.pop();
            for(auto &x:rooms[fr]){
                if(!vis[x]){
                    vis[x]=true;
                    qu.push(x);
                }
            }

        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);

        bfs(0,vis,rooms);

        for(int i=0;i<n;i++){
            if(vis[i]==false)return false;
        }
        return true;
    }
};