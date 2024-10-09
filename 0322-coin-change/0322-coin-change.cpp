class Solution {
public:
    int func(int ind, vector<int>& coins, int amt, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (amt % coins[0] == 0) ? amt / coins[0] : 1e9;
        }
        if (dp[ind][amt] != -1)
            return dp[ind][amt];
        int nt = 0 + func(ind - 1, coins, amt, dp);

        int tk = 1e9;
        if (coins[ind] <= amt)
            tk = 1 + func(ind, coins, amt - coins[ind], dp);

        return dp[ind][amt] = min(tk, nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n - 1, coins, amount, dp);
        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};