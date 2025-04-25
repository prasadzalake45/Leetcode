class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        if(n==0){
            return 0;
        }

        
        int maxi=1;

        for(int i=0;i<n;i++){
           int arr[255]={0};
            
            for(int j=i;j<n;j++){
                if(arr[s[j]]==1){
                maxi=max(maxi,j-i);
                break;

                }
                else{
                    arr[s[j]]=1;
                    maxi=max(maxi,j-i+1);

                }
              
             

            
            }

        }

        

        return maxi;
        
    }
};