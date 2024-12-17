class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        vector<int>vec(26,0);


        for(char ch:s){
            vec[ch-'a']++;
        }



        int i=25;

        string ans="";
        
        while(i>=0){

            if(vec[i]==0){
                i--;
                continue;
            }

            char ch='a'+i;
            int fre=vec[i];

            int mini=min(fre,repeatLimit);

            ans.append(mini,ch);

            vec[i]-=mini;

            if(vec[i]>0){
                int j=i-1;

                while(j>=0 && vec[j]==0){
                    j--;
                }

                if(j<0){
                    break;
                }
                ans.push_back('a'+j);
                vec[j]--;
            }




        }

        return ans;
        
    }
};