class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int n = h.size();
        int res = 0;
        int curr;
        int tp;
        
        for(int i=0; i<n; i++){
            while(!s.empty() && h[s.top()]>=h[i]){
                tp  = s.top();
                s.pop();
                curr = h[tp] * (s.empty()?i:i-s.top()-1);
                res = max(res, curr);
            }
            s.push(i);
        }
        
        while(!s.empty()){
            tp = s.top();
            s.pop();
            curr = h[tp] * (s.empty()?n:n-s.top()-1);
            res = max(res, curr);
        }
        
        return res;
    }
};