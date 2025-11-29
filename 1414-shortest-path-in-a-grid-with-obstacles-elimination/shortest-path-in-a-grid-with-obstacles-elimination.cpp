class Solution {
public:
    int shortestPath(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(m, -1));

        int row[] = {0,0,1,-1};
        int col[] = {1,-1,0,0};

        q.push({0,0,k});
        vis[0][0] = k;

        int lvl = 0;

        while(q.size()){
            int len = q.size();
            while(len--){
                auto tmp = q.front();
                q.pop();

                int cr = tmp[0];
                int cc = tmp[1];
                int rem = tmp[2];

                if(cr == n-1 && cc == m-1) return lvl;

                for(int i=0;i<4;i++){
                    int nr = cr + row[i];
                    int nc = cc + col[i];

                    if(nr>=0 && nc>=0 && nr<n && nc<m){
                        int newRem = rem - mat[nr][nc];

                        if(newRem >= 0 && newRem > vis[nr][nc]){
                            vis[nr][nc] = newRem;
                            q.push({nr, nc, newRem});
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
