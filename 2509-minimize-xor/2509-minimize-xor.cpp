class Solution {
public:

   bool isSet(int& x,int bit){
    return x&(1<<bit);

   }

   bool setBit(int& x,int bit){
    return x|=(1<<bit);

   }
   bool unsetBit(int& x,int bit){

    return x&=~(1<<bit);

   }
    int minimizeXor(int num1, int num2) {
        int x=num1;

        int req=__builtin_popcount(num2);

        int cur=__builtin_popcount(x);

        int bit=0;

        
        if(req>cur){
            while(req>cur){
                if(!isSet(x,bit)){
                    setBit(x,bit);
                    cur++;
                }
                bit++;
            }

        }

        if(req<cur){

            while(req<cur){
                if(isSet(x,bit)){
                    unsetBit(x,bit);
                    cur--;

                }
                bit++;
            }

        }

        return x; 

        
        
    }
};