class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]<<=1;
                nums[i+1]=0;
            }
        }
        vector<int>ans;
        for(auto &x:nums){
            if(x>0)ans.push_back(x);
        }
        int zer=nums.size()-ans.size();
        while(zer--)
        ans.push_back(0);
        return ans;
    }
};