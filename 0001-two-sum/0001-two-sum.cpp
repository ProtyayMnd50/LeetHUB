#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, pair<int, int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].first++;
            mp[nums[i]].second = i;
        }
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++) {
            if (mp[target - nums[i]].second != i &&
                mp[target - nums[i]].first) {
                res[0] = i;
                res[1] = mp[target - nums[i]].second;
                break;
            }
        }
        for (auto& x : res)
            cout << x << " ";
        return res;
    }
};