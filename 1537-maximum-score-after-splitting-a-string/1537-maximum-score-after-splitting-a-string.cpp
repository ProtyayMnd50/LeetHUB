class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int cl=(s[0]=='0')?1:0;
        int cr=count(s.begin(),s.end(),'1');
        cr-=(1^cl);
        // cout<<cl<<" "<<cr<<endl;
        int ans=(cl+cr);
        for(int i=1;i<n-1;i++){
            if(s[i]=='0')cl++;
            else cr--;
            ans=max(ans,(cl+cr));
        }
        return ans;
    }
};