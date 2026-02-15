class AuctionSystem {
public:
    map<pair<int,int> ,int>usr;
    map<int,set< pair<int,int>,greater<pair<int,int> > > >bamt;
    AuctionSystem() {
        
    }
    
    void addBid(int u, int i, int amt) {
        if(usr.find({u,i})==usr.end()){
            usr[{u,i}]=amt;
            bamt[i].insert({amt,u});
        }
        else{
            int oamt=usr[{u,i}];
            usr[{u,i}]=amt;
            bamt[i].erase({oamt,u});
            bamt[i].insert({amt,u});
        }
    }
    
    void updateBid(int u, int i, int namt) {
        int oamt=usr[{u,i}];
        bamt[i].erase({oamt,u});
        bamt[i].insert({namt,u});
        usr[{u,i}]=namt;
    }
    
    void removeBid(int u, int i) {
        int amt=usr[{u,i}];
        usr.erase({u,i});
        bamt[i].erase({amt,u});
        if(bamt[i].size()==0){
            bamt.erase(i);
        }
    }
    
    int getHighestBidder(int i) {
        if(bamt.empty() || bamt.find(i)==bamt.end())return -1;
        return (*(bamt[i].begin())).second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */