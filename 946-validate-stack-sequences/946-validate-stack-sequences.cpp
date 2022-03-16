class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int> st;
        int n = pu.size();
        
        int i = 0, j = 0;
        
        while(j<n){         
            if(!st.empty() and st.top() == po[j]){
                st.pop();
                j++;
            }
            else if(i!=n){
                st.push(pu[i++]); 
            }
            else return false;
        }
        return true;
        
    }
};