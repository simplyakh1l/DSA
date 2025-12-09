class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& a, int k) {
        vector<int>tmp;
        int n=a.size();
        for(int i=0;i<n-1;i++){
            int ind=i;
            for(int j=i+1;j<n;j++){
                if(a[j][k]>a[ind][k]){
                    ind=j;
                }
            }
            if(ind!=i)swap(a[i],a[ind]);
        }
        return a;
        
    }
};