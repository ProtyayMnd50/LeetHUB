class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(const char& ch : s){
            bool isPoped = false;
            if(!st.empty()){
                char top = st.top();
                if(ch==')' && top == '('){
                    st.pop();
                    isPoped = true;
                }
            }
            if(!isPoped){
                st.push(ch);
            }

        }
        return st.size();
    }
};