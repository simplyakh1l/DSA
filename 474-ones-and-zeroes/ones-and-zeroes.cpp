class Solution {
public:
    int t[101][101][601];
    int sol(vector<int>&z,vector<int> &v,int zl,int vl,int n){
        if(zl==0 && vl==0)return 0;
        if(n==0)return 0;
        if(t[zl][vl][n]!=-1)return t[zl][vl][n];
        if(z[n-1]<=zl && v[n-1]<=vl){
            int inc=1+sol(z,v,zl-z[n-1],vl-v[n-1],n-1);
            int exc=sol(z,v,zl,vl,n-1);
            return t[zl][vl][n]=max(inc,exc);
        }
        else return t[zl][vl][n]=sol(z,v,zl,vl,n-1);
    }
    int findMaxForm(vector<string>& s, int zl, int vl) {
        memset(t,-1,sizeof(t));
        int n=s.size();
        vector<int>z(n);
        vector<int>v(n);

        for(int i=0;i<n;i++){
            int zcnt=0;
            int vcnt=0;
            for(auto it:s[i]){
                if(it=='0')zcnt++;
                else vcnt++;
            }
            z[i]=zcnt;
            v[i]=vcnt;
        }

        int ans=sol(z,v,zl,vl,n);
        return ans;


        
        
    }
};