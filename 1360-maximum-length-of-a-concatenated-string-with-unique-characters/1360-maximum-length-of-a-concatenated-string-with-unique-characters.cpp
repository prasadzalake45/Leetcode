class Solution {
public:
    bool hasDuplicate(string& s1,string& s2){
        int vec[26]={0};

        for(char ch:s1){
            if(vec[ch-'a']>0){
                return true;
            }
            vec[ch-'a']++;


        }

        for(char ch:s2){
            if(vec[ch-'a']>0){
                return true;
            }
        }


        return false;
    }

    int rec(int i,vector<string>& arr,string temp,int n)
    {

        if(i>=n){
            return temp.size();
        }

        int include=0;
        int exclude=0;

        if(hasDuplicate(arr[i],temp)){
            exclude=rec(i+1,arr,temp,n);

        }
        else{
            include=rec(i+1,arr,temp+arr[i],n);

            exclude=rec(i+1,arr,temp,n);


        }


        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {

       string temp="";
       int n=arr.size();
       int i=0;


       return rec( i,arr,temp,n);
        
        
    }
};