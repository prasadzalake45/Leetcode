class Solution {
public:
    int numberOfSubstrings(string s) {

        int n=s.size();


        vector<int>ans(3,-1);

        int cnt=0;

        for(int i=0;i<n;i++){

            ans[s[i]-'a']=i;

            if(ans[0]!=-1 && ans[1]!=-1 && ans[2]!=-1){
                cnt+=(1+min({ans[0],ans[1],ans[2]}));
            }

        }

        return cnt;
        
    }
};