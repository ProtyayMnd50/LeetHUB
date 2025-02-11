class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        if(n==1)return nums.front();

        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]!=nums[((mid-1)+n)%n]&&nums[mid]!=nums[(mid+1)%n])
            return nums[mid];

            if(nums[mid]==nums[mid+1]){
                int rght=n-1-mid+1;
                if(rght&1)
                low=mid+1;
                else
                high=mid-1;
            }else if(nums[mid]==nums[mid-1]){
                if((mid+1)&1)
                high=mid-1;
                else
                low=mid+1;
            }
        }
        return -1;
    }
};