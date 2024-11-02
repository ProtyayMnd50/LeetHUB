class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        vector<char>str;
        for(auto &x:s)
        str.push_back(x);

        int i=0;
        string res="";
        for(;i<str.size();){
            int j=i;
            int cnt=0;
            while(j<str.size()&&str[i]==str[j]){
                j++;
                cnt++;
            }
            cnt=j-i;
            if(cnt>=3){
                // for(int k=i+2;k<min(j,n);k++){
                //     str[i]='^';
                // }
                res+=str[i];
                res+=str[i+1];
                // cout<<i+2<<"\n";
            }else{
                res+=str[i];
                if(cnt==2)
                res+=str[i+1];
            }
            // cout<<cnt<<" ";
            // cout<<i<<" "<<j-1<<"\n";
            i=j;
            
        }
      for(auto &x:res)
      cout<<x;

        return res;
    }
};