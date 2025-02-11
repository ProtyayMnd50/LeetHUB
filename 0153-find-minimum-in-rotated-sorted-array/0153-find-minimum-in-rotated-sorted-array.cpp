class Solution {
public:
    int findMin(vector<int>& nums) {
         int n=nums.size();
      int low=0,high=n-1;
        int mn=INT_MAX;
        while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[low]<=nums[mid]){//if left half sorted
            mn=min(mn,nums[low]);
            low=mid+1;//going to unsorted half
        }else if(nums[mid]<=nums[high]){//if right half sorted
            mn=min(mn,nums[mid]);
            high=mid-1;//going to unsorted half
        }
      }
      return mn;
    }
};