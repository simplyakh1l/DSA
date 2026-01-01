class Solution {
public:
    int coinChange(vector<int>& a, int amt) {
        int n=a.size();
        long long t[n+1][amt+1];

        for(int j=0;j<amt+1;j++)t[0][j]=INT_MAX;
        for(int i=0;i<n+1;i++)t[i][0]=0;

        
        for(long long i=1;i<n+1;i++){
            for(long long j=1;j<amt+1;j++){
                if(a[i-1]<=j){
                    long long inc=1+t[i][j-a[i-1]];
                    long long exc=t[i-1][j];
                    t[i][j]=min(inc,exc);
                }
                else t[i][j]=t[i-1][j];
            }
        }
        if(t[n][amt]>=INT_MAX)return -1;
        return t[n][amt];
    }
};