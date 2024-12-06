class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {


        vector<int>vec;
        unordered_map<int,int>mp;

        for(auto it:banned){
            mp[it]++;
        }


        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                vec.push_back(i);
            }
        }


       long long  sum=0;
       int maxi=0;

        for(int i=0;i<vec.size();i++){
            for(int j=i;j<vec.size();j++){
                sum+=vec[j];

                if(sum<=maxSum){
                    maxi=max(maxi,j-i+1);
                }
               
                
            }
        }
      
        return maxi;
        

        
    }
};