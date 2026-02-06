class RideSharingSystem {
public:
    queue<int>r; 
    queue<int>d; 
    set<int>st;
    RideSharingSystem() {
        
    }
    
    void addRider(int rid) {
        r.push(rid);
        st.insert(rid);
    }
    
    void addDriver(int did) {
        d.push(did);
    }
    
    vector<int> matchDriverWithRider() { 
        while(r.size() && st.find(r.front())==st.end()){
            r.pop();
        }
        if(r.size() && d.size()){
            int rid=r.front();
            int did=d.front();
            r.pop();
            d.pop();
            return {did,rid};
            st.erase(rid);
        }
        return {-1,-1};
    }
    void cancelRider(int rid) {
        if(st.find(rid)!=st.end()){
            st.erase(rid);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */