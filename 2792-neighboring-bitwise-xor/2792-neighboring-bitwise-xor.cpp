class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR=0;


        for(int i=0;i<derived.size();i++){
            XOR=XOR^derived[i];
        }

        return XOR==0;
    }
};