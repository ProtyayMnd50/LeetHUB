class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();

        unordered_map<int,int>frq;//for storing frequency of numbers
        vector<pair<int,int>>ranges;
        unordered_map<int,int>prefix;
        int lowest=1e9;
        int highest=-1e9;
        for(int i=0;i<n;i++)
        {
            frq[nums[i]]++;
            int low=nums[i]-k;
            int high=nums[i]+k;
            ranges.push_back({low,high});
            lowest=min(lowest,low);
            highest=max(highest,high);
        }
        for(int i=lowest;i<=highest;i++){
            prefix[i]=0;
        }

        for(auto &x:ranges){
            prefix[x.first]++;
            prefix[x.second+1]--;
        }
         
        for(int i=lowest+1;i<=highest;i++){
            prefix[i]+=prefix[i-1];
        }
        int ans=0;
        for(int i=lowest;i<=highest;i++){
            int pehle=frq[i];
            int abhi=prefix[i];
            int badha=abhi-pehle;//itne ops hue ye freq lane ke liye
            int actual=pehle+min(numOperations,badha);
            ans=max(ans,actual);
            // cout<<i<<" "<<actual<<"\n";
        }

        return ans;

        
    }
};