class Solution {
public:
    int change(int amt, vector<int>& a) {
        int n=a.size();
        vector<vector<unsigned long long> >t(n+1,vector<unsigned long long>(amt+1));

        for(int j=0;j<amt+1;j++)t[0][j]=0;
        for(int i=0;i<n+1;i++)t[i][0]=1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<amt+1;j++){
                if(a[i-1]<=j){
                    unsigned long long inc=t[i][j-a[i-1]];
                    unsigned long long exc=t[i-1][j];
                    t[i][j]=inc+exc;
                }
                else{
                    unsigned long long exc=t[i-1][j];
                    t[i][j]=exc;
                }
            }
        }
        return t[n][amt];
        
    }
};