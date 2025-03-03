class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n=nums.size();

        vector<int>ans(n,0);

        int cntless=0;
        int cntpivot=0;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                cntless++;

            }
            else if(nums[i]==pivot){
                cntpivot++;
            }
        }

        int i=0;
        int j=cntless;
        int k=cntless+cntpivot;

      for(int s=0;s<n;s++){
        if(nums[s]<pivot){
            ans[i]=nums[s];
            i++;
        }

        else if(nums[s]==pivot){
            ans[j]=nums[s];
            j++;
        }
        else{
            ans[k]=nums[s];
            k++;
        }
      }

      return ans;
        
    }
};