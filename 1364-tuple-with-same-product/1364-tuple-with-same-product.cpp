class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int prod=nums[i]*nums[j];
                mp[prod]++;
            }
        }
        int ans=0;
        for(auto &x:mp){
            // cout<<x.first<<"->"<<x.second<<"\n";
            int freq=x.second;
            int comb=freq*(freq-1);
            comb>>=1;
            
            ans+=comb*8;
            
        }
        return ans;
    }
};