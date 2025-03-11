#define ll long long
class Solution {
public:
    int daysReq(vector<int>v,ll cap){
        // int i=0;
        int days=1;
        ll sum=0;
        for(int i=0;i<v.size();i++){
          if((sum+1LL*v[i])<=cap){
            sum+=1LL*v[i];
          }else{
            days++;
            sum=v[i];
          }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
     ll sum=accumulate(weights.begin(),weights.end(),0ll);
     ll low=*max_element(weights.begin(),weights.end());
     ll high=sum;
    ll ans=sum;
     while(low<=high){
        ll mid=low+(high-low)/2;//capacity
        int mndays=daysReq(weights,mid);

        if(mndays<=days){
            ans=min(ans,mid);
            cout<<mid<<" "<<mndays<<endl;
            high=mid-1;
        }else{
            low=mid+1;
        }
     }
     return ans;
    }
};