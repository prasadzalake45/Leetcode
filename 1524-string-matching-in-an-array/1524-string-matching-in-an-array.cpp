class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>check;

        for(int i=0;i<words.size();i++){
            check.push_back(words[i]);
        }

        vector<string>ans;


        // for(auto it:words){
           
        //         for(int i=0;i<check.size();i++){
        //             string str=check[i];
        //             if(str.find(it)!=string::npos){
        //                 ans.push_back(it);
        //             }
        //         }
            
        // }

        for(int i=0;i<words.size();i++){
            for(int j=0;j<check.size();j++){
                if(i==j){
                    continue;
                }
                else{
                    string str=check[j];

                    if(str.find(words[i])!=string::npos){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }
       


        return ans;


        
    }
};