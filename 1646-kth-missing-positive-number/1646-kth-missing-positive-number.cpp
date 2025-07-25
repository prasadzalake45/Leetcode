class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

      int n=arr.size();

      unordered_map<int,int>mp;

      for(auto it:arr){
        mp[it]++;

      }

      vector<int>ans;

      int maxi=arr[n-1];

      for(int i=1;i<=maxi;i++){
        if(mp.find(i)==mp.end()){
          ans.push_back(i);

        }
      }

      if(k<ans.size()+1){
        return ans[k-1];
      }
   
        int rem=k-ans.size();
        return maxi+rem;
      



        
    }
};