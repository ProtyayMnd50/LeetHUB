class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]<<=1;
                nums[i+1]=0;
            }
        }
        int j=0;
        int i=0;
        while(i<n){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
        return nums;
    }
};