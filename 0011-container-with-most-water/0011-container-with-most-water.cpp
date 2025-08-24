class Solution {
public:
    int maxArea(vector<int>& height) {

      int n=height.size();
      
      int left=0;
      int right=n-1;
      int maxi=INT_MIN;

      while(left<right){

        int width=right-left;
        int heigh=min(height[left],height[right]);
        int ans=width*heigh;
        maxi=max(maxi,ans);

        if(height[left]<height[right]){
          left++;

        }
        
        else{
          right--;

        }

      }
      return maxi;
        
    }
};