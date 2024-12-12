class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int>pq;

        for(auto it:gifts){
            pq.push(it);
        }

        for(int i=0;i<k;i++){
            int ans=pq.top();
            pq.pop();
            int sqr=floor((double)pow(ans,0.5));
            cout<<sqr<<" ";
            pq.push(sqr);
        }

        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            cout<<pq.top()<<" ";
            pq.pop();
        }

        return sum;
        
    }
};