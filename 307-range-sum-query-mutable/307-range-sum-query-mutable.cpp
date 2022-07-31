class NumArray {
public:
    vector<int> v;
    vector<int> st;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        v = nums;
        st = vector<int>(4*n);
        construct(0, n-1, 0);
    }
    
    void update(int index, int val) {
        int diff = val - v[index];
        solveUpdate(0, v.size()-1, 0, index, diff);
        v[index] = val;
    }
    
    void solveUpdate(int ss, int se, int si, int i, int diff) {
        if(ss > i or se < i){
            return;
        }
        
        st[si] += diff;
        if(se > ss) {
            int mid = (ss + se) / 2;
            solveUpdate(ss, mid, 2*si + 1, i, diff);
            solveUpdate(mid+1, se, 2*si + 2, i, diff);
        }
        
    }
    
    int sumRange(int left, int right) {
        return getSum(left, right, 0, v.size()-1, 0);
    }
    
    int getSum(int qs, int qe, int ss, int se, int si) {
        if(qs > se or qe < ss) {
            return 0;
        } else if(ss >= qs and se <= qe) {
            return st[si];
        } else {
            int mid = (ss + se) / 2;
            return getSum(qs, qe, ss, mid, 2*si+1) + getSum(qs, qe, mid+1, se, 2*si+2);
        }
    }
    
    int construct(int ss, int se, int si) {
        if(ss == se) {
            st[si] = v[ss];
            return v[ss];
        }
        
        int mid = (ss + se) / 2;
        return st[si] = construct(ss, mid, 2*si + 1) + construct(mid+1, se, 2*si+2);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */