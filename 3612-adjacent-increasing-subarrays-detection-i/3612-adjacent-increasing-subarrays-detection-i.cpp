class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        // if(n==(2*k)){
        //     unordered_set<int>st1(nums.begin(),nums.begin()+k);
        //     unordered_set<int>st2(nums.begin()+k,nums.end());

        //   if(st1.size()==k&&st2.size()==k && is_sorted(nums.begin(),nums.begin()+k)&&is_sorted(nums.begin()+k,nums.end()))
        //     return true;
        //     else
        //     return false;
        // }
        for(int i=0;i<=(n-2*k);i++){
            vector<int>v1;
            for(int j=i;j<i+k;j++){
                v1.push_back(nums[j]);
            }
            unordered_set<int>st1(v1.begin(),v1.end());

            vector<int>v2;
             for(int l=(i+k);l<(i+2*k);l++){
                v2.push_back(nums[l]);
            }
            unordered_set<int>st2(v2.begin(),v2.end());

            if(is_sorted(v1.begin(),v1.end())&& is_sorted(v2.begin(),v2.end())&& v1.size()==st1.size()&& v2.size()==st2.size()){
                return true;
            }
           
        }
        return false;
    }
};