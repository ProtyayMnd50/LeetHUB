#define nl "\n"
class Solution {
public:
    vector<int> minOperations(string boxes) {
        // int ans=0;
        int n=boxes.size();
        vector<int>full;//stores indexes of full boxes
        for(int i=0;i<n;i++){
            if(boxes[i]=='1')full.push_back(i);
        }
       
        vector<int>ans;
        for(int i=0;i<n;i++){
            int jmp=0;
            for(int j=0;j<full.size();j++){
                jmp+=abs(i-full[j]);
            }
            ans.push_back(jmp);
        }
        // cout<<ans<<nl;
        return ans;
    }
};