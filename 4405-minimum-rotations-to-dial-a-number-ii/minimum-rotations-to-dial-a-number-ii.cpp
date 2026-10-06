class Solution {
public:
    int gd(char c1,char c2){
        int diff=abs(c1-c2);
        return min(diff,9-diff+1);
    }
    int sol(string s,int n){
        int ans=0;
        for(int i=1;i<n;i++){
            int diff=abs(s[i]-s[i-1]);
            ans+=min(diff,9-diff+1);
        }
        return ans;
    }
    int minRotations(int n, string s) {
        s="0"+s;
        n=s.size();
        char c=s[n-1];
        int d=INT_MAX;
        int pos=-1;
        int ans=sol(s,n);
        for(int i=n-2;i>=1;i--){
            int od=gd(s[i],s[i-1]);
            int nd=gd(c,s[i-1]);

            if(nd-od<=d){
                d=nd-od;
                pos=i;
            }
        }
        if(pos!=-1)reverse(s.begin()+pos,s.end());

        ans=min(ans,sol(s,n));
        return ans;
    }
};