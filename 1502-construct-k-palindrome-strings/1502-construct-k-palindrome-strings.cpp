class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()==k)return true;
        if(s.size()<k)return false;

        unordered_map<char,int>mp;
        for(auto &x:s)
        mp[x]++;

        int odf=0;//odd frequencies
        for(auto &x:mp){
            if(x.second&1)odf++;
        }
        
        return (k>=odf)? true: false;


    }
};