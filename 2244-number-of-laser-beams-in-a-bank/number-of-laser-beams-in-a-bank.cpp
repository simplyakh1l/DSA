class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();

        int ans=0;
        int pl=-1;

        for(auto it:bank){
            int cnt=0;
            for(auto j : it){
                if(j=='1')cnt++;
            }
            if(pl==-1){
                pl=cnt;
                continue;
            }
            ans+=(pl*cnt);
            if(cnt!=0)pl=cnt;
        }
        return ans;
        
    }
};