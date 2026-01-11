class Solution {
public:

    void nextSmallerLeft(vector<int>& heights,vector<int>&left){
        stack<pair<int,int>>st;

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                left.push_back(-1);
            }
            else{
                left.push_back(st.top().second);
            }

            st.push({heights[i],i});
        }
    }

    void nextSmallerRight(vector<int>& heights,vector<int>&right){
       stack<pair<int,int>>st;

       int n=heights.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                right.push_back(n);
            }
            else{
                right.push_back(st.top().second);
            }

            st.push({heights[i],i});
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        // next smaller at left
        // next smaller at right

        // this need to do because you have to find the width
        // width=right-left-1

        // now you already have height as lenth
        // multiply length * height you will get the max area
        int maxi=INT_MIN;
        vector<int>left;

        nextSmallerLeft(heights,left);

        vector<int>right;

        nextSmallerRight(heights,right);
        reverse(right.begin(),right.end());
        
        int n=heights.size();
        vector<int>width(n);

        for(int i=0;i<heights.size();i++){
            cout<<left[i]<<"->>>"<<right[i]<<endl;
           
            width[i]=right[i]-left[i]-1;
        }


       
        
        for(int i=0;i<heights.size();i++){

            // cout<<heights[i]<<"->"<<width[i]<<" ";
            maxi=max(maxi,heights[i]*width[i]);
            
        }

        return maxi;

        


    }
};