class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        return a.back()>b.back();
    }

    int recur(vector<vector<int>>& boxTypes,int truckSize,int i,int units){
       int n=boxTypes.size();

       if(i==n||truckSize<=0){
        return units;
       }

        if(truckSize>=boxTypes[i].front())
        {
            return recur(boxTypes,truckSize-boxTypes[i].front(),i+1,units+boxTypes[i].back()*boxTypes[i].front());
        }else{
            return recur(boxTypes,0,i,units+truckSize*boxTypes[i].back());
        }

        return 0;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);

        for(auto &x:boxTypes){
            for(auto &y:x){
                cout<<y<<",";
            }
            cout<<"\n";
        }

        int res=recur(boxTypes,truckSize,0,0);
        return res;
       
    }
};