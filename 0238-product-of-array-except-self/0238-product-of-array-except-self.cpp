class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pfx(n);
        vector<int>sfx(n);

        pfx.front()=nums.front();
        sfx.back()=nums.back();

        for(int i=i=1;i<n;i++)
            pfx[i]=pfx[i-1]*nums[i];

        for(int i=max(n-2,0);i>=0;i--)
            sfx[i]=sfx[i+1]*nums[i];

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(i==0)
            ans[i]=sfx[i+1];
            else if(i==n-1)
            ans[i]=pfx[max(i-1,0)];
            else
            ans[i]=pfx[i-1]*sfx[i+1];
        }
        for(auto &x:ans)cout<<x<<" ";

        return ans;
    }
};