class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>>pq;

        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
       
       string ans="";

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            if(ans.size()>=2 && ans.back()==it.second && ans[ans.size()-2]==it.second){

                if(pq.empty()){
                    break;
                }
                auto it2=pq.top();
                pq.pop();

                ans+=it2.second;
                it2.first--;

                if(it2.first>0){
                    pq.push({it2.first,it2.second});
                }

                pq.push({it.first,it.second});
            } 

            else{
                ans+=it.second;
                it.first--;

                if(it.first>0){
                    pq.push({it.first,it.second});
                }
            }
        }

        return ans;
        
    }
};