class Solution {
public:
    int numberOfSubstrings(string s) {

        int n=s.size();
        int i=0;
        int j=0;
        int cnt=0;
        int store[3]={0};

        while(j<n){

            store[s[j]-'a']++;

            while(store[0]>0 && store[1]>0 && store[2]>0){
                cnt+=(n-j);
                store[s[i]-'a']--;
               
                i++;
            }
            j++;
        }

        return cnt;




        
    }
};