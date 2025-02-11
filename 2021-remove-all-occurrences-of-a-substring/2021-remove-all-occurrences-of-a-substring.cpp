class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        
        while(s.find(part)!=string::npos){
            int ans=s.find(part);

            s.erase(ans,part.size());

        }

        return s;
    }
};