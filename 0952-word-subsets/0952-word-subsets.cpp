class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    
        map<char,int>sec;
        // for(char ch='a';ch<='z';ch++){
        //     sec[ch];
        // }
        for(auto &x:words2){
            map<char,int>mp;
            for(auto &y:x){
                mp[y]++;
                sec[y]=max(sec[y],mp[y]);
            }
        }
        vector<string>ans;
        for(int i=0;i<words1.size();i++){
            map<char,int>mp;
            // for(char ch='a';ch<='z';ch++)
            //     mp[ch];

            for(auto &x:words1[i])
                mp[x]++;
            
            bool fl=true;
            for(char ch='a';ch<='z';ch++){
                if(sec[ch]>mp[ch]){
                    fl=false;break;
                }
            }
            if(fl)
            ans.push_back(words1[i]);
        }
        for(auto &x:ans){
            cout<<x<<" ";
        }

        return ans;
    }
};