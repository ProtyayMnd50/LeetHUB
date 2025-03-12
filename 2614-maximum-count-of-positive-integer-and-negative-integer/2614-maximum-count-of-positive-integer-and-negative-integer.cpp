class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        //finding least positive

        int lp=n;
        int l=0,h=n-1;

        while(l<=h){
            int md=l+(h-l)/2;
            if(nums[md]>0){
                lp=min(lp,md);
                h=md-1;
            }else
                l=md+1;
        }
        //finding max negative
        int mn=-1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<0){
                mn=max(mn,mid);
                low=mid+1;
            }else
                high=mid-1;
        }
        cout<<"Least pos: "<<lp<<endl;
        cout<<"Max neg: "<<mn<<endl;
        return max((n-1-lp+1),(mn+1));
    }
};