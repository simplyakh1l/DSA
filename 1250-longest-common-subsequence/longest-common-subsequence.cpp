class Solution {
public:
    int t[1001][1001];
    int sol(string &s1,string &s2,int n,int m){
        if(n==0 || m==0)return t[n][m]=0;
        if(t[n][m]!=-1)return t[n][m];
        if(s1[n-1]==s2[m-1]){
            return t[n][m]=1+sol(s1,s2,n-1,m-1);
        }
        else{
            int py=sol(s1,s2,n-1,m);
            int px=sol(s1,s2,n,m-1);
            int pn=sol(s1,s2,n-1,m-1);
            return t[n][m]=max({py,px,pn});
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        memset(t,-1,sizeof(t));
        int n=s1.size();
        int m=s2.size();
        int ans=sol(s1,s2,n,m);
        return ans;
    }
};