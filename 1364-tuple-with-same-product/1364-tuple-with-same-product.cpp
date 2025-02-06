class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto &x:mp){
            if(x.second>=2){
                // cout<<x.first<<" "<<x.second<<endl;
                int freq=x.second;
                int val=freq*(freq-1);
                val>>=1;
                ans+=val*8;
            }
        }
        return ans;

        return 0;
    }
};