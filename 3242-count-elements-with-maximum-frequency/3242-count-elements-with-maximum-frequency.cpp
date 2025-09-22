class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

      int n=nums.size();

      unordered_map<int,int>mp;

      for(auto it:nums){
        mp[it]++;
      }

      int maxi=INT_MIN;
      for(auto it:mp){
        maxi=max(maxi,it.second);
      }

      cout<<maxi<<endl;
      int cnt=0;
      for(auto it:mp){

       if(it.second==maxi){
        cnt++;
       }
      }


      return cnt*maxi;
        
    }
};