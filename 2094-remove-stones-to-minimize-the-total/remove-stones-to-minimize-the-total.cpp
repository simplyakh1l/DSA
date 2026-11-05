class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        int sm=0;
        priority_queue<int>pq;
        for(auto it:a){
            sm+=it;
            pq.push(it);
        }

        while(k--){
            int tp=pq.top();
            pq.pop();
            sm-=tp;

            pq.push((tp+1)/2);
            sm+=(tp+1)/2;
        }
        return sm;

        
    }
};