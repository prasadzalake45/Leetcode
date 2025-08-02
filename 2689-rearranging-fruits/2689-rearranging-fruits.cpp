class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

      int n1=basket1.size();
      int n2=basket2.size();

      unordered_map<int,int>mp1;
      int global_min=INT_MAX;



      for(auto it:basket1){

        mp1[it]++;
        global_min=min(global_min,it);

      }

      for(auto it:basket2){
        mp1[it]--;

        if(mp1[it]==0){
          mp1.erase(it);
        }
        global_min=min(global_min,it);

      }



      vector<int>ex;
      for(auto &[val,freq]:mp1){

        if(freq%2!=0){
          return -1;
        }
         
        for(int i=0;i<abs(freq)/2;i++){

          ex.push_back(val);

        }

      

      



      }

      sort(ex.begin(),ex.end());

      long long cost=0;


      for(int i=0;i<ex.size()/2;i++){
        cost+=min(ex[i],2*global_min);
      }

   

      return cost;
      


        
    }
};