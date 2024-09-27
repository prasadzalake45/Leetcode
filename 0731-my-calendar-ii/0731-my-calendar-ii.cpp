class MyCalendarTwo {
public:

   vector<pair<int,int>>booking;
    vector<pair<int,int>>overlap;
    MyCalendarTwo() {
        
        
    }
    
    
    bool book(int start, int end) {

        for(auto o:overlap){

            if(max(start,o.first)<min(end,o.second)){
                return false;
            }

        }

        for(auto it:booking){

            int overlap_first=max(start,it.first);
            int overlap_end=min(end,it.second);
            if(overlap_first<overlap_end){
                overlap.push_back({overlap_first,overlap_end});
            }

        }

        booking.push_back({start,end});
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */