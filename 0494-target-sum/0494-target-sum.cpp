class Solution {
public:
    int func(int ind,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(ind==0){
            if(nums[0]==0&&target==0)return 2;//tk or not tk two ways
            else if(nums[0]==target&&nums[0]!=0)return 1;//tk only, 1 way possible
            else if(target==0)return 1;//nt anything
            else return 0;
        }
            if(dp[ind][target]!=-1)return dp[ind][target];
            int nt=func(ind-1,nums,target,dp);
            int tk=0;
            if(nums[ind]<=target)
            tk=func(ind-1,nums,target-nums[ind],dp);
            return tk+nt;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        int d=target;
        int targ=tot-d;
        if(targ<0||targ%2==1)return 0;//cannot be partitioned
        targ>>=1;// (tot-d)/2
        vector<vector<int>>dp(n,vector<int>(targ+1,-1));
        return func(n-1,nums,targ,dp);
    }
};