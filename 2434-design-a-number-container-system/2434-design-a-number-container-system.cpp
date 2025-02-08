class NumberContainers {
public:

    unordered_map<int,int>mp;
    unordered_map<int,set<int>>mp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if(mp.count(index)){
            int old=mp[index];
            mp2[old].erase(index);
            if(mp2[old].empty()){
                mp2.erase(old);
            }
        }
        

        mp[index]=number;
        mp2[number].insert(index);
        
    }
    
    int find(int number) {
 
        if(mp2.count(number) && !mp2[number].empty()){
            return *mp2[number].begin();
        }

      

       return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */