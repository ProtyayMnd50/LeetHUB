class Solution {
#define ll long long
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        unordered_set<int>st;
        ll tot=0;
        for(int i=0;i<(n/2);i++){
            st.insert(skill[i]+skill[n-1-i]);
            ll chem=1LL*skill[i];
            chem*=skill[n-1-i];
            tot+=chem;
        }
        if(st.size()>1)return -1;

        return tot;
    }
};