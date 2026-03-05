class Solution {
public:
    vector<int>dp;
    int sol(vector<int>&a,int ind,int i){
        if(i==ind)return a[ind];
        if(i<ind)return 0;
        if(dp[i]!=-1)return dp[i];
        int p=a[i]+sol(a,ind,i-2);
        int np=sol(a,ind,i-1);
        return dp[i]=max(p,np);
    }
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        dp.assign(n,-1);
        int a1=sol(a,0,n-2);
        dp.assign(n,-1);
        int a2=sol(a,1,n-1);
        return max(a1,a2);

        
    }
};