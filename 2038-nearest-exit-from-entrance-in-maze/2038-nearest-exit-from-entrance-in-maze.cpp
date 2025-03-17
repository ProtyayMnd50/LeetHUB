#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();

        // cout<<n<<" "<<m<<"\n";
         vector<vector<int>>visited(n,vector<int>(m,0));      
         queue<pair<pair<int,int>,int>>qu;
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};      
        int sr=entrance.front();
        int sc=entrance.back();
         qu.push({{sr,sc},0});
         visited[sr][sc]=1;
            
        int ans=INT_MAX;

         while(qu.empty()==false){
            pair<int,int>pr=qu.front().first;
            int prevdist=qu.front().second;
            int cr=pr.first;
            int cc=pr.second;
            //   if((cr==0||cr==(n-1)||cc==0||cc==(m-1))&&maze[cr][cc]=='.' && !(cr==sr && cc==sc)){         
            //     cout<<prevdist<<"\n";
            //     ans=min(ans,prevdist);
            // }
            qu.pop();      
            for(int i=0;i<4;i++){
                int nr=cr+dx[i];
                int nc=cc+dy[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&visited[nr][nc]==0&&maze[nr][nc]=='.'){
                    visited[nr][nc]=1;
                    qu.push({{nr,nc},prevdist+1});
                    if(nr==0||nc==0||nr==(n-1)||nc==(m-1))
                    ans=min(ans,(prevdist+1));
                    
                }
            }
       
         }
     cout<<ans<<endl;

     for(auto &x:visited){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
     }
    return (ans==INT_MAX) ? -1 : ans;
    }
};