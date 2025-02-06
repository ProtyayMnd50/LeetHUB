class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        map<pair<char,char>,int>mp;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                mp[{s1[i],s2[i]}]++;
            }
        }
        if(mp.empty())return true;
        else if(mp.size()==2){
            for(auto &x:mp){
                char fe=x.first.first;
                char se=x.first.second;
                if(mp[{fe,se}]==1&&mp[{se,fe}]==1)return true;
                else return false;
            }
        }else
        return false;

        return true;
    }
};