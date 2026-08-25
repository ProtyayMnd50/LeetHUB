#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>hsh;
        for(auto &x:nums)
            hsh[x]++;
        
        int c=1;
        int ans=105;//largest number that will be divisible by ans
        while(true){
            if(!hsh[k*c]){
                ans=k*c;
                break;
            }
            c++;
        }

        cout<<ans<<"\n";
        return ans;
    }
};