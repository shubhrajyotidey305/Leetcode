// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


long long int calculate(int arr[], int n)
{
    // Complete the function
    sort(arr, arr+n);
    
    int ans = 0;
    for(int i=0; i<n-1; i++){
        int cnt =  1;
        while(i<n and arr[i] == arr[i+1]){
            cnt++;
            i++;
        }
        ans += cnt * (cnt - 1) / 2;
    }
    return ans;
}
