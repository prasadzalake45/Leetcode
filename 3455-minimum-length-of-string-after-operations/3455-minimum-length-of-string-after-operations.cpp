class Solution {
public:
    int minimumLength(string s) {

        unordered_map<char,int>mp;

        for(auto it:s){
            mp[it]++;
        }
        int delet=0;

        for(auto it:mp){
            if(it.second>2){
                if(it.second%2==0){

                    delet=delet+(it.second-2);


                }
                else{


                    delet=delet+(it.second-1);

                }
            }
        }

        

        return s.size()-delet;
        
    }
};