class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans(2,-1);
       int i=0,j=numbers.size()-1;
       while(i<j){
        int sum=numbers[i]+numbers[j];
        if(sum>target)
        j--;
        else if(sum<target)
        i++;
        else if(target==sum)
        {
            ans[0]=i+1;
            ans[1]=j+1;
            cout<<numbers[i]<<" "<<numbers[j];
            // break;
            i++;
            j--;
        }
       }
       return ans;
    }
};