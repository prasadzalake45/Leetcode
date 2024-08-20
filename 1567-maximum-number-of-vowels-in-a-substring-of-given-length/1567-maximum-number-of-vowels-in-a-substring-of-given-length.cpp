class Solution {
public:

   bool vowel(char& ch){
    return ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u' ;  
   }
    int maxVowels(string s, int k) {

        int n=s.size();
        
        int i=0;
        int j=0;
        int cnt=0;
        int maxV=0;

        while(j<n){
            if(vowel(s[j])){
                cnt++;
            }

            if(j-i+1==k){
                maxV=max(maxV,cnt);

                if(vowel(s[i])){
                    cnt--;
                }
                i++;
            }
            j++;
        }

        return maxV;
    }
};