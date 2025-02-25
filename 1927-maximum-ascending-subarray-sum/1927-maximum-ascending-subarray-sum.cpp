#define ll long long
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int l=1,r=1;
        int prev=nums.front();
        ll sum=nums.front();
        ll ans=nums.front();
      while(r<nums.size()){
        if(prev<nums[r]){
            sum+=nums[r];
            prev=nums[r];
        }else{
            l=r;
            sum=nums[r];
            prev=nums[r];
        }
        ans=max(ans,sum);
        r++;
      } 
      return ans;
    }
};