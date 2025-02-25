class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0;
        int incr=1,decr=1;
        int ans=1;
        while(i<nums.size()-1){
            if(nums[i]<nums[i+1]){
                decr=1;
                incr++;
            }else if(nums[i]>nums[i+1]){
                incr=1;
                decr++;
            }else{
                incr=1;
                decr=1;
            }
             ans=max({incr,decr,ans});
            i++;
        }
        return ans;
    }
};