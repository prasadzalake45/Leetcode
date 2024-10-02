class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int>s(arr.begin(),arr.end());


        map<int,int>mp;

        int rank=1;

        for(auto it:s){
            mp[it]=rank;
            rank++;

        }

       for(int i=0;i<arr.size();i++){
        arr[i]=mp[arr[i]];
       }
        

        return arr;
    }
};