class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        int i=0;
        string res="";
        while(i<s.size()){
            int j=i;
            int cnt=0;
            while(j<s.size()&&s[i]==s[j]){
                j++;
                cnt++;
            }
            if(cnt>=3){
                res+=s[i];
                res+=s[i+1];
            }else{
                res+=s[i];//cnt>=1
                if(cnt==2)
                res+=s[i+1];
            }
            i=j;
        }
        return res;
    }
};