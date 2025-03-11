#define ll long long
class Solution {
public:
    int bouquets(vector<int>&a,int day,int k){
        int bouqs=0;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(day>=a[i])
            cnt++;
            else{
                bouqs+=cnt/k;
                cnt=0;
            }
        }
          bouqs+=cnt/k;
        return bouqs;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        ll prod=1LL*m;
        prod*=k;
        if(prod>bloomDay.size())return -1;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int bouqs=bouquets(bloomDay,mid,k);

            if(bouqs>=m){
                ans=min(ans,mid);
                high=mid-1;  
            }else{
                low=mid+1;
            }

        }
        return ans;

    }
};