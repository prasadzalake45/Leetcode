class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        sort(skill.begin(),skill.end());

        int i=1;
        int j=skill.size()-2;

        long long mul=skill[0]*skill[skill.size()-1];
        
        int sum2=skill[0]+skill[skill.size()-1];

        while(i<j){
            int sum=sum2-(skill[i]+skill[j]);
            

    

            if(sum==0){
                mul+=(skill[i]*skill[j]);
            }
            else{
                return -1;
            }
            i++;
            j--;


            
        }

        return mul;
        
    }
};