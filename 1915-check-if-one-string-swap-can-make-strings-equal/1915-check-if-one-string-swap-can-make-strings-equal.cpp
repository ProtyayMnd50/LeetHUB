class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<pair<char,char>,int>mp;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                mp[{s1[i],s2[i]}]++;
            }
        }
        int cnt=0;
        for(auto &x:mp){
            char c1=x.first.first;
            char c2=x.first.second;   
            cout<<c1<<", "<<c2<<"->"<<x.second<<endl;

            if(mp[{c1,c2}]==mp[{c2,c1}])
            cnt+=x.second;
        }
        cout<<cnt<<endl;
        return ( (cnt==2 && mp.size()==2)||mp.empty())?true:false;
    }
};