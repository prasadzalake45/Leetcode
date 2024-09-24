class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        

        unordered_set<int>s;

        for(auto it:arr1){

        while(!s.count(it) && it>0){
            s.insert(it);
            it=it/10;

        }
            
        
        }

        int res=0;

        for(auto it:arr2){

            while(!s.count(it) && it>0){
                it=it/10;
            }

            if(it>0){
            res=max(res,(int)log10(it)+1);


            }


            
        }
        return res;
        
    }
};