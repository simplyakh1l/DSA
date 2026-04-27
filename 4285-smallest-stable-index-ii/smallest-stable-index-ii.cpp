class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n=a.size();
        vector<int>pmax(n);
        vector<int>smin(n);

        pmax[0]=a[0];
        smin[n-1]=a[n-1];

        for(int i=1;i<n;i++)pmax[i]=max(pmax[i-1],a[i]);
        for(int i=n-2;i>=0;i--)smin[i]=min(smin[i+1],a[i]);

        for(int i=0;i<n;i++){
            if(pmax[i]-smin[i]<=k)return i;
        }
        return -1;
        
    }
};