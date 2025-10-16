class Solution {
public:
    string frequencySort(string s) {
        string result="";

        unordered_map<char,int>mp;

        for(auto it:s){
            mp[it]++;
        }

        vector<pair<char,int>>ans;
        for(auto it:mp){
            ans.push_back({it.first,it.second});
        }

        // i have to sort based on frequency

        sort(ans.begin(),ans.end(),[](pair<char,int>&a,pair<char,int> &b){
             if(a.second==b.second){
                return a.first<b.first;
            }

            return a.second>b.second;

            
           
        });

        for(auto it:ans){
            cout<<it.first<<"-->"<<it.second<<endl;
        }

        for(auto it:ans){
            result.append(it.second,it.first);

        }


        return result;

        





    }
};