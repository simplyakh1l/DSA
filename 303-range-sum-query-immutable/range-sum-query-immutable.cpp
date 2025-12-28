class NumArray {
public:
    vector<long long>psm;
    NumArray(vector<int>& a) {
        int n=a.size();
        psm.resize(n);
        
        psm[0]=a[0];
        for(int i=1;i<n;i++)psm[i]=psm[i-1]+a[i];
    }
    
    int sumRange(int l, int r) {
        return psm[r]-((l>0)?psm[l-1]:0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */