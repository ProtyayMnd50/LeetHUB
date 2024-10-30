class Solution {
public:
    #define ll long long
    ll mod = 1e9 +7;
    
    int lengthAfterTransformations(string s, int t) {
        vector<ll> freq(26,0);
        
        for(auto c:s){
            freq[c-'a']++;
        }
        
        while(t--){
            ll z = freq[25];
            freq[25]=0;
            for(int i=24;i>=0;i--){
                freq[i+1] = freq[i];
                freq[i] = 0;
            }
            freq[0] += z;
            freq[0]%=mod;
            freq[1] += z;
            freq[1]%mod;
            
        }
        
        ll ans = 0;
        for(auto f:freq){
            ans+=f;
            ans%=mod;
        }
        
        return ans;
    }
};