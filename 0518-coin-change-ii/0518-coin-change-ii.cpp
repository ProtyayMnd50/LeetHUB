class Solution {
public:
    int func(int ind, vector<int>& coins, int amt, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (amt % coins[0] == 0) ? 1 : 0;
        }
        if (dp[ind][amt] != -1)
            return dp[ind][amt];
        int nt = 0 + func(ind - 1, coins, amt, dp);

        int tk = 0;
        if (coins[ind] <= amt)
            tk=func(ind, coins, amt - coins[ind], dp);

        return dp[ind][amt] = tk + nt;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n - 1, coins, amount, dp);
        return ans;
    }
};