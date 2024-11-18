class Solution {
public:  

    bool vowel(char ch){

        return ch=='a' ||ch=='e' ||ch=='i'  ||ch=='o' ||ch=='u' || ch=='A'||
        ch=='E'|| ch=='I' ||ch=='O'|| ch=='U';

    }
    string reverseVowels(string s) {

        int start=0;
        int end=s.size()-1;


        while(start<=end){
            if(vowel(s[start])==true && vowel(s[end])==true){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(vowel(s[start])==true && vowel(s[end])==false){
                end--;
            }
            else{
                start++;
            }
        }

        return s;
        
    }
};