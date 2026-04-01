class EventManager {
public:
    map<int,int>m1; //eid->pr
    map<int,set<int> ,greater<int> >m2; //pr->eid
    EventManager(vector<vector<int>>& events) {
        for(auto it:events){ 
            m1[it[0]]=it[1];
            m2[it[1]].insert(it[0]);
        }
    }
    
    void updatePriority(int eid, int np) {
        int op=m1[eid];
        m2[op].erase(eid);
        if(m2[op].empty())m2.erase(op);

        m1[eid]=np;
        m2[np].insert(eid);
        
    }
    
    int pollHighest() {
        if(m2.empty())return -1;
        auto pr=m2.begin()->first;
        auto eid=*(m2.begin()->second).begin();

        m2[pr].erase(eid);
        if(m2[pr].empty())m2.erase(pr);

        m1.erase(eid);
        return eid;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */