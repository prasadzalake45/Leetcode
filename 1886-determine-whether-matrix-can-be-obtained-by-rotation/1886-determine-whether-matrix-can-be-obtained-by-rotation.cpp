class Solution {
public:

   bool checkRotation(vector<vector<int>>& mat, vector<vector<int>>& target){

    // mat transponse and reverse the row;
    int row=mat.size();
    int col=mat[0].size();

    for(int i=0;i<row;i++){
        for(int j=i+1;j<col;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

   for(int i = 0; i < row; i++){
    reverse(mat[i].begin(), mat[i].end());
  }

  return target==mat;



   }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row=mat.size();
        int col=mat[0].size();

       // here you need to know how to do 90 degree rotatton
       // if you want to do 90 degree rotate you need to Transpose the matrix and then reverse the row will give the rotation of the matrix in clockwise

    // you need to check 90 degree rotation 3 time because 4 th time rotation it will become the original mat

      for(int i=0;i<4;i++){
        if(checkRotation(mat,target)==true){
            return true;
        }
      }

      return false;


    }
};