class Solution {
public:
        vector<int> minBitwiseArray(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 2)
                ans.push_back(-1);
            else if ((nums[i] & nums[i] + 1) == 0) // of form 2^k-1 (no zeros)
            {
                ans.push_back(nums[i] / 2);
            }
            else
            {
                for (int j = 0; j <=30; j++)
                {
                    if(nums[i]&(1<<j))continue;
                    ans.push_back(nums[i]^(1<<(j-1)));break;
                }
            }
        }
        return ans;
    }
};