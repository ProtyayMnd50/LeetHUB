class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int incr=1;
        int decr=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){//incr
                incr++;
                decr=1;
                ans=max({ans,incr,decr});
            }else if(nums[i-1]>nums[i]){//decr
                decr++;
                incr=1;
                ans=max({ans,incr,decr});
            }else{//same elements(neither increasing, nor decreasing)
                incr=1;
                decr=1;
            }
        }
        return ans;
    }
};