class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();

        unordered_map<int,long>mp;

        for(auto it:nums1){
            mp[it]+=n2;
        }

        for(auto it:nums2){
            mp[it]+=n1;
        }

         int XOR=0;
        for(auto it:mp){
            if(it.second%2==1){
                XOR=XOR^it.first;
               
            }
        }

        return XOR;
        
    }
};