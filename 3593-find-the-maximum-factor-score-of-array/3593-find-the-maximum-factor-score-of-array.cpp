class Solution {
public:
#define ll long long
#define nl "\n"
    long long maxScore(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1LL*nums[0]*nums[0];
        }
        ll ans=0;
        ll gc=0;
        ll lc=1;
        for(int i=0;i<n;i++){
            gc=gcd(gc,nums[i]);
            lc=lcm(lc,nums[i]);
        }
        ans=max(ans,(gc*lc));
        for(int i=0;i<n;i++){
            ll gc1=0;
            ll lc1=1;

            for(int j=0;j<i;j++){
                gc1=gcd(gc1,nums[j]);
                lc1=lcm(lc1,nums[j]);
            }
            for(int k=(i+1);k<n;k++){
                gc1=gcd(gc1,nums[k]);
                lc1=lcm(lc1,nums[k]);
            }
             ans=max(ans,1LL*(gc1*lc1));
        }
        return ans;
       
    }
};