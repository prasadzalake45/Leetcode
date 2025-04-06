class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
       sort(special.begin(),special.end());
       int maxi=INT_MIN;
       int n=special.size();

       maxi=max(maxi,special[0]-bottom);
       maxi=max(maxi,top-special[n-1]);

       for(int i=0;i<special.size()-1;i++){
        int ans=special[i+1]-special[i]-1;

        maxi=max(maxi,ans);
       
        

          
        
       }
       return maxi;



        
    }
};