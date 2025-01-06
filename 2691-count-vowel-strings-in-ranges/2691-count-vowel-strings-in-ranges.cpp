class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>hsh(n,0);
        vector<char> vow={'a','e','i','o','u'};
        vector<int>pref(n,0);
        for(int i=0;i<words.size();i++){
            int p1=find(vow.begin(),vow.end(),words[i].front())-vow.begin();//first letter is vowel if p1 != -1
            int p2=find(vow.begin(),vow.end(),words[i].back())-vow.begin();//last letter is vowel if p2 != -1
            if(p1<5 && p2<5 )//both are vowels 
            hsh[i]++;
            // reqs.push_back(i);
        }
        pref[0]=hsh[0];
        for(int i=1;i<n;i++){
            pref[i]=hsh[i]+pref[i-1];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ans.push_back(l==0?pref[r]:pref[r]-pref[l-1]);
        }
        return ans;

    }
};