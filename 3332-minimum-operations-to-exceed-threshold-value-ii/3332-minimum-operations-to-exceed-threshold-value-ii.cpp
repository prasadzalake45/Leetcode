class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long,vector<long long>,greater<long long>>p;

        for(int i=0;i<nums.size();i++){
            p.push(nums[i]);
        }
        int cnt=0;

        while(p.top()<k && !p.empty()){
            long long a=p.top();
            p.pop();
            long long b=p.top();
            p.pop();

            long long c=a*2+b;
            p.push(c);

            cnt++;


        }
        return cnt;

        
    }
};