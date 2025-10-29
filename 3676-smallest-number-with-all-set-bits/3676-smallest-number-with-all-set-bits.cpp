#define nl "\n"
class Solution {
public:
    int smallestNumber(int n) {
        for(int i=n;;i++){
            int chk=i&(i+1);
            if(!chk) {
                cout<<i<<nl;
                return i;
            }
        }
    }
};