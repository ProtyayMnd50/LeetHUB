class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>hsh;
        for(auto &x:nums){
            hsh[x]++;
        }
        int maxi=200;
        int c=1;
        int ans=-1;
        while(c*k<=maxi){
            if(!hsh[c*k]){
                ans=c*k;
                break;
            }
            c++;
        }
        cout<<ans<<"\n";
        return ans;
    }
};