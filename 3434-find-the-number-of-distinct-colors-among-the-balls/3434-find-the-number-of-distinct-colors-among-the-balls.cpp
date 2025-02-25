class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>balls;//konsa color ith ball pe (ball is the key)
        map<int,int>color;//ek color kitne balls pe laga hai
        vector<int>res;
        for(auto &x:queries){
            int bl=x[0];
            int cl=x[1];
            int prevcol=balls[bl];//previous color on the ball that existed
            if(color[prevcol])color[prevcol]--;//if conflicting color
            if(!color[prevcol])color.erase(prevcol);//color not coloring any ball
            balls[bl]=cl;
            color[cl]++;
            res.push_back(color.size());
        }

        for(auto &x:res)
        cout<<x<<" ";
        return res;

        
    }
};