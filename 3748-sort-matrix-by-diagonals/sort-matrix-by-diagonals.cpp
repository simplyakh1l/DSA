class Solution {
public:
    //f=0 asc f=1 desc
    void fix(int x,int y,vector<vector<int> >&mat,char f){
        vector<int>tmp;
        int n=mat.size();
        int i=x,j=y;

        while(i<n && j<n){
            tmp.push_back(mat[i][j]);
            i++;
            j++;
        }
        sort(tmp.begin(),tmp.end());

        int ind=(f=='a')?0:tmp.size()-1;
        i=x,j=y;
        while(i<n && j<n){
            mat[i][j]=tmp[ind];
            if(f=='a')ind++;
            else ind--;
            i++;
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int j=1;j<n;j++){
            fix(0,j,mat,'a');
        }
        for(int i=0;i<n;i++){
            fix(i,0,mat,'d');
        }
        return mat;
    }
};