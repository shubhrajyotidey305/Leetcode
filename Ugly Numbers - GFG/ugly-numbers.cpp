// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    if(n==1 or n==2 or n==3 or n==4 or n==5)
	        return n;
	       
	    set<ull> st;
	    st.insert(1);
	    n--;
	    
	    while(n){
	        auto it = st.begin();
	        ull x = *it;
	        st.erase(it);
	        
	        st.insert(x*2);
	        st.insert(x*3);
	        st.insert(x*5);
	        
	        n--;
	    }
	    return *st.begin();
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends