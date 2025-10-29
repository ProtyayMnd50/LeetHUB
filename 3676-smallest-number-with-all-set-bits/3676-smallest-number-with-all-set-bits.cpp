class Solution {
public:
    int smallestNumber(int n) {
        // int bit_count = static_cast<int>(floor(log2(n))) + 1;
        int binDigs=floor(log2(n))+1;
        int res = (1 << binDigs) - 1;
        return res;
    }
};