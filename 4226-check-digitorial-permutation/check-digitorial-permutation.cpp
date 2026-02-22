class Solution {
public:
    long long sol(int n){
        if(n==0)return 1;
        long long x=1;
        for(int i=1;i<=n;i++)x*=i;
        return x;
    }
    bool isDigitorialPermutation(int n) {
        long long sm=0;
        long long x=n;
        while(x>0){
            int ld=x%10;
            sm+=sol(ld);
            x/=10;
        }
        string a=to_string(sm);
        string b=to_string(n);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;

        
    }
};