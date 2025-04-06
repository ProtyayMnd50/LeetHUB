#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        ll mx=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    ll curr=1LL*(nums[i]-nums[j]);
                    curr*=nums[k];
                    mx=max(mx,curr);
                }
            }
        }
        cout<<mx<<"\n";
        return mx;
    }
};