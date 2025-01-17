class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            int pos=words[i].find(pref);
            if(pos==0)
            ans++;
        }
        cout<<ans<<endl;
        return ans;
    }
};