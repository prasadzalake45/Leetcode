class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

      int n=folder.size();

      sort(folder.begin(),folder.end());


      // for(int i=0;i<n;i++){
      //   cout<<folder[i]<<" ";
      // }

    //  return folder;
    //   // string ans="";

    //   // for(int i=0;i<n;i++){

    //   // }


    string ans="";

    vector<string>answer;

    for(int i=0;i<n;i++){

      string str=folder[i];

      if(ans.empty() || str.substr(0,ans.size()+1)!= ans+"/"){
        answer.push_back(str);
        ans=str;


      }
    }

    return answer;


               
    }
};