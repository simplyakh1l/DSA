class Solution {
public:
    int garbageCollection(vector<string>&a, vector<int>& t) {
        int n=a.size();
        vector<int>g(n);
        vector<int>p(n);
        vector<int>m(n);

        for(int i=0;i<n;i++){
            for(auto it:a[i]){
                if(it=='M')m[i]++;
                else if(it=='P')p[i]++;
                else g[i]++;
            }
        }

        int mi=n-1,pi=n-1,gi=n-1;  
        while(mi>=0 && m[mi]==0)mi--;
        while(gi>=0 && g[gi]==0)gi--;
        while(pi>=0 && p[pi]==0)pi--;

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(g[i]+p[i]+m[i]);

            if(i<gi)ans+=t[i];
            if(i<pi)ans+=t[i];
            if(i<mi)ans+=t[i];
        }
        return ans;


        

        
    }
};