class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int n=points.size();

        if(n==1){
            return 0;
        }
        int i=0;
        int j=1;
        int sum=0;

        while(j<n){

            int diffX=abs(points[j][0]-points[i][0]);
            int diffY=abs(points[j][1]-points[i][1]);
            i++;
            j++;

            int maxi=max(diffX,diffY);

            sum+=maxi;
            


           
        }

        return sum;
        
    }
};