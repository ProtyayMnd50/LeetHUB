#define ll long long
class Solution {
public:
    ll hourstaken(vector<int>&arr,int k){
        ll res=0;
        for(int i=0;i<arr.size();i++){
            int quo=arr[i]/k;
            res+=quo;
            if(arr[i]%k>0)
            res++;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;//maximum value of answer
        while(low<=high){
            int mid=low+(high-low)/2;
            ll mnh=hourstaken(piles,mid);
            if(mnh>h)
            low=mid+1;
            else
            {
               ans=min(ans,mid);
               high=mid-1;
            }
        }
        return ans;
    }
};