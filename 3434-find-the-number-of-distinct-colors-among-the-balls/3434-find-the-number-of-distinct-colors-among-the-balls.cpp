class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>balls;//konsa color ith ball pe (ball is the key)
        map<int,vector<int>>color;//konsa ball is colored by color i(color is the key)
        vector<int>res;
        for(auto &x:queries){
            int bl=x[0];
            int cl=x[1];
            int prevcol=balls[bl];//previous color on the ball
            if(color[prevcol].size())color[prevcol].pop_back();
            if(color[prevcol].size()==0)color.erase(prevcol);
            balls[bl]=cl;
            color[cl].push_back(bl);
            res.push_back(color.size());
        }

        for(auto &x:res)
        cout<<x<<" ";
        return res;

        
    }
};