class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int si=1;
        int sd=1;
        for(int i=0;i<n-1;i++){
            int ci=0;
            int cd=0;
            for(int j=i;j<n-1;j++){
                if(nums[j]<nums[j+1]){
                    ci++;
                    si=max(ci+1,si);
                }
                else
                ci=0;

                if(nums[j]>nums[j+1]){
                    cd++;
                    sd=max(sd,cd+1);
                }else
                cd=0;
            }
        }

        return max(si,sd);
    }
};