
class Solution {
#define nl "\n"
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        // int n=words.size();
        int ans=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=(i+1);j<words.size();j++){
                //checking prefix
                bool pr=true;
                for(int k=0;k<min(words[i].size(),words[j].size());k++){
                    if(words[i][k]!=words[j][k]){
                        pr=false;
                        break;
                    }
                }
                //checking suffix
                bool sx=true;
                int a=words[i].size()-1,b=words[j].size()-1;
                int r=0;
                while(r<min(words[i].size(),words[j].size())){
                      if(words[i][a]!=words[j][b]){
                        sx=false;
                        break;
                    }
                    a--;
                    b--;
                    r++;
                }
                if(pr==true &&sx==true&&words[i].size()<=words[j].size()){
                    ans++;
                    cout<<pr<<" "<<sx<<nl;
                }
            }
        }
        return ans;
    }
};