#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n, "");
        for (int i = 0; i < n; i++) {
            int val=i+1;
           if(val%15==0)
            ans[i]="FizzBuzz";
            else if(val%3==0)
            ans[i]="Fizz";
            else if(val%5==0)
            ans[i]="Buzz";
            else
            ans[i]=to_string(i+1);
        }
        for(auto &x:ans){
            cout<<x<<" ";
        }
        return ans;
    }
};