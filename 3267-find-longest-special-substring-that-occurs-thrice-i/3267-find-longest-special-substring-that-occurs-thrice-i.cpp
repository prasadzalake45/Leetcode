class Solution {
public:
    int maximumLength(string s) {

        unordered_map<string,int>mp;

        for(int i=0;i<s.size();i++){
            string ans="";
            for(int j=i;j<s.size();j++){

                if(ans.empty()){
                   ans=ans+s[j];
                   mp[ans]++;
                }

                else{
                    if(ans.back()==s[j]){
                        ans+=s[j];
                        mp[ans]++;
                       

                    }
                    else{
                        break;
                    }
                }
                

                

               
                
            }
        }


        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }

        int maxi=INT_MIN;
        for(auto it:mp){
            if(it.second>=3){
                int one=it.first.length();
                maxi=max(maxi,one);
                
            }
        }

        if(maxi!=INT_MIN){
            return maxi;
        }

        return -1;
        
    }
};