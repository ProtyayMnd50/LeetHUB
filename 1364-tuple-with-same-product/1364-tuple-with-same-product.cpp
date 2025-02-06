class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int cnt=0;
        int ans=0;
        for(auto &x:mp){
            if(x.second>=4){
            cnt++;
            cout<<x.first<<" "<<x.second/2<<endl;
            int freq=x.second/2;
            int perm=freq*(freq-1);
            perm>>=1;
            ans+=perm*8;
            }
        }
        return ans;
    }
};