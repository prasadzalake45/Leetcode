class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();

        unordered_map<int,int>mp;

        for(int i=0;i<answers.size();i++){
            mp[answers[i]]+=1;

        }
        
        int cnt=0;
        for(auto it:mp){
           int x=it.first;
           int fre=it.second;
           int groupSize=x+1;

           int group=(fre+groupSize-1)/groupSize;

           cnt+=group*groupSize;
        }
        return cnt;
    }
};