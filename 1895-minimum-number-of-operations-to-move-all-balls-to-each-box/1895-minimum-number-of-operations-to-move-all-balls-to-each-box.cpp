#define nl "\n"
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>px(n,0);//prefix sums of indexes of boxes which have balls
        vector<int>sx(n,0);//suffix sums of indexes of boxes which have balls
        int balls=count(boxes.begin(),boxes.end(),'1');//total number of boxes having balls
        px[0]=(boxes[0]=='1'?0:0);
        for(int i=1;i<n;i++){
            px[i]=(boxes[i]=='1'?i:0);
            px[i]+=px[i-1];
        }
        sx.back()=(boxes.back()=='1'?n-1:0);
        for(int i=n-2;i>=0;i--){
            sx[i]=(boxes[i]=='1'?i:0);
            sx[i]+=sx[i+1];
        }
        vector<int>ans;
        int l1=0;//total number of balls in the left
        for(int i=0;i<n;i++){
            if(boxes[i]=='1')l1++;
            int lops=abs(i*l1-px[i]);//left operation cost
          
            int rops=abs(i*(balls-l1)-sx[i]);//right operation cost
            if(boxes[i]=='1')
            rops-=i;//if ith box has ball, then its index value has to be deducted
           ans.push_back(lops+rops);
        }
   
        return ans;


        for(auto &x:px)
        cout<<x<<" ";
        cout<<nl;
        for(auto &x:sx)
        cout<<x<<" ";
        cout<<nl;
        return {0};
    }
};