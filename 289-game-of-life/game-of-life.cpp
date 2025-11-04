class Solution {
public:
    void gameOfLife(vector<vector<int>>& arr) {
        vector<vector<int> >a=arr;
        int n=a.size();
        int m=a[0].size();

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt1=0;
                for(int r=-1;r<=1;r++){
                    for(int c=-1;c<=1;c++){
                        int nr=i+r;
                        int nc=j+c;

                        if(nr>=0 && nc>=0 && nr<n && nc<m){
                            if(a[nr][nc]==1 && !(r==0 && c==0))cnt1++;
                        } 
                    }
                }
                if(a[i][j]==1 && cnt1<2)arr[i][j]=0;
                else if(a[i][j]==1 && (cnt1==3 || cnt1==2))arr[i][j]=1;
                else if(a[i][j]==1 && cnt1>3)arr[i][j]=0;
                else if(a[i][j]==0 && cnt1==3)arr[i][j]=1;
            }
        }
    }
};