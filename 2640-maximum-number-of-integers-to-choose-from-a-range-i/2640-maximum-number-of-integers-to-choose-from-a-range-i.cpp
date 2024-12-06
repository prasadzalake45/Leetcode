class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {


        vector<int>vec;
        unordered_map<int,int>mp;

        for(auto it:banned){
            mp[it]++;
        }


        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                vec.push_back(i);
            }
        }


       long long sum=0;

       int cnt=0;

       for(auto num:vec){
           sum+=num;

           if(sum<=maxSum){
              cnt++;
            
           }
           else{
            break;
           }
       }

       return cnt;
        

        
    }
};