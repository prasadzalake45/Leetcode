class Solution {
public:  

  bool bSearch(vector<int>&index,int start,int end){
    int l=0;
    int h=index.size()-1;

    while(l<=h){
        int mid=(l+h)/2;

        if(index[mid]<start){
            l=mid+1;
        }
        else if(index[mid]>end){
            h=mid-1;
        }
        else{
            return false;
        }
    }

    return true;

  }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>index;
        vector<bool>ans;

        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                index.push_back(i);
            }
        }

        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];



        bool violate=bSearch(index,start+1,end);
        if(violate==false){
            ans.push_back(false);

        }
        else{
            ans.push_back(true);
        }



        }     

        return ans;
     }
};