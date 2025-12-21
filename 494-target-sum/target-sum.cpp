class Solution {
public:
    int findTargetSumWays(vector<int>& a, int target) {
        int n=a.size();
        int tsm=accumulate(a.begin(),a.end(),0);

        if((tsm-target)%2==1 || target>tsm)return 0;
        int tar=(tsm-target)/2;


        int t[n+1][tar+1];
        for(int j=0;j<tar+1;j++)t[0][j]=0;
        int zcnt=0;
        for(int i=0;i<n;i++){
            t[i][0]=pow(2,zcnt);
            if(a[i]==0)zcnt++;
        }
        t[n][0]=pow(2,zcnt);

        for(int i=1;i<n+1;i++){
            for(int j=1;j<tar+1;j++){
                if(a[i-1]<=j){
                    int inc=t[i-1][j-a[i-1]];
                    int exc=t[i-1][j];
                    t[i][j]=inc+exc;
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][tar];
        
    }
};