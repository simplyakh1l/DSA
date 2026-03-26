class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        if(n >= 1e3){
            long long upper = min(n, (long long)1e6 - 1);
            ans += (upper - 1e3 + 1) * 1;
        }

        if(n >= 1e6){
            long long upper = min(n, (long long)1e9 - 1);
            ans += (upper - 1e6 + 1) * 2;
        }

        if(n >= 1e9){
            long long upper = min(n, (long long)1e12 - 1);
            ans += (upper - 1e9 + 1) * 3;
        }

        
        if(n >= 1e12){
    long long upper = min(n, (long long)1e15 - 1);
    ans += (upper - 1e12 + 1) * 4;
}

if(n == 1e15){
    ans += 5;
}

        return ans;
    }
};