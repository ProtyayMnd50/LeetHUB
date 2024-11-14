class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        int ans=-1;
        while(true){
            int tmp=num;
            int prd=1;
            while(tmp>0){
                prd*=(tmp%10);
                tmp/=10;
            }
            if(prd%t==0){
                ans=num;
                break;
            }
            num++;
        }   
        return ans;
    
    }
};