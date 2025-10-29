#define nl "\n"
class Solution {
public:
    vector<int> allOnes;
    Solution() {
        for (int i = 1; i <= 1023; i++) {
            int chk = i & (i + 1);
            if (!chk)
                allOnes.push_back(i);
        }
    }

    int smallestNumber(int n) {
        int ansPos =
            lower_bound(allOnes.begin(), allOnes.end(), n) - allOnes.begin();
        return allOnes[ansPos];
    }
};