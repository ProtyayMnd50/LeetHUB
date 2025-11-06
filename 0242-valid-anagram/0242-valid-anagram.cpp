class Solution {
public:
    bool isAnagram(string s, string t) {
       //solution involving use of a single hashMap for the purpose
        if(s.size()!=t.size()) return false;

        vector<int>hsh(26,0);
        for(int i=0;i<s.size();i++){
            hsh[s[i]-'a']++;
            hsh[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(hsh[i]!=0) return false;
        }
        return true;
    }
};