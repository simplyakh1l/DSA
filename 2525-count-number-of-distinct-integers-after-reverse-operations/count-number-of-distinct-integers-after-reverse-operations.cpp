class Solution {
public:
    int countDistinctIntegers(vector<int>& a) {
        int n=a.size();

        unordered_set<int>st;

        for(int i=0;i<n;i++){
            st.insert(a[i]);
            int x=a[i];
            int num=0;
            while(x){
                int ld=x%10;
                num=num*10+ld;
                x/=10;
            }
            st.insert(num);
        }
        return st.size();



        
    }
};