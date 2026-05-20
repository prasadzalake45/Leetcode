class Solution {
public:
    vector<int>helper(vector<int>& A, vector<int>& B,vector<int>&C){
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        int i=0;
        int j=0;

        int n1=A.size();
        int n2=B.size();

        while(i<n1 && j<n2){
            if(i!=0 && j!=0){
                C[i]=C[i-1];
            }

            if(A[i]==B[j]){
              C[i]+=1;
            }
            if(mp1.find(B[j])!=mp1.end()){
                C[i]+=1;
            }
            if(mp2.find(A[i])!=mp2.end()){
                C[i]+=1;
            }

            mp1[A[i]]++;
            mp2[B[j]]++;
           
            i++;
            j++;
        }

        return C;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        

        // find the prefix common array till that index from two array
         
        //approach
        //1) first check if it equal yes increase the cnt
        //2) check on map it present 


        int n=A.size();
        vector<int>C(n,0);
        return helper(A,B,C);

    }
};