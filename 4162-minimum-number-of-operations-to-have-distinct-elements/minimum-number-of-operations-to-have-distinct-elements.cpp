class Solution {
public:
    int minOperations(vector<int>& a) {
        int n=a.size();
        unordered_set<int>st;
        
        int i=n-1;

        while(i>=0){
            if(st.find(a[i])!=st.end())break;
            st.insert(a[i]);
            i--;
        }
        return ceil(((i+1)*1.0)/3);



    }
};