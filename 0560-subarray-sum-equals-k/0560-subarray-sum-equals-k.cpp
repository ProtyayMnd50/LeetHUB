class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ps=0;
        mp[ps]++;
        int cnt=0;
        for(int i=0;i<n;i++){
            ps+=nums[i];
            cnt+=mp[ps-k];//kitne log jiska sum ps-k hai,(ps+(ps-k))==k
            mp[ps]++;
        }
        return cnt;
    }
};