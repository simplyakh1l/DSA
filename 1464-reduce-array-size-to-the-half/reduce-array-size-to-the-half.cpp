class Solution {
public:
    int minSetSize(vector<int>& a) {
        int n=a.size();

        map<int,int>mpp;
        priority_queue<int>pq;

        for(int i=0;i<n;i++){
            mpp[a[i]]++;
        }

        for(auto it:mpp){
            pq.push(it.second);
        }

        int sm=0;
        int cnt=0;

        while(sm<(n/2)){
            int freq=pq.top();
            pq.pop();

            sm+=freq;
            cnt++;
        }
        return cnt;

        
        
    }
};