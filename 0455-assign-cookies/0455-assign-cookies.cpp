class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int childrenSize=g.size();
        int cookiesSize=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());


        int i=0;
        int j=0;
        int assignCookies=0;
        int cnt=0;

        while(i<childrenSize && j<cookiesSize){

            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }
            else{
              j++;  
            }

        }
        return cnt;
        
    }
};