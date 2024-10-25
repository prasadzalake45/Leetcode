class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
     sort(folder.begin(), folder.end());  

        vector<string> result;
        string prev = "";

        for (const string& f : folder) {
            if (prev.empty() || f.substr(0, prev.size() + 1) != prev + "/") {
                result.push_back(f);
                prev = f; 
            }
        }
        
        return result;
         
    }
};