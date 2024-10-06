class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        int sum=0;
        for(int i=0;i<n;i++){
            int left=sum;
            int right=tot-(nums[i]+left);
            if(left==right)return i;
            sum+=nums[i];
        }
        return -1;
    }
};