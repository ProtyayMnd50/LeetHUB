#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> result(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
          
            if (mp.find(x)!=mp.end()&&mp[x] !=i) {
                result[0] = i;
                result[1] = mp[x];
                break;
            }
              mp[nums[i]] = i;
        }
        return result;
    }
};