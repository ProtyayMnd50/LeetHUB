class Solution {
public:
    bool isCircularSentence(string sentence) {
        string tmp=sentence;
        tmp+=" ";
        vector<string>words;
        int sz=tmp.size();
        int i=0;
        string wrd="";
        while(i<sz){
            if(tmp[i]!=' ')
            wrd+=tmp[i];
            else{
                words.push_back(wrd);
                wrd="";
            }
            i++;
        }

        for(int i=0;i<words.size()-1;i++){
            if(words[i].back()!=words[i+1].front())return false;
        }
        if(words[0].front()!=words[words.size()-1].back())return false;

        return true;
    }
};