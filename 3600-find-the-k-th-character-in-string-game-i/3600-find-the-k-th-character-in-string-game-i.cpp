class Solution {
public:
    string st="a";
    unordered_map<int,char>mp;
    // for(char ch='a';ch<='z';ch++){
    //     mp[ch-'a']=ch;
    // }
    
    char kthCharacter(int k) {
        while(st.size()<=k+1){
            string nw="";
            for(int i=0;i<st.size();i++){
                char ch=st[i];
                if(ch=='z')
                ch='a';
                else
                ch++;
                nw+=ch;
            }
            st+=nw;
            cout<<st<<" "<<endl;
        }
        return st[k-1];
    }
};