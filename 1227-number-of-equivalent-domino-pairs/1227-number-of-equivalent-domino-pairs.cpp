class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        int n=dominoes.size();

        int count[100]={0};

        int ans=0;


        for(int i=0;i<n;i++){

            int a=dominoes[i][0];
            int b=dominoes[i][1];

            int key=min(a,b)*10+max(a,b);

            ans+=count[key];
            count[key]++;

        }

        return ans;


        
    }
};