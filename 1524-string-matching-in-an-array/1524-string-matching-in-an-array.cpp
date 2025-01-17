#define nl "\n"
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        unordered_set<string>st;
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(i!=j &&words[j].find(words[i])!=-1)
               st.insert(words[i]);
            }
        }

        for(auto &x:st){
            ans.push_back(x);
        }
        return ans;
    }
};