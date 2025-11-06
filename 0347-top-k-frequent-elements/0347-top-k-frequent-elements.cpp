class Solution {
public:
    static bool cstm(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto& x : nums)
            mp[x]++;
        vector<pair<int, int>> vp;
        for (auto& x : mp)
            vp.push_back({x.first, x.second});

        sort(vp.begin(), vp.end(), cstm);
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(vp[i].first);

        return ans;
    }
};