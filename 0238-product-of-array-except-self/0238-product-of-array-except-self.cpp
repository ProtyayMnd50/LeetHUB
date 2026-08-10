class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);//intially ans stores the left suffix
        ans.front()=nums.front();
        for(int i=1;i<nums.size();i++)
            ans[i]=ans[i-1]*nums[i];
        
        int rfx=1;
        for(int i=n-1;i>=0;i--){
            if(i==0)
            ans[i]=rfx;
            else
            ans[i]=ans[i-1]*rfx;
            rfx*=nums[i];
        }

        for(auto &x:ans)
        cout<<x<<" ";
        return ans;
    }
};