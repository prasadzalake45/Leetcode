class Solution {
public:

    int check(int target, vector<int>&tops, vector<int>&bottoms){
        int n=tops.size();
        int topRotation=0;
        int bottomRotation=0;

        for(int i=0;i<n;i++){

            if(target!=tops[i] && target!= bottoms[i]){
                return -1;
            }

            else if(target!=tops[i]){
                topRotation++;
            }
            else if (target!=bottoms[i]){
                bottomRotation++;
            }
        }


        return min(topRotation,bottomRotation);

    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        

        int rotation=check(tops[0],tops,bottoms);

        if(rotation!=-1 || tops[0]== bottoms[0]){
            return rotation;
        }
        else{
            return check(bottoms[0],tops,bottoms);
        }
    }
};