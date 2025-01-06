#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ll tot=accumulate(nums.begin(),nums.end(),0ll);
        ll p1=0;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            p1+=nums[i];
            ll p2=tot-p1;
            if(p1>=p2)
            ans++;
        }
        return ans;
    }
};