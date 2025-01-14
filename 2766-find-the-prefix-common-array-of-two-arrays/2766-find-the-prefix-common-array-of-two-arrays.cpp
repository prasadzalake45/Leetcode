class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n=A.size();

        unordered_set<int>s1;
        unordered_set<int>s2;

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            s1.insert(A[i]);
            s2.insert(B[i]);


            int cnt=0;

            for(auto it:s1){
                if(s2.count(it)!=0){
                    cnt++;
                }
            }

            ans[i]=cnt;


        }
        return ans;
    }
};