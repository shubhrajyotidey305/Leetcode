class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        
        set<string> st;    
        
        for(int i = 0;i<n-k+1;i++){ 
            st.insert(s.substr(i,k));
        }        
        
        if(st.size() == pow(2,k) ){  
            return true;
        }
        else{
            return false;
        }
    }
};