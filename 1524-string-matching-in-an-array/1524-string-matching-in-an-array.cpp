#define nl "\n"
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        unordered_set<string>st;
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(words[i].compare(words[j])!=0){
                int pos=words[j].find(words[i]);
                int sz=words[j].size();
                if(pos>=0&&pos<sz)
                // ans.push_back(words[i]);
                st.insert(words[i]);
               }
            }
        }

        for(auto &x:st){
            ans.push_back(x);
        }
        return ans;
    }
};