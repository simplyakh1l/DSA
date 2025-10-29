class Solution {
public: 
    void bfs(int i,int j,vector<vector<int> >&mat,vector<vector<int> >&vis,int &f){
        int n=mat.size();
        int m=mat[0].size();

        queue<pair<int,int> >q;
        q.push({i,j});
        vis[i][j]=1;

        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};


        while(q.size()){
            pair<int,int>tmp=q.front();
            q.pop();
            int cr=tmp.first;
            int cc=tmp.second;

            if(cr==0 || cr==n-1 || cc==0 || cc==m-1)f=0;

            for(int i=0;i<4;i++){
                int nr=cr+row[i];
                int nc=cc+col[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]==0 && vis[nr][nc]==0){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int> >vis(n,vector<int>(m));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0 && vis[i][j]==0){
                    int f=1;
                    bfs(i,j,mat,vis,f);
                    if(f)ans++;
                }
            }
        }
        return ans;
    }
};