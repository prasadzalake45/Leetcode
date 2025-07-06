class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;

        if(n<k){
          return;
        }


        vector<int>arr1;
        vector<int>arr2;
        vector<int>answer;

        // lastly k element

        for(int i=n-1;i>=n-k;i--){
          arr1.push_back(nums[i]);
        }
        reverse(arr1.begin(),arr1.end());

        for(int i=0 ;i<n-k;i++){
          arr2.push_back(nums[i]);
        }


        answer.insert(answer.end(),arr1.begin(),arr1.end());
        answer.insert(answer.end(),arr2.begin(),arr2.end());

        nums=answer;
    }
};