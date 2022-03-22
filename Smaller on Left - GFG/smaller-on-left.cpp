// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    vector<int> ans;
    ans.push_back(-1);
    
    set<int> st;
    st.insert(arr[0]);
    
    for(int i=1; i<n; i++){
        st.insert(arr[i]);
        auto it = st.lower_bound(arr[i]);
       
        
        while(it!=st.begin()){
            if(*it<arr[i]) break;
            it--;
        }
        
        if(*it<arr[i]) ans.push_back(*it);
        else ans.push_back(-1);
    }
    return ans;
}