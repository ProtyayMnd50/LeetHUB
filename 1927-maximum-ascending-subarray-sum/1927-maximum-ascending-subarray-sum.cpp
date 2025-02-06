class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
       int n=nums.size();
       if(n==1)return nums.front();
       int l=0,r=1;
       int sum=0;
       int mx=0;
       while(r<n){
        if(nums[r-1]<nums[r]){
            sum+=nums[r-1];
            if(r==n-1)
            sum+=nums[r];
            r++;
            mx=max(mx,sum);
            cout<<sum<<endl;
        }else{
             sum+=nums[r-1];
             mx=max(mx,sum);
            cout<<sum<<endl;
            l=r;
            r=l+1;
            sum=0;  
        }
       }
       return mx; 
    }
};