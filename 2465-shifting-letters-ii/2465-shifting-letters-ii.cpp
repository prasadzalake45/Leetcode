class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int s1=s.size();
        int n=shifts.size();


        vector<int>diff(s1,0);

        for(auto it:shifts){
            int l=it[0];
            int r=it[1];
            int dir=it[2];
            int x;

            if(dir==0){
               x=-1;
                

            }
            else if(dir==1){
                x=+1;

            }

            diff[l]+=x;
            if(r+1<s1){
                 diff[r+1]-=x;

            }
           
        }

        for(int i=1;i<s1;i++){
            diff[i]+=diff[i-1];
        }

        for(int i=0;i<s1;i++){
            int shift=diff[i]%26;

            if(shift<0){
                shift+=26;
            }
            s[i]=((s[i]-'a')+shift)%26+'a';
        }
        return s;


        
    }
};