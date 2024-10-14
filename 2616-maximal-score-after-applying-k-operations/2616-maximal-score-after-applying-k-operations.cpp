class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        int n=nums.size();


        priority_queue<int>pq(nums.begin(),nums.end());
        
       long long score=0;

       while(!pq.empty() && k>0){

        double ans=pq.top();
        cout<<ans<<endl;
        pq.pop();

        score+=ans;
        double res=ans/3;



        k--;

        pq.push(ceil(res));

       }

       return score;
        
    }
};