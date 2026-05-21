class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        

        // arr1 all element prefixed need to be stored
        // arr2 here for each element reduce from last and check is that present or not


// stored each element prefix in set
        unordered_set<int>s;

        for(auto num:arr1){
            while(num>0){
                 s.insert(num);
               num=num/10;
              
            }
        }


         int maxi=0;

        // for arr2

        for(auto num:arr2){

            while(num>0){

                if(s.count(num)){
                    int size=to_string(num).size();
                    maxi=max(maxi,size);

                }

                num=num/10;
            }
        }


        return maxi;



    }
};