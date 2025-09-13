class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

      int n=nums.size();

      int cand1;
      int cand2;
      int cnt1=0;
      int cnt2=0;

      vector<int>answer;

      for(auto num:nums){
        if(num==cand1){
          cnt1++;

        }
        else if(num==cand2){
          cnt2++;

        }
        else if(cnt1==0){
          cand1=num;
          cnt1++;
        }
        else if(cnt2==0){
          cand2=num;
          cnt2++;
        }
        else{
          cnt1--;
          cnt2--;
        }
      }

      cout<<cand1<<" "<<cand2<<endl;
       cnt1=0;
       cnt2=0;
      for(auto num:nums){
        if(num==cand1){
          cnt1++;
        }
        if(num==cand2){
          cnt2++;
        }
      }


      int ans=n/3;

      if(cnt1>ans){
        answer.push_back(cand1);

      }
      if(cnt2>ans){
        answer.push_back(cand2);

      }
       
       return answer;


        
    }
};