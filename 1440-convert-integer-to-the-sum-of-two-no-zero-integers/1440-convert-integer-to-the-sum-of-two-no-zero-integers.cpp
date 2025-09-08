class Solution {
public:
    bool helper(int n){
      string number=to_string(n);

      return number.contains("0");


    }
    vector<int> getNoZeroIntegers(int n) {

      for(int i=1;i<n;i++){
        int left=i;
        int right=n-i;

        if(!helper(left)  && !helper(right)){
          return {left,right};
        }

      
      }
      return {-1,-1};
    
       




        
    }


};