class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        
        unordered_map<string,int>mp1;
       
        
        for(string it:message){
            mp1[it]++;
        }
        
       
        
        
           int cnt=0;
        
        for(string it:bannedWords){
            if(mp1.find(it)!=mp1.end()){
                
                cnt+=mp1[it];
                mp1[it]--;
                
        }
         
            
       }
        
        if(cnt>=2){
            return true;
}
        return false;
        
        
    }
};