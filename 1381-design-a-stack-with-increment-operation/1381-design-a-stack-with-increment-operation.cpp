class CustomStack {
public:
    vector<int> st;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(st.size() < n) {
            st.push_back(x);
        }
    }
    
    int pop() {
        if(st.size() == 0) {
            return -1;
        }
        int x = st.back();
        st.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        int i=0;
        while(k-- && i<st.size()){            
            st[i] += val;
            i++;
        }        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */