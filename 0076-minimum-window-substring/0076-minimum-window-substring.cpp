class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size()>s.size()){
            return "";
        }

        int n=s.size();

        int hash[256]={0};

        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }

        int left=0;
        int right=0;
        int minlen=INT_MAX;
        int startIndex=0;
        int cnt=t.size();

        while(right<n){

            if(hash[s[right]]>0){
                cnt--;
                
            }
            hash[s[right]]--;
            right++;

            while(cnt==0){
                if(right-left<minlen){
                    minlen=right-left;
                    startIndex=left;
                }
                
                hash[s[left]]++;

                if(hash[s[left]]>0){
                    cnt++;
                   
                }
                 left++;
            }
            


        }
        
        if(minlen==INT_MAX){
            return "";
        }
        
            return s.substr(startIndex,minlen);
        
    }
};