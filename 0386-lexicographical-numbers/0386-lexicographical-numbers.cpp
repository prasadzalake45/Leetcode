class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<int>vec;
        for(int i=1;i<=n;i++){
            vec.push_back(i);
        }
        

        sort(vec.begin(),vec.end(),[](int a,int b){
            string strA=to_string(a);
            string strB=to_string(b);
            return strA<strB;
        });
        return vec;
    }
};