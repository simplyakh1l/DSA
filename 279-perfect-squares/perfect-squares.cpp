class Solution {
public:
    int numSquares(int n) {
        vector<long long>a;
        for(long long i=1;i*i<=n;i++)a.push_back(i*i);
        int tar=n;
        n=a.size();

        int t[n+1][tar+1];

        for(int j=0;j<tar+1;j++)t[0][j]=INT_MAX;
        for(int i=0;i<n+1;i++)t[i][0]=0;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<tar+1;j++){
                if(a[i-1]<=j){
                    long long inc=1+t[i][j-a[i-1]];
                    long long exc=t[i-1][j];
                    t[i][j]=min(inc,exc);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][tar];
        
    }
};