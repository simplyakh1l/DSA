class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n=a.size();
        int tsm=accumulate(a.begin(),a.end(),0);
        int tar=(tsm+1)/2;

        int t[n+1][tar+1];
        for(int j=0;j<tar+1;j++)t[0][j]=0;
        for(int i=0;i<n+1;i++)t[i][0]=1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<tar+1;j++){
                if(a[i-1]<=j){
                    bool inc=t[i-1][j-a[i-1]];
                    bool exc=t[i-1][j];
                    t[i][j]=( inc || exc);
                }
                else t[i][j]=t[i-1][j];
            }
        }

        int s1,s2;
        for(int j=tar;j>=0;j--){
            if(t[n][j]){
                s1=j;
                s2=tsm-j;
                break;
            }
        }
        return abs(s1-s2);


        
    }
};