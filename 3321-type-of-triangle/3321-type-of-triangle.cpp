class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>mp;

        for(int i=0;i<n;i++){
            mp.insert(nums[i]);

        }
        sort(nums.begin(),nums.end());

        if(nums[0]+nums[1]<=nums[2]){
            return "none";

        }

        if(mp.size()==nums.size()){
            return "scalene";

        }
        else if(mp.size()==nums.size()-1){
          return "isosceles";
        }
        // else if(mp.size()==nums.size()-2){
            return "equilateral";
        

    
    }
};