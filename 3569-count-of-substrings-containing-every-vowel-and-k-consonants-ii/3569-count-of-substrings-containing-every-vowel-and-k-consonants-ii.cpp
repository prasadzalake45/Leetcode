class Solution {
public:

    bool isVowel(char& ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }

        return false;
    }
    long long countOfSubstrings(string word, int k) {

        int n=word.size();
        unordered_map<char,int>mp;

        int consCnt=0;
        long long cnt=0;

        vector<int>nextCons(n);

        int lastIdx=n;
        for(int i=n-1;i>=0;i--){
            nextCons[i]=lastIdx;

            if(!isVowel(word[i])){
                lastIdx=i;
            }
        }

        int  i=0;
        int j=0;

        while(j<n){
            char ch=word[j];

            if(isVowel(ch)){
                 mp[ch]++;
            }
            else{
                consCnt++;
            }

            while(consCnt>k){
                char ch=word[i];

                if(isVowel(ch)){
                    mp[ch]--;

                    if(mp[ch]==0){
                        mp.erase(ch);
                    }
                }
                else{
                    consCnt--;

                }
                i++;
            }
             

            while(i<n && mp.size()==5 && consCnt==k){
                int idx=nextCons[j];
                cnt+=idx-j;

                char ch=word[i];

                if(isVowel(ch)){
                    mp[ch]--;

                    if(mp[ch]==0){
                        mp.erase(ch);
                    }
                    
                }

                else{
                        consCnt--;
                    }
                    i++;



                 
            }
              j++;

          
            
        }

        return cnt;


        
    }
};