class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        // cout<<mp[0]<<endl;
        if(mp[0]>=2)return true;//even number of zeros

        for(int i=0;i<n;i++){
            if(mp[2*arr[i]]>0 && arr[i]!=0)return true;
        }
        return false;
    }
};