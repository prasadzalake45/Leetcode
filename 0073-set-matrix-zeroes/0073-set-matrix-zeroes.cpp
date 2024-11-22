class Solution {
public:  
   
    void markrow(int row,int col,vector<vector<int>>& matrix){

        for(int col=0;col<matrix[0].size();col++){
            if(matrix[row][col]!=0){
                matrix[row][col]='p';
            }
        }

    }

    void markcol(int row,int col,vector<vector<int>>& matrix){

        for(int row=0;row<matrix.size();row++){
            if(matrix[row][col]!=0){
                matrix[row][col]='p';
            }
        }
        
    }


    
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    markrow(i,j,matrix);
                    markcol(i,j,matrix);
                   
                    
                    
                }
            }
        }


         for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='p'){
                    matrix[i][j]=0;
                    
                    
                }
            }
        }

       

        
         
    }
};