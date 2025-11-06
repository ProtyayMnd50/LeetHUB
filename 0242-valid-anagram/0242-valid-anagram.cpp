class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto &x:s){
            mp1[x]++;
        }
        for(auto &x:t){
            mp2[x]++;
        }
        if(mp1.size()!=mp2.size()){
            return false;
        }else{
            vector<pair<char,int>>p1;
            vector<pair<char,int>>p2;
            for(auto &x:mp1){
                p1.push_back({x.first,x.second});
            }
            for(auto &x:mp2){
                p2.push_back({x.first,x.second});
            }
            bool res=true;
            for(int i=0;i<mp1.size();i++){
                if(p1[i].first==p2[i].first&&p1[i].second==p2[i].second){

                }else{
                    res=false;
                    break;
                }

            }
            return res;
        }    
    }
};