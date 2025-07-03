class Solution {
public:
    char kthCharacter(int k) {

      string word="a";



      

      while(word.size()<=k){


        int ans=word.size();
        string a="";

        for(int i=0;i<ans;i++){
          a+=word[i]+1;


        }

        word=word+a;
        
     
         


        }
      cout<<word<<endl;

      return word[k-1];
        
    }
};