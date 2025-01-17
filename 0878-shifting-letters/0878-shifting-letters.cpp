#define nl "\n"
#define ll long long
class Solution {

public:
    string shiftingLetters(string s, vector<int>& shifts) {
        map<ll,char>mp;
        for(char ch='a';ch<='z';ch++){
            mp[ch-'a']=ch;
        }
       
        string ans="";

        ll tot=accumulate(shifts.begin(),shifts.end(),0ll);
        ll psum=0;//previous sum
        for(int i=0;i<s.size();i++){
            ll toshift=tot-psum;
            toshift%=26;
            ll num=(s[i]-'a');
            num%=26;
            num=(num+toshift)%26;
            char shifted=mp[num];
            cout<<shifted;
            ans+=shifted;
            psum+=shifts[i];
        }
        return ans;
    }
};