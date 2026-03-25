class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int n=a.size();
        set<int>od;
      
        for(auto it:a){
            if(it%2==1)od.insert(it);
        }

        int ef=1;
        for(auto it:a){
            if(it%2==0)continue;
            else{
                if(od.empty() || od.lower_bound(it) == od.begin()){
                    ef=0;
                    break;
                }
            }
        }
        int of=1;
        for(auto it:a){
            if(it%2==1)continue;
            else{
                if(od.empty() || od.lower_bound(it) == od.begin()){
                    of=0;
                    break;
                }
            }
        }

        if(of || ef)return true;
        else return false;


        
    }
};