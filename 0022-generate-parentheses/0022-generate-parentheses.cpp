class Solution {
public:
    void recur(int open,int close,string curr,vector<string>&res,int n){
        //open->number of opening brackets that can be added

        //close->number of closing brackets that can be added

        int copen=n-open;
        int cclose=n-close;
        if(open==0&&close==0){
            res.push_back(curr);
            return;
        }
        
        if(open>0){
            curr.push_back('(');
            recur(open-1,close,curr,res,n);
            curr.pop_back();
        }

        if(copen>cclose){
            curr.push_back(')');
            recur(open,close-1,curr,res,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        recur(n,n,"",res,n);

        return res;

    }
};