class Solution {
public:
    double dis(int x1,int y1,int x2,int y2){
        return sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
    }
    int sol(int x,int y,int r,vector<vector<int> >&a){
        int ans=0;

        for(auto it:a){
            double d=dis(x,y,it[0],it[1]);
            if(d<=r)ans++;
        }
        return ans;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& q) {
        vector<int>ans;

        for(auto it:q){
            int tmp=sol(it[0],it[1],it[2],points);
            ans.push_back(tmp);
        }
        return ans;
    }
};