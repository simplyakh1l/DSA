class Solution {
public:
    long long minMoves(vector<int>& a) {
        int n=a.size();
        queue<pair<int,int> >q;
        vector<int> vis(n);
        long long t=-1;
        long long sm=0;

        for(int i=0;i<n;i++){
            if(a[i]<0){
                t=a[i];
                q.push({a[i],i});
                vis[i]=1;
            }
            else sm+=a[i];
        }
        if(q.empty())return 0;
        if(abs(t)>sm)return -1;
       
        
 
        int lvl=0;
        long long ans=0;

        while(q.size()){
            int len=q.size();

            while(len--){
                pair<int,int> tmp=q.front();
                q.pop();
                int val=tmp.first;
                int ind=tmp.second;

               
                if(t+val>=0 && lvl!=0){
                    ans+=(abs(t)*lvl);
                    return ans;
                }

                ans+=(val*lvl);
                if(lvl!=0)t+=val;

                int li=(ind-1+n)%n;
                int ri=(ind+1)%n;

                if(vis[li]==0){
                    q.push({a[li],li});
                    vis[li]=1;
                }
                if(vis[ri]==0){
                    q.push({a[ri],ri});
                    vis[ri]=1;
                }
                
            }
            lvl++;
        }
        return ans;
        
    }
};