class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n=boxes.size();

        vector<int>ans;

        vector<int>ones;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                ones.push_back(i);
            }
        }

        for(int i=0;i<n;i++){
           int cnt=0;
           for(int j=0;j<ones.size();j++){
            cnt+=abs(i-ones[j]);

           }

           ans.push_back(cnt);

        }

        return ans;
        
    }
};