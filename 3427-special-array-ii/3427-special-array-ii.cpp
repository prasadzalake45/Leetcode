class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

   int n=nums.size();

   vector<int>ans(n,0);

   int i=0;
   int j=0;

   while(i<n){

    if(j<i){
        j=i;
    }

    while(j+1<n && nums[j]%2!=nums[j+1]%2 ){
        j++;

    }

    ans[i]=j;
    i++;
    

   }
    vector<bool>res;
   for(int i=0;i<queries.size();i++){
    int start=queries[i][0];
    int end=queries[i][1];

    if(ans[start]>=end){
        res.push_back(true);
    }
    else{
        res.push_back(false);
    }


   }

   return res;
        
    }
};