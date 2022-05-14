// { Driver Code Starts
// C++ program to search an element in an array
// where difference between all elements is 1
#include<bits/stdc++.h>
using namespace std;

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k);


// Driver program to test above function
int main()
{
	int t,n,k,x;
	cin>>t;
	while(t--)
    {

        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>x;
        cout<<search(arr, n, x, k)<<endl;

    }
return 0;
}

// } Driver Code Ends


// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // Complete the function
    if(n == 1 and arr[0] == x) return 0;
    
    int ans = INT_MAX;
    if(arr[0] == x and abs(arr[0] - arr[1]) <= k){
        ans = min(ans, 0);
    }
    
    for(int i=1; i<n; i++){
        if(arr[i] == x and abs(arr[i] - arr[i-1]) <= k){
            ans = min(ans, i);
        }    
    }
    return ans == INT_MAX ? -1 : ans;
}    	