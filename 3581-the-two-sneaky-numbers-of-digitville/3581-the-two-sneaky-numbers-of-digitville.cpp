class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        unordered_map<int,int>mp;

        vector<int>vec;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            if(it.second==2){
                vec.push_back(it.first);

            }
        }

        return vec;
        
    }
};