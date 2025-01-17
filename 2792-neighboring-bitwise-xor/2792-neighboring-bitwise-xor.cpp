class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();

        vector<int>ori(n);

        ori[0]=0;

        for(int i=1;i<n;i++){
            ori[i]=derived[i-1]^ori[i-1];

        }

        if(ori[n-1]^ori[0]==derived[n-1]){
            return true;
        }
        

        ori[0]=1;
         for(int i=1;i<n;i++){
            ori[i]=derived[i-1]^ori[i-1];

        }

        if(ori[n-1]^ori[0]==derived[n-1]){
            return true;
        }


        return false;
    }
};