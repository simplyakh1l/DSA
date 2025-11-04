class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& a) {
        int n=a.size();
       
        vector<int>row(n);
        vector<int>col(n);
        for(int i=0;i<n;i++){
            int rmax=0,cmax=0;
            for(int j=0;j<n;j++){
                rmax=max(a[i][j],rmax);
                cmax=max(a[j][i],cmax);
            }
            row[i]=rmax;
            col[i]=cmax;
        }

        
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int rmax=row[i];
                int cmax=col[j];
                int inc=min(rmax,cmax);
                
                if(a[i][j]>=inc)continue;
                else ans+=inc-a[i][j];
            
            }
        }
        return ans;
    }
};