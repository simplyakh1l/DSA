class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        int n=a.size();
        priority_queue<int>pq;

        for(auto it:a)pq.push(it);


        while(pq.size()>1){
            int h1=pq.top();
            pq.pop();
            int h2=pq.top();
            pq.pop();

            if(h1==h2)continue;
            else{
                h1-=h2;
                pq.push(h1);
            }
        }

        if(pq.empty())return 0;
        else return pq.top();
        
    }
};