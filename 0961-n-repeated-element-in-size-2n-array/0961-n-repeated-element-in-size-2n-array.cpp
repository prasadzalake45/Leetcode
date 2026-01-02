class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {



        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;

        }

        int cnt=(nums.size()/2);


        for(auto it:mp){
            if(it.second>=cnt){
                return it.first;
            }
        }


        return -1;
        
    }
};