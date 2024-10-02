class Solution {
public:

    typedef long long ll;
    long long wonderfulSubstrings(string word) {

        int n=word.size();

        unordered_map<ll,ll>mp;
        mp[0]=1;

        int cumxor=0;
        ll result=0;

        for(char ch:word){

            int  shift=ch-'a';
            cumxor^=(1<<shift);

            result+=mp[cumxor];

            for(char ch1='a' ;ch1<='j';ch1++){
                shift=ch1-'a';

                ll checkxor=(cumxor^(1<<shift));

                result+=mp[checkxor];
            }

            mp[cumxor]++;


            

        }

        return result;
        
    }
};