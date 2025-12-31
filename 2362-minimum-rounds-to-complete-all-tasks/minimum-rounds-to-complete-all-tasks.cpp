class Solution {
public:
    int minimumRounds(vector<int>& a) {
        unordered_map<int,int>mpp;
        for(auto it:a)mpp[it]++;

        int cnt=0;
        for(auto it:mpp){
            if(it.second==1)return -1;
            if(it.second%3==0)cnt+=(it.second/3);
            else if(it.second%3==1){
                cnt+=((it.second/3)+1);
            }
            else{
                cnt+=((it.second/3)+1);
            }
        }
        return cnt;
    }
};