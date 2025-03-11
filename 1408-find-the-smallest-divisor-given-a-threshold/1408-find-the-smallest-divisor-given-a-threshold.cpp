#define ll long long
class Solution {
public:
    ll divRes(vector<int>&nums,int divisor){
        ll sum=0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)(nums[i]) / (double)(divisor));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;//mid is the divisor
            ll res=divRes(nums,mid);

            if(res<=threshold){
                cout<<mid<<endl;
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }  
        }
        return ans;
    }
};