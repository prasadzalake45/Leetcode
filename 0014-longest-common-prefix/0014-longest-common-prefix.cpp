class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n=strs.size();

        string temp=strs[0];

        for(int i=1;i<n;i++){


            int j=0;

            while(j<temp.size() && j<strs[i].size() && temp[j]==strs[i][j]){
                j++;
            }

            temp=temp.substr(0,j);

             if(temp.empty()){
                return "";
             }
        }

        return temp;
        
    }
};