class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        int p2=0,p1=1;
        int ans;
        for(int i=2;i<=n;i++){
            ans=p1+p2;
            p2=p1;
            p1=ans;
        }
        return ans;
        
    }
};